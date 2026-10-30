#include <iostream>
#include <vector>
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

    vector<Product> getProducts() {
        return products;
    }
};

// Responsibility: Total price calculate karna
class CartCalculator {
public:
    double calculateTotalPrice(ShoppingCart& cart) {
        double total = 0;

        for (auto product : cart.getProducts()) {
            total += product.price;
        }

        return total;
    }
};

// Responsibility: Database mein save karna
class CartRepository {
public:
    void saveToDB(ShoppingCart& cart) {
        cout << "Shopping cart saved to database"
             << endl;
    }
};

int main() {
    Product p1("Laptop", 50000);
    Product p2("Mouse", 1000);

    ShoppingCart cart;

    cart.addProduct(p1);
    cart.addProduct(p2);

    CartCalculator calculator;
    CartRepository repository;

    cout << "Total Price: "
         << calculator.calculateTotalPrice(cart)
         << endl;

    repository.saveToDB(cart);

    return 0;
}
