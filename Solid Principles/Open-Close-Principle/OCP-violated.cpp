
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
};

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

// OCP VIOLATED
class CartRepository {
public:

    void saveToDB(
        const ShoppingCart& cart,
        string database
    ) {

        if (database == "MySQL") {
            cout << "Saving cart to MySQL"
                 << endl;
        }

        else if (database == "MongoDB") {
            cout << "Saving cart to MongoDB"
                 << endl;
        }

        else if (database == "VectorDB") {
            cout << "Saving cart to Vector DB"
                 << endl;
        }

        else {
            cout << "Invalid Database"
                 << endl;
        }
    }
};

int main() {

    Product p1("Laptop", 50000);
    Product p2("Mouse", 1000);

    ShoppingCart cart;

    cart.addProduct(p1);
    cart.addProduct(p2);

    CartCalculator calculator;

    cout << "Total Price: "
         << calculator.calculateTotalPrice(cart)
         << endl;

    CartRepository repository;

    repository.saveToDB(cart, "MySQL");

    repository.saveToDB(cart, "MongoDB");

    repository.saveToDB(cart, "VectorDB");

    return 0;
}
