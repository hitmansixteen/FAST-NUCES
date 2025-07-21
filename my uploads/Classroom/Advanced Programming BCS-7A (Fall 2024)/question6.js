const Cart = {
    items: [],

    addItem(item) {
        const index = this.items.findIndex(
            (i) => i.name === item.name && i.size === item.size
        );
        if (index !== -1) {
            this.items[index].quantity += item.quantity;
        } else {
            this.items.push(item);
        }
    },

    removeItem(name, size) {
        const index = this.items.findIndex(
            (i) => i.name === name && i.size === size
        );
        if (index !== -1) {
            this.items.splice(index, 1);
        } else {
            return `Item "${name}" of size "${size}" not found in the cart.`;
        }
    },

    calculateTotal() {
        return this.items.reduce(
            (total, item) => total + item.price * item.quantity,
            0
        );
    },

    displayCart() {
        this.items.forEach((item) => {
            console.log(
                `Name: ${item.name}, Size: ${item.size}, Price: ${
                    item.price
                }, Quantity: ${item.quantity}, Total Price: ${
                    item.price * item.quantity
                }`
            );
        });
    },
};

// Example usage
Cart.addItem({ name: "T-shirt", size: "M", price: 19.99, quantity: 2 });
Cart.addItem({ name: "Jeans", size: "L", price: 49.99, quantity: 1 });
Cart.addItem({ name: "T-shirt", size: "M", price: 19.99, quantity: 1 });

Cart.displayCart();
console.log("Total Cost:", Cart.calculateTotal());

Cart.removeItem("Jeans", "L");
Cart.displayCart();
console.log("Total Cost after removal:", Cart.calculateTotal());

console.log(Cart.removeItem("Shoes", "M"));
