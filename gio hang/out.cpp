#include "Cart.h"

Product::Product(const std::string& name, double price, int quantity) : name(name), price(price), quantity(quantity) {
    if (quantity < 1) {
        throw std::invalid_argument("Invalid quantity");
    }
}

std::string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

int Product::getQuantity() const {
    return quantity;
}

void Product::setQuantity(int quantity) {
    if (quantity < 1) {
        throw std::invalid_argument("Invalid quantity");
    }
    this->quantity = quantity;
}

Cart::Cart(int capacity) : capacity(capacity) {
    if (capacity < 1) {
        throw std::invalid_argument("Invalid capacity");
    }
}

double Cart::calculateTotal() const {
    double total = 0;
    for (const Product& product : products) {
        total += product.getPrice() * product.getQuantity();
    }
    return total;
}

int Cart::getItemCount() const {
    return products.size();
}

void Cart::clearCart() {
    products.clear();
}

void Cart::removeProduct(const std::string& productName) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getName() == productName) {
            products.erase(it);
            return;
        }
    }
}

void Cart::purchaseProduct(const std::string& productName, int quantity) {
    if (quantity < 1) {
        throw std::invalid_argument("Invalid purchase quantity");
    }

    if (products.size() >= capacity) {
        throw std::overflow_error("Cart is full");
    }

    for (Product& product : products) {
        if (product.getName() == productName) {
            int newQuantity = product.getQuantity() + quantity;
            product.setQuantity(newQuantity);
            return;
        }
    }

    // Product not found, add a new one
    products.push_back(Product(productName, 0.0, quantity));
}
