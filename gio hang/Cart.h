#ifndef CART_H
#define CART_H

#include <vector>
#include <stdexcept>

class Product {
public:
    Product(const std::string& name, double price, int quantity = 1);
    std::string getName() const;
    double getPrice() const;
    int getQuantity() const;
    void setQuantity(int quantity);
    
private:
    std::string name;
    double price;
    int quantity;
};

class Cart {
public:
    Cart(int capacity);
    double calculateTotal() const;
    int getItemCount() const;
    void clearCart();
    void removeProduct(const std::string& productName);
    void purchaseProduct(const std::string& productName, int quantity);

private:
    int capacity;
    std::vector<Product> products;
};

#endif
