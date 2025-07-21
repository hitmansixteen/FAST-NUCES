# Umamah Hussain 21L-1858
# Laraib Akhtar 21L-5294
# Shaheer Ahmad 21L-5193


import tkinter as tk
from tkinter import filedialog
import numpy as np
from PIL import Image, ImageTk
import cv2
import math

class HoughTransformApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Hough Transform GUI")

        self.canvas = tk.Canvas(self.root, width=500, height=500, bg='white')
        self.canvas.pack(side=tk.LEFT)
        self.canvas.bind("<Button-1>", self.place_dot)

        self.control_frame = tk.Frame(self.root)
        self.control_frame.pack(side=tk.RIGHT, fill=tk.BOTH)

        tk.Label(self.control_frame, text="Rho:").pack(pady=5)
        self.rho_entry = tk.Entry(self.control_frame)
        self.rho_entry.pack(pady=5)
        self.rho_entry.insert(0, "9") 

        tk.Label(self.control_frame, text="Theta (radians):").pack(pady=5)
        self.theta_entry = tk.Entry(self.control_frame)
        self.theta_entry.pack(pady=5)
        self.theta_entry.insert(0, "0.264")  

        tk.Label(self.control_frame, text="Threshold:").pack(pady=5)
        self.threshold_entry = tk.Entry(self.control_frame)
        self.threshold_entry.pack(pady=5)
        self.threshold_entry.insert(0, "4")  

        self.upload_btn = tk.Button(self.control_frame, text="Upload Image", command=self.upload_image)
        self.upload_btn.pack(pady=10)

        self.hough_btn = tk.Button(self.control_frame, text="Apply Hough Transform", command=self.apply_hough)
        self.hough_btn.pack(pady=10)

        self.sample_btn = tk.Button(self.control_frame, text="Place Sample Dots", command=self.place_sample_dots)
        self.sample_btn.pack(pady=10)

        self.clear_btn = tk.Button(self.control_frame, text="Clear Canvas", command=self.clear_canvas)
        self.clear_btn.pack(pady=10)

        
        tk.Label(self.control_frame, text="Canny Lower Threshold").pack(pady=5)
        self.canny_lower_slider = tk.Scale(self.control_frame, from_=0, to=255, orient=tk.HORIZONTAL, command=self.apply_canny)
        self.canny_lower_slider.set(50)
        self.canny_lower_slider.pack(pady=5)

        tk.Label(self.control_frame, text="Canny Upper Threshold").pack(pady=5)
        self.canny_upper_slider = tk.Scale(self.control_frame, from_=0, to=255, orient=tk.HORIZONTAL, command=self.apply_canny)
        self.canny_upper_slider.set(100)
        self.canny_upper_slider.pack(pady=5)

        self.dots = []
        self.image = None

    def place_dot(self, event):
        if self.image is None:
            x, y = event.x, event.y
            self.canvas.create_oval(x-3, y-3, x+3, y+3, fill='black')
            self.dots.append((x, y))
            print(f"Placed dot at: ({x}, {y})")

    def place_sample_dots(self):
        self.clear_canvas()
        side_length = 200
        start_x, start_y = 100, 100
        step = side_length // 6

        for i in range(7):
            self.canvas.create_oval(start_x + i*step - 3, start_y - 3, start_x + i*step + 3, start_y + 3, fill='black')
            self.dots.append((start_x + i*step, start_y))
            self.canvas.create_oval(start_x + side_length - 3, start_y + i*step - 3, start_x + side_length + 3, start_y + i*step + 3, fill='black')
            self.dots.append((start_x + side_length, start_y + i*step))
            self.canvas.create_oval(start_x + i*step - 3, start_y + side_length - 3, start_x + i*step + 3, start_y + side_length + 3, fill='black')
            self.dots.append((start_x + i*step, start_y + side_length))
            self.canvas.create_oval(start_x - 3, start_y + i*step - 3, start_x + 3, start_y + i*step + 3, fill='black')
            self.dots.append((start_x, start_y + i*step))

        print("Placed 28 sample dots in a square.")

    def clear_canvas(self):
        self.canvas.delete("all")
        self.dots = []
        self.image = None 
        self.edge_image = None 

    def upload_image(self):
        file_path = filedialog.askopenfilename()
        if file_path:
            self.image = cv2.imread(file_path, cv2.IMREAD_GRAYSCALE)
            self.image = cv2.resize(self.image, (500, 500))
            self.apply_canny()

    def apply_canny(self, _=None):
        if self.image is not None:
            lower_thresh = self.canny_lower_slider.get()
            upper_thresh = self.canny_upper_slider.get()
            self.edge_image = cv2.Canny(self.image, lower_thresh, upper_thresh)
            self.display_image(self.edge_image)

    def display_image(self, image):
        img_pil = Image.fromarray(image)
        img_tk = ImageTk.PhotoImage(image=img_pil)
        self.canvas.create_image(0, 0, anchor=tk.NW, image=img_tk)
        self.canvas.image = img_tk  

    def apply_hough(self):
        if self.dots:
            self.apply_hough_to_dots()
        elif self.image is not None:
            edge_points = np.argwhere(self.edge_image > 0)
            self.apply_hough_to_dots(edge_points)

    def apply_hough_to_dots(self, points=None):
        if points is None:
            points = self.dots
        if len(points) == 0:
            print("No points to apply Hough Transform.")
            return

        self.canvas.delete("hough_line")

        try:
            self.rho = int(self.rho_entry.get())
            self.theta = float(self.theta_entry.get())
            self.threshold = int(self.threshold_entry.get())
        except ValueError:
            print("Invalid input. Please enter valid numbers.")
            return

        image_height = 500
        image_width = 500
        diagonal = int(math.sqrt(image_width**2 + image_height**2))
        theta_angles = np.arange(0, np.pi, self.theta)
        rho_values = np.arange(-diagonal, diagonal, self.rho)
        accumulator = np.zeros((len(rho_values), len(theta_angles)))

        for x, y in points:
            for t_idx, theta in enumerate(theta_angles):
                rho = x * np.cos(theta) + y * np.sin(theta)
                rho_idx = np.argmin(np.abs(rho_values - rho))
                accumulator[rho_idx, t_idx] += 1

        rho_idxs, theta_idxs = np.where(accumulator > self.threshold)
        for rho_idx, theta_idx in zip(rho_idxs, theta_idxs):
            rho = rho_values[rho_idx]
            theta = theta_angles[theta_idx]
            cos_theta = np.cos(theta)
            sin_theta = np.sin(theta)
            if sin_theta != 0:
                x1 = 0
                y1 = int(rho / sin_theta)
                x2 = image_width
                y2 = int((rho - x2 * cos_theta) / sin_theta)
            else:
                x1 = x2 = int(rho / cos_theta)
                y1 = 0
                y2 = image_height

            self.canvas.create_line(x1, y1, x2, y2, fill='red', width=1, tags="hough_line")

        print(f"Hough lines drawn: {len(rho_idxs)} lines")

if __name__ == "__main__":
    root = tk.Tk()
    app = HoughTransformApp(root)
    root.mainloop()
