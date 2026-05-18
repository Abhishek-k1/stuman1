#include <iostream>
using namespace std;

class Club
{
    public:
      string clubName;
      string category;
      string coordinator;       
};

class Student
{
  public:
      string studentName;
      string usn;
      string branch;
      string interestedclub;
};
      
int main()
{
  Club c;
  Student s;
  string searchClub;
  int choice;

  while(true)
  {
    cout << "\n===== CLUBHUB MENU =====\n";
    cout << "1. Add Club\n";
    cout << "2. Display Club\n";
    cout << "3. Register Student\n";
    cout << "4. Display Student\n";
    cout << "5. Search Club\n";
    cout << "6. Exit\n";
    

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

    else if (choice == 3)
    {
      cout <<  "Enter Student Name: ";
      cin >> s.studentName;

      cout << "Enter USN: ";
      cin >> s.usn;

      cout  << "Enter Branch: ";
      cin >> s.branch;

      cout << "Enter Interested Club: ";
      cin >> s.interestedclub;

      cout << "Student Registered Successfully!\n";
    }

    else if(choice == 4)
    {
      cout  << "\nStudent Name: " << s.studentName << endl;
      cout << "USN: " << s.usn << endl;
      cout << "Branch: " << s.branch << endl;
      cout << "Interested Club: " << s.interestedclub << endl;
    }

    else if(choice == 5)
    {
      cout << "Enter club Name to Search: ";
      cin >> searchClub;

      if(searchClub == c.clubName)
      {
        cout << "\nClub Found!\n";

        cout << "Club Name: " << c.clubName << endl;
        cout << "Category: " << c.category << endl;
        cout << "Coordinator: " << c.coordinator << endl;
      }
    }
    else if  (choice == 6)
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

