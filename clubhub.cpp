#include <iostream>
using namespace std;

class Club
{
    public:
      string clubName;
      string category;
      string coordinator;       
};
int main()
{
  Club c;
  int choice;

  while(true)
  {
    cout << "\n===== CLUBHUB MENU =====\n";
    cout << "1. Add Club\n";
    cout << "2. Display Clubs\n";
    cout << "3. Exit\n";

    cout << "Enter Choice: ";
    cin >> choice;

    if(choice == 1)
    {
      cout << "Enter Club Name: ";
      cin >> c.clubName;

      cout << "Enter Club Category: ";
      cin >> c.category;

      cout  << "Enter Coordinator Name: ";
      cin >> c.coordinator;

      cout << "Club Added Successfully!\n";


     }
    else if (choice == 2)
    {
        cout << "\nClun Name: " << c.clubName << endl;
        cout << "Category: " << c.category << endl;
        cout << "Coordinator: " << c.coordinator << endl;
    }
    else if  (choice == 3)
    {
       cout << "Exiting Program...";
        break;
    }
    else
    {
        cout << "Invalid Choice";
    }
  }
}

