#include <iostream>
using namespace std;

/*
=======================================================================================================================================================================
                                                           VEHICLE MANAGEMENT SYSTEM
=========================================================================================================================================================================

This program demonstrates:

1. classes and objects
2. Inheritance
3. Multilevel Inheritance
4. Constructors
5. Copy Constructor
6. Encapsulation
7. Static Members
8. Friend Function
9. Function Reuse

===========================================================================================================================================================================
*/

/*
------------------------------------------------------------------- BASE CLASS ----------------------------------------------------------------------------

base class is a parent class from which other classes
inherit properties and functions

*/

class vehicle
{
protected:
  /*----------------------------------------------------------------- PROTECTED MEMBER ---------------------------------------------------------------------  
     Accessible innside derived classes
  */

    int vehicleID;
    string brand;

private:
 /*----------------------------------------------------------------------- PRIVATE MEMBER ---------------------------------------------------------------------------
     Accessible only inside this class
     */

    int engineNumber;

/*--------------------------------------------------------------------------- PRIVATE HELPER FUNCTION ----------------------------------------------------------- 
      used only inside vehicle class
*/

    void validateSpeed(int speed)
    {
        if(speed < 0)
        {
            cout << "Invalid Speed!" << endl;
        }
    }

public:

/*-----------------------------------------------------------------------------------  STATIC VARIABLE ------------------------------------------------------------
     shared  by all objects
     counts total number of vehicles created
*/

     static int totalVehicles;

 /*------------------------------------------------------------------------------- DEFAULT CONSTRUCTOR -------------------------------------------------------------
     Automatically called when object is created without
     arguments.
 */    

     vehicle()
     {
        vehicleID = 0;
        brand = "unknown";
        engineNumber = 0;

        totalVehicles++;
     }

/*------------------------------------------------------------------- PARAMETERIZED CONNSTRUCTOR -----------------------------------------------------------------------
     used to initialize object eith values
*/

     vehicle(int id, string b, int engine)
     {
        vehicleID = id;
        brand = b;
        engineNumber = engine;

        totalVehicles++;
     }
 
/*----------------------------------------------------------------------------------- COPY CONSTRUCTOR --------------------------------------------------------------
           Copy value from another object.     
*/

     vehicle(vehicle &v)
     {
        vehicleID = v.vehicleID;
        brand = v.brand;
        engineNumber = v.engineNumber;

        totalVehicles++;
     }
   
/*-----------------------------------------------------------------------FUNCTION TO DISPLAY VEHICLE DETAILS--------------------------------------------------------
*/
    
     void showVehicle()
    {
        cout << "Vehicle ID : " << vehicleID << endl;
        cout << "Brand      : " << brand  << endl;
    }

/*---------------------------------------------------------------- STATIC FUNCTION ------------------------------------------------------------------------------------
    Calling using  class name
*/

    static void showTotalVehicles()
    {
        cout << "\nTotal Vehicles Created : " 
            << totalVehicles << endl;
    }
/*---------------------------------------------------------------------------- FRIEND FUNCTION DECLARATION ---------------------------------------------------------
  Allows comparePrice() to access private members
*/

friend void comparePrice(class car c1, class car c2);
};

// static variable must be defined outside class

int vehicle::totalVehicles = 0;

/*--------------------------------------------------------------------------- DERIVED CLASS --------------------------------------------------------------------------
Inheritance:
 car class inherts vehicle class
*/

class Car : public vehicle
{
 private:
      int price;
      int seats;

 public:

//------------------------------------------------------------------------------ DEFAULT CONSTRUCTOR ------------------------------------------------------------------

   Car() : vehicle()
   {
        price = 0;
        seats = 0;
   }

/*------------------------------------------------------------------------------- PARAMETRIZED CONSTRUCTOR --------------------------------------------------------------
  calls parent class constructor using :
*/

   Car(int id, string b, int engine, int p, int s) : vehicle(id, b, engine)

   {
    price = p;
    seats = s;
   }

// -------------------------------------------------------------------------- DISPLAY CAR DETAILS ---------------------------------------------------------------------

   void showCar()
   {

// --------------------------------------------------------------------------- REUSING PARENT CLASS FUNCTION ----------------------------------------------------------

        showVehicle();

        cout << "Price    : " << price << endl;
        cout << "seats    : " << seats << endl;

   }

/*-------------------------------------------------------------------------------------- GETTER FUNCTION -------------------------------------------------------------
   used to safely access private data
*/

   int getPrice()
   {
     return price;
   }
};

// ------------------------------------------------------------------------------ BIKE CLASS -----------------------------------------------------------------------

class Bike : public vehicle{
    private:
            bool helmetRequired;

    public:

// ---------------------------------------------------------------------------- CONSTRUCTOR ------------------------------------------------------------------------

       Bike(int id, string b,  int engine, bool h) : vehicle(id, b, engine)

       {
            helmetRequired = h;
       }

// ------------------------------------------------------------------------- DISPLAY BIKE DETAILS -----------------------------------------------------------------

       void showBike()
       {
        showVehicle();

        if(helmetRequired)
             cout << "Helmet Reqquired : Yes" << endl;
        else
             cout << "Helmet Required : No" << endl;
            
       }
};

/*-------------------------------------------------------------------------------- MULTILEVEL INHERITANCE --------------------------------------------------------------
   vehicle -------------> car ------------> electriccar
   ElectricCar inherits  Car class,  and car inherits vehicle class
*/

class ElectricCar : public Car
{
  private:
        int batteryCapacity;

  public:

// ------------------------------------------------------------------------------ CONSTRUCTOR ------------------------------------------------------------------------

      ElectricCar(int id, string b, int engine, int p, int s, int battery) : Car(id, b, engine, p, s)
  {
       batteryCapacity = battery;     
  }
  
//----------------------------------------------------------------- DISPLAY ELECTRIC CAR DETAILS ----------------------------------------------------------------------

     void showElectricCar()
     {

 //----------------  CALLING CAR CLASS FUNCTION

        showCar();
        
        cout << "Battery Capacity : " << batteryCapacity << " kwh" << endl;
     }   
};

/*------------------------------------------------------------------- FRIEND FUNCTION ----------------------------------------------------------------------------------
  compares prices of two cars.
*/

  void comparePrice(Car c1, Car c2)
  {
     if(c1.getPrice() > c2.getPrice())
     {
        cout << "\nCar 1 is more expensive." << endl;
     }
     else if(c2.getPrice() > c1.getPrice())
     {
        cout << "\nCar 2 is more expensive." << endl;
     }
     else
     {
        cout << "\nBoth cars have same  price." << endl;
     }

  }

/* ------------------------------------------------------------------------------ MAIN FUNCTION ----------------------------------------------------------------------
  Program execution starts here
*/

  int main()
  {

// ------------------------------------------------------------------------- CREATING CAR OBJECTS ----------------------------------------------------------------------

    Car c1(101, "Rolls-Royce", 63327, 60000000, 5);
    Car c2(102, "Bmw", 25434, 10000000, 5);

// ---------------------------------------------------------------------------- CREATING BIKE OBJECTS  ----------------------------------------------------------------

    Bike b1(201, "Yamaha", 87261, true);

// ----------------------------------------------------------------------- CREATING  ELECTRIC CAR OBJECTS -----------------------------------------------------------

    ElectricCar e1(301, "Tesla", 76352, 6500000, 5, 85);

// ----------------------------------------------------------------------- DISPLAY CAR 1 DETAILS -------------------------------------------------------------------------------

    cout << "\n====  CAR 1DETAILS ====\n";
    c1.showCar();

// ------------------------------------------------------------------- DISPLAY CAR 2 DETAILS -----------------------------------------------------------------------------------

    cout << "\n==== CAR 1 DETAILS ====\n";
    c2.showCar();

// ------------------------------------------------------------------------ DISPLAY  BIKE DETAILS -------------------------------------------------------------------------------

    cout << "\n==== BIKE DETAILS ====\n";
    b1.showBike();

// ------------------------------------------------------------------------ DISPLAY ELECTRIC CAR  DETAILS ----------------------------------------------------------------------------------

    cout << "\n==== ELECTRIC CAR DETAILS ====\n";
    e1.showElectricCar();

// ------------------------------------------------------------------------------- COMPARE CAR  PRICES ---------------------------------------------------------------------------------------------------

    comparePrice(c1, c2);

// ------------------------------------------------------------------------- DISPLAY TOTAL VEHICLES CREATED ------------------------------------------------------------------------------------------

    vehicle::showTotalVehicles();

    return 0;
  }
