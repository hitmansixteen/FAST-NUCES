import tkinter as tk
from tkinter import filedialog, Label, Radiobutton, IntVar, Spinbox, Frame
from PIL import Image, ImageTk
import numpy as np
import os



def image_to_matrix(image_path):
    image = Image.open(image_path)
    image = image.convert('RGB')
    image_matrix = np.array(image)
    return image_matrix

def extend_image(image_matrix, k):
    original_height, original_width, channels = image_matrix.shape
    new_height = (original_height - 1) * k + 1
    new_width = (original_width - 1) * k + 1

    new_image_matrix = np.zeros((new_height, new_width, channels), dtype=np.uint16)

    for i in range(original_height):
        for j in range(original_width):
            new_image_matrix[i * k, j * k] = image_matrix[i, j]
    return new_image_matrix

def zero_order_hold(image_matrix, k):
    height, width, channels = image_matrix.shape
    buffer = np.copy(image_matrix)

    for i in range(height):
        for j in range(width):
            if np.all(buffer[i, j] == 0):
                nearest_i = (i // k) * k
                nearest_j = (j // k) * k
                buffer[i, j] = image_matrix[nearest_i, nearest_j]
    return buffer

def first_order_hold(image_matrix, k):
    height, width, channels = image_matrix.shape
    buffer = np.copy(image_matrix)

    for i in range(height):
        for j in range(width):
            if np.all(buffer[i, j] == 0):
                if i % k == 0:
                    prev_col = ((j // k) * k)
                    next_col = min(((j // k) + 1) * k, width - 1)

                    buffer[i, j] = (image_matrix[i, prev_col] + image_matrix[i, next_col]) // 2
                elif j % k == 0:
                    prev_row = ((i // k) * k)
                    next_row = min(((i // k) + 1) * k, height - 1)

                    buffer[i, j] = (image_matrix[prev_row, j] + image_matrix[next_row, j]) // 2
                else:
                    prev_row = ((i // k) * k)
                    next_row = min(((i // k) + 1) * k, height - 1)
                    prev_col = ((j // k) * k)
                    next_col = min(((j // k) + 1) * k, width - 1)

                    buffer[i, j] = (image_matrix[prev_row, prev_col] + image_matrix[prev_row, next_col] +
                                    image_matrix[next_row, prev_col] + image_matrix[next_row, next_col]) // 4
    return buffer

def linear_interpolation(image_matrix, k):
    height, width, channels = image_matrix.shape
    buffer = np.copy(image_matrix)

    for i in range(height):
        for j in range(width):
            if np.all(buffer[i, j] == 0):
                i0 = (i // k) * k
                j0 = (j // k) * k
                i1 = min(i0 + k, height - 1)
                j1 = min(j0 + k, width - 1)

                wi = (i - i0) / (i1 - i0) if i1 != i0 else 0
                wj = (j - j0) / (j1 - j0) if j1 != j0 else 0

                for c in range(channels):
                    buffer[i, j, c] = int((1 - wi) * (1 - wj) * image_matrix[i0, j0, c] +
                                          wi * (1 - wj) * image_matrix[i1, j0, c] +
                                          (1 - wi) * wj * image_matrix[i0, j1, c] +
                                          wi * wj * image_matrix[i1, j1, c])
    return buffer

def matrix_to_image(image_matrix, image_path='output.jpg'):
    image = Image.fromarray(image_matrix.astype(np.uint8))
    image.save(image_path)

INTERPOLATION_METHODS = {
    1: zero_order_hold,
    2: first_order_hold,
    3: linear_interpolation
}


def open_image():
    global original_image_matrix, image_path
    image_path = filedialog.askopenfilename(filetypes=[("Image files", "*.jpg *.png")])
    if image_path:
        original_image_matrix = image_to_matrix(image_path)
        display_image(image_path, original_image_label)

def process_image():
    if not original_image_matrix.any():
        return  

    k = int(enlargement_spinbox.get())
    interpolation_method = INTERPOLATION_METHODS.get(interpolation_var.get(), linear_interpolation)

   
    enlarged_matrix = extend_image(original_image_matrix, k)


    enlarged_matrix = interpolation_method(enlarged_matrix, k)


    matrix_to_image(enlarged_matrix, 'output.jpg')
    display_image('output.jpg', enlarged_image_label)

def display_image(image_path, label):
    img = Image.open(image_path)
    img = ImageTk.PhotoImage(img)

    label.config(image=img)
    label.image = img


root = tk.Tk()
root.title("Image Enlargement GUI")

# Frame for inputs
input_frame = Frame(root)
input_frame.pack(pady=10)

# Upload Image Button
open_button = tk.Button(input_frame, text="Open Image", command=open_image)
open_button.grid(row=0, column=0, padx=10, pady=10)

# Enlargement Size (k) Input
enlargement_label = tk.Label(input_frame, text="Enlargement Factor (k):")
enlargement_label.grid(row=0, column=1, padx=10)
enlargement_spinbox = Spinbox(input_frame, from_=2, to=10, width=5)
enlargement_spinbox.grid(row=0, column=2, padx=10)

# Interpolation Method Selection
interpolation_var = IntVar(value=3)
method_label = tk.Label(input_frame, text="Interpolation Method:")
method_label.grid(row=1, column=0, columnspan=3)

zero_order_button = Radiobutton(input_frame, text="Zero-Order Hold", variable=interpolation_var, value=1)
zero_order_button.grid(row=2, column=0)

first_order_button = Radiobutton(input_frame, text="First-Order Hold", variable=interpolation_var, value=2)
first_order_button.grid(row=2, column=1)

linear_button = Radiobutton(input_frame, text="Linear Interpolation", variable=interpolation_var, value=3)
linear_button.grid(row=2, column=2)

# Process Image Button
process_button = tk.Button(root, text="Process Image", command=process_image)
process_button.pack(pady=10)

# Frames for Original and Enlarged Image Display
image_frame = Frame(root)
image_frame.pack(pady=10)

original_image_label = Label(image_frame)
original_image_label.grid(row=0, column=0, padx=20)

enlarged_image_label = Label(image_frame)
enlarged_image_label.grid(row=0, column=1, padx=20)


original_image_matrix = np.array([])  
image_path = ""

root.mainloop()
