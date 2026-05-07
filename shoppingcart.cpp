#include <iostream>
using namespace std;

// online shopping system using c++ oop
// Includes product management, cart, and checkout system

// class to store product details
class product
{
public:
    int id;
    string name;
    double price;
    int stock;
    product() {}
    product(int i, string n, double p, int s)
    {
        id = i;
        name = n;
        price = p;
        stock = s;
    }
    void display()
    {
        cout << id << " | " << name
             << "|Price: " << price
             << "|Stock: " << stock << endl;
    }
};

// class to store items added to cart(product + quantity)
class CartItem
{
public:
    int productId;
    int quantity;
    CartItem() {}
    CartItem(int id, int q)
    {
        productId = id;
        quantity = q;
    }
};

// Main store class that manage products, cart, and operations
class Store
{
private:
    product products[100];
    CartItem cart[100];
    int productCount;
    int cartSize;

public:
    Store()
    {
        productCount = 0;
        cartSize = 0;
    }

    //  Add new product to store
    void addProduct(int id, string name, double price, int stock)
    {
        products[productCount] = product(id, name, price, stock);
        productCount++;
    }

    // Display all available products
    void showProducts()
    {
        cout << "\n--- PRODUCT LIST ---\n";
        for (int i = 0; i < productCount; i++)
        {
            products[i].display();
        }
    }

    // search product by ID
    void searchproduct(int id)
    {
        for (int i = 0; i < productCount; i++)
        {
            if (products[i].id == id)
            {
                cout << "\nProduct Found:\n";
                products[i].display();
                return;
            }
        }
        cout << "Product not found!\n";
    }

    // Add product to cart after checking stock
    void addToCart(int pid, int qty)
    {
        for (int i = 0; i < productCount; i++)
        {
            if (products[i].id == pid)
            {

                if (products[i].stock >= qty)
                {
                    cart[cartSize] = CartItem(pid, qty);
                    cartSize++;
                    products[i].stock -= qty;
                    cout << "Added to cart successfully!\n";
                }
                else
                {
                    cout << "Not enough stock!\n";
                }

                return;
            }
        }
        cout << "Invalid Product id!\n";
    }

    // Display all items in cart
    void showCart()
    {
        cout << "\n--- CART ITEMS ---\n";
        if (cartSize == 0)
        {
            cout << "Cart is empty!\n";
            return;
        }
        for (int i = 0; i < cartSize; i++)
        {
            cout << "Product ID: " << cart[i].productId
                 << " | Quantity: " << cart[i].quantity << endl;
        }
    }

    // calculate total bill and generate invoice
    void checkout()
    {
        double total = 0;
        cout << "\n--- BILL ---\n";
        for (int i = 0; i < cartSize; i++)
        {
            for (int j = 0; j < productCount; j++)
            {
                if (products[j].id == cart[i].productId)
                {
                    double cost = cart[i].quantity * products[j].price;
                    total += cost;
                    cout << products[j].name
                         << " x " << cart[i].quantity
                         << " = " << cost << endl;
                }
            }
        }
        cout << "---------------------\n";
        cout << "TOTAL BILL = " << total << endl;
        cartSize = 0;
    }
};

// Main function  -program execution starts here
int main()
{
    Store store;
    store.addProduct(1, "Laptop", 50000, 5);
    store.addProduct(2, "Phone", 20000, 10);
    store.addProduct(3, "Headphones", 2000, 15);

    int choice;

    while (true)
    {

        cout << "\n==== ONLINE SHOP MENU =====\n";
        cout << "1. Show Products\n";
        cout << "2. Search Product\n";
        cout << "3. Add to Cart\n";
        cout << "4. View Cart\n";
        cout << "5. Checkout\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1)
        {
            store.showProducts();
        }
        else if (choice == 2)
        {
            int id;
            cout << "Enter Product ID to search: ";
            cin >> id;
            store.searchproduct(id);
        }

        else if (choice == 3)
        {
            int id, qty;
            cout << "Enter Product ID: ";
            cin >> id;
            cout << "Enter Quantity: ";
            cin >> qty;
            store.addToCart(id, qty);
        }

        else if (choice == 4)
        {
            store.showCart();
        }

        else if (choice == 5)
        {
            store.checkout();
        }

        else if (choice == 0)
        {
            cout << "Exiting...\n";
            break;
        }

        else
        {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
