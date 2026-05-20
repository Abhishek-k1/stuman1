#include <iostream>
#include <fstream>

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

class Event
{
  public:
      string eventName;
      string venue;
      string timing;
      string clubName;
};
      
int main()
{
  Club c;
  Student s;
  string searchClub;
  Event e;
  int choice;

  while(true)
  {
    cout << "\n===== CLUBHUB MENU =====\n";
    cout << "1. Add Club\n";
    cout << "2. Display Club\n";
    cout << "3. Register Student\n";
    cout << "4. Display Student\n";
    cout << "5. Search Club\n";
    cout << "6. Add Event\n";
    cout << "7. Display Events\n";
    cout << "8. Exit\n";
    

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

      ofstream file("clubs.txt", ios::app);

      file << c.clubName << " ";
      file << c.category << " ";
      file << c.coordinator << endl;

      file.close();



      cout << "Club Added Successfully!\n";


     }

    else if (choice == 2)
    {
      ifstream file("clubs.txt");

      string name, category, coordinator;

      while(file >> name >> category >> coordinator)
      {

        cout << "\nClub Name: " << name << endl;
        cout << "Category: " << category << endl;
        cout << "Coordinator: " << coordinator << endl;
    }
    file.close();
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
      else
      {
        cout << "Club Not Found!\n";
      }
    }
      else if(choice == 6)
      {
        cout << "Enter Event Name: ";
        cin >> e.eventName;

        cout << "Enter Venue: ";
        cin >> e.venue;

        cout << "Enter Timing: ";
        cin >> e.timing;

        cout << "Enter Club Name: ";
        cin >> e.clubName;

        ofstream file("events.txt", ios::app);

        file << e.eventName << " ";
        file << e.venue << " ";
        file << e.timing << " ";
        file << e.clubName << endl;

        file.close();

        cout << "Event Added Successfully!\n";
      }

      else if(choice == 7)
      {
        ifstream file("events.txt");

        string eventName, venue, timing, clubName;

        while(file >> eventName >> venue >> timing >> clubName)
        {
          cout << "\nEvent Name: " << eventName << endl;
          cout << "Venue: " << venue << endl;
          cout << "Timing: " << timing << endl;
          cout << "club Name: " << clubName << endl;
        }

        file.close();
      
    }
    else if  (choice == 8)
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

