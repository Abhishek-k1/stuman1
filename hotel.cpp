#include <iostream>
using namespace std;
/*
===================================================================
                        HOTEL MANAGEMENT SYSTEM
===================================================================
1. class & object
2. encapsulation
3. inheritance
4. static member
5. friend funnction
6. dynamic memory allocation
7. constructor
8. pointers
9. function modularity
*/

class Person  // Base class
{
protected:
      char name[50];

public:
      void getPerson()
      {
        cout << "Enter customer name: ";
        cin >> name;
      }

      void showPerson() 
      {
        cout << "Customer Name: " << name << endl;
      }
};
class Customer : public Person    // Derived class
{
private:
       int roomNo;
       int days;
       float bill;

       static int  customerCount;   // static member

       void calculateBill()     // Function Modularity
       {
        bill = days * 5000;
       }
public:
    Customer()           // Constructor
    {
        roomNo = 0;
        days = 0;
        bill = 0;
        customerCount++;
    }

    void bookRoom()
    {
        getPerson();

        cout << "Enter room number: ";
        cin >> roomNo;

        cout << "Enter number of days: ";
        cin >> days;

        calculateBill();
    }

    void display()
    {
        showPerson();

        cout << "Room Number: " << roomNo << endl;
        cout << "Days Stayed: " << days << endl;
        cout << "Bill Amount: " << bill << endl;
    }

    friend void showTotalCustomers();    // Friend Function

    static void totalCustomer()       // static function
    {
        cout << "Total Customers: " << customerCount << endl;
    }
};

int Customer::customerCount = 0;      // static Member Initialization

void showTotalCustomers()      
{
    cout << "\nFriend Function Accessing Static Member" << endl;
    Customer::totalCustomer();
}

int main()
{
    int n;

    cout << "Enter number of customer: ";
    cin >> n;

    Customer *c = new Customer[n];        //Dynamic memory allocation

    for(int i = 0; i < n; i++)
    {
        cout << "\nEnter details for customer " << i+1 << endl;
        (c + i)->bookRoom();              // Input
    }

    cout << "\n------ HOTEL RECORD -----\n";

    for(int i = 0; i < n; i++)
    {
        cout << "\nCustomer " << i + 1 << endl;

        (c + i)->display();           //Output
    }
    showTotalCustomers();             // Friend function

    delete[] c;            // Memory deallocation
    
    return 0;
}