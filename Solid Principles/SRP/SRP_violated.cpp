#include<bits/stdc++.h>
using namespace std;

// Product class representing any item of any Ecommerce

class Product{
    public:
    string name;
    double price;

    Product(string name, double price){
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart{
    private:
    vector<Product>products;

    public:
    // Responsibility 1: Product manage karna
    void addProduct(Product product){
        products.push_back(product);
    }

    // Responsibilty 2: Total price calculation karna
    double calculationTotalPrice(){
        double total =0;
        for(auto product: products){
            total +=product.price;
        }
        return total;
    }
    
     // Responsibility 3: Database mein save karna
    void saveToDB() {
        cout << "Shopping cart saved to database"
             << endl;
    }
};

int main(){
    Product p1("Laptop", 50000);
    Product p2("Keyboard", 500);

    ShoppingCart cart;
    cart.addProduct(p1);
    cart.addProduct(p2);

    cout << "Total Price: "<< cart.calculationTotalPrice()<<endl;

    cart.saveToDB();
    return 0;
}