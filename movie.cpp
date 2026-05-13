#include <iostream>
#include <string>
using namespace std;
/*
===================================================================
                       MOVIE BOOKING SYSTEM
===================================================================
This program demonstrate:-
1. class and object
2. Encapsulation
3. Inheritance
4. static Member
5. Friend function
6. Arrays
7.  constructors
8. Dynamic memory allocation
9. Pointers
*/

// CLASS: blueprint for creating objects
class Movie
{
private:
    int ticketPrice[3]; // Array: stores multiple values (3 ticket prices)

    int totalAmount; // Variable: stores sum of ticket prices

    void calculateTotal() //Member function: Internal logic only
    {
        totalAmount = ticketPrice[0] + ticketPrice[1] + ticketPrice[2]; // adds values
    }

protected:
    int movieID;            // protected: accessible in child class

    string movieName;       // String: stores text (movie name)

public:

    static int totalBookings;  // static: shared  by all objects

    Movie()     // constructor:  runs automatrically when object is  created
    {
        movieID = 0;               // initialization
        movieName = "Unknown";    // default value

        for (int i = 0; i < 3; i++)    // Loop: repeats 3 times
        {
            ticketPrice[i] = 0;        // initialize array valuess
        }

        totalAmount = 0;        // initialized total

        totalBookings++;       // static counter increase
    }
    void input()        // Member function: takes input
    {
        cout << "\nEnter Movie ID: ";
        cin >> movieID;

        cin.ignore();        // clears buffer before string input

        cout << "Enter Movie Name: ";
        getline(cin, movieName);        // read full line

        cout << "Enter 3 Ticket Prices:\n";

        for (int i = 0; i < 3; i++)  // loop: input 3 va;ues
        {
            cin >> ticketPrice[i];
        }

        calculateTotal();   //function call: computes total
    }

    void display() // Member funnction: shows data
    {
        cout << "\nMovie ID: " << movieID;
        cout << "\nMovie Name: " << movieName;

        cout << "\nTicket Prices: ";

        for (int i = 0; i < 3; i++)  // Loop: prints array
        {
            cout << ticketPrice[i] << " ";
        }

        cout << "\nTotal Amount: " << totalAmount << endl;
    }

    friend void checkVIP(Movie m); // Friend function: can access private data
};

int Movie::totalBookings = 0;   // static initialization  outside class

class PremiumMovie : public Movie // Inheritance: child class gets parent features
{
private:
    string screenType;   // Extra  feature only for premiumMovie

public:
    void getscreenType()    // Input function
    {
        cout << "Enter Screen Type (IMAX/3D): ";
        cin >> screenType;
    }

    void showscreenType()    // Display function
    {
        cout << "Screen Type: " << screenType << endl;
    }
};

void checkVIP(Movie m)   // Friend function definition

{
    if (m.totalAmount > 500)     //  condition check
    {
        cout << "VIP Booking\n";
    }
    else
    {
        cout << "Normal Booking\n";
    }
}

int main()     //Mainn funcytion : program start here
{

    int n;

    cout << "Enter number of bookings: ";
    cin >> n;

    PremiumMovie *ptr = new PremiumMovie[n];  // Dynamic memory: array of objects

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter Details for Booking " << i + 1 << endl;

        (ptr + i)->input();          // pointer-> object access
        (ptr + i)->getscreenType();
    }

    cout << "\n==== BOOKING DETAILS ====\n";

    for (int i = 0; i < n; i++)
    {
        (ptr + i)->display();      // show data

        (ptr + i)->showscreenType();    // pass object to function

        checkVIP(*(ptr + i));

        cout << "---------------------------\n";
    }

    cout << "\nTotal Booking: " << Movie::totalBookings << endl;  // static access

    delete[] ptr;    // memory free

    return 0;      // program ends
}