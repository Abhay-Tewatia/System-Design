
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Responsibility: Product ka data store karna
class Product {
public:
    string name;
    double price;

    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
};

// Responsibility: Products manage karna
class ShoppingCart {
private:
    vector<Product> products;

public:
    void addProduct(Product product) {
        products.push_back(product);
    }

    const vector<Product>& getProducts() const {
        return products;
    }
};

// Responsibility: Total price calculate karna
class CartCalculator {
public:
    double calculateTotalPrice(
        const ShoppingCart& cart
    ) {
        double total = 0;

        for (const auto& product : cart.getProducts()) {
            total += product.price;
        }

        return total;
    }
};

// Abstract class
// Responsibility: Database save karne ka contract define karna
class CartRepository {
public:

    virtual void saveToDB(
        const ShoppingCart& cart
    ) = 0;

    virtual ~CartRepository() {}
};

// MySQL Database
class MySQLCartRepository : public CartRepository {
public:

    void saveToDB(
        const ShoppingCart& cart
    ) override {
        cout << "Saving cart to MySQL Database"
             << endl;
    }
};

// MongoDB Database
class MongoDBCartRepository : public CartRepository {
public:

    void saveToDB(
        const ShoppingCart& cart
    ) override {
        cout << "Saving cart to MongoDB Database"
             << endl;
    }
};

// Vector Database
class VectorDBCartRepository : public CartRepository {
public:

    void saveToDB(
        const ShoppingCart& cart
    ) override {
        cout << "Saving cart to Vector Database"
             << endl;
    }
};

int main() {

    Product p1("Laptop", 50000);
    Product p2("Mouse", 1000);

    ShoppingCart cart;

    cart.addProduct(p1);
    cart.addProduct(p2);

    // Calculate total price
    CartCalculator calculator;

    cout << "Total Price: "
         << calculator.calculateTotalPrice(cart)
         << endl;

    // Database selection
    MySQLCartRepository mysql;
    MongoDBCartRepository mongo;
    VectorDBCartRepository vectorDB;

    // Save to MySQL
    CartRepository* repository = &mysql;
    repository->saveToDB(cart);

    // Save to MongoDB
    repository = &mongo;
    repository->saveToDB(cart);

    // Save to Vector DB
    repository = &vectorDB;
    repository->saveToDB(cart);

    return 0;
}
