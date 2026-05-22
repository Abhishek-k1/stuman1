#include <iostream>    // For cout, cin
#include <fstream>    // For file handling

using namespace std;

class Club      // class for storing club details
{
public:
  string clubName;   // stores club name
  string category;   // stores club category
  string coordinator;  // stores coordinator name 
};

class Student
{
public:
  string studentName;   // student name
  string usn;           // student USN
  string branch;        // student branch
  string interestedclub;   // Interseted club
};

class Event      // class for storing event details
{
public:
  string eventName;  // Event name
  string venue;      // Event venue
  string timing;     // Event timing
  string clubName;   // Related club name
};

int main()
{
  Club c;             // Object of Club class
  Student s;          // object of student class
  string searchClub;  // variable for searching club
  Event e;            // Object  of Event class
  int choice;         // Stoes menu choice

  while (true)
  {
    // Main menu display
    cout << "\n============= WELCOME TO CLUBHUB SYSTEM ==============\n";
    cout << "1. Add Club\n";
    cout << "2. Display Club\n";
    cout << "3. Register Student\n";
    cout << "4. Display Student\n";
    cout << "5. Search Club\n";
    cout << "6. Add Event\n";
    cout << "7. Display Events\n";
    cout << "8. Admin Menu\n";
    cout << "9. Exit\n";

    cout << "Enter Choice: ";
    cin >> choice;      // user enters menu choice

    // ADD CLUB FEATURE
    if (choice == 1)
    {
      cout << "Enter Club Name: ";
      cin.ignore();                  // Clears newline from buffer
      getline(cin, c.clubName);      // Takes full line input

      cout << "Enter Club Category: ";
      cin >> c.category;

      cout << "Enter Coordinator Name: ";
      cin.ignore();
      getline(cin, c.coordinator);

      ofstream file("clubs.txt", ios::app);

      file << c.clubName << " ";
      file << c.category << " ";
      file << c.coordinator << endl;

      file.close();    // Close file

      cout << "Club Added Successfully!\n";
    }

    // Display CLUB FEATURE
    else if (choice == 2)
    {
      ifstream file("clubs.txt");    // Opens file for reading

    // Checks if file exists
      if (!file)
      {
        cout << "No Club Data Found!\n";
      }
      string name, category, coordinator;

    // Reads data from file
      while (file >> name >> category >> coordinator)
      {

        cout << "\n==================================\n";
        cout << "\nClub Name: " << name << endl;
        cout << "Category: " << category << endl;
        cout << "Coordinator: " << coordinator << endl;
        cout << "===================================\n";
      }
      file.close();
    }

  // STUDENT REGISTRATION
    else if (choice == 3)
    {
      cout << "Enter Student Name: ";
      cin.ignore();
      getline(cin, s.studentName);

      cout << "Enter USN: ";
      cin >> s.usn;

      cout << "Enter Branch: ";
      cin.ignore();
      getline(cin, s.branch);

      cout << "Enter Interested Club: ";
      getline(cin, s.interestedclub);

      cout << "Student Registered Successfully!\n";
    }

    // DISPLAY STUDENT DETAILS
    else if (choice == 4)
    {
      cout << "\nStudent Name: " << s.studentName << endl;
      cout << "USN: " << s.usn << endl;
      cout << "Branch: " << s.branch << endl;
      cout << "Interested Club: " << s.interestedclub << endl;
    }

    // SEARCH CLUB FEATURE
    else if (choice == 5)
    {
      cout << "Enter club Name to Search: ";
      cin.ignore();
      getline(cin, searchClub);

    // Compares searched club with storeed club
      if (searchClub == c.clubName)
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

    // ADD EVENT FEATURE
    else if (choice == 6)
    {
      cout << "Enter Event Name: ";
      cin.ignore();
      getline(cin, e.eventName);

      cout << "Enter Venue: ";
      getline(cin, e.venue);

      cout << "Enter Timing: ";
      cin >> e.timing;

      cout << "Enter Club Name: ";
      cin.ignore();
      getline(cin, e.clubName);

      ofstream file("events.txt", ios::app);

      file << e.eventName << " ";
      file << e.venue << " ";
      file << e.timing << " ";
      file << e.clubName << endl;

      file.close();

      cout << "Event Added Successfully!\n";
    }

    // DISPLAY EVENTS
    else if (choice == 7)
    {
      ifstream file("events.txt");

      string eventName, venue, timing, clubName;

    // Reads event details from file
      while (file >> eventName >> venue >> timing >> clubName)
      {
        cout << "\nEvent Name: " << eventName << endl;
        cout << "Venue: " << venue << endl;
        cout << "Timing: " << timing << endl;
        cout << "Club Name: " << clubName << endl;
      }

      file.close();
    }

    // ADMIN MENU
    else if (choice == 8)
    {
      int adminChoice;

      cout << "\n===== ADMIN MENU =====\n";
      cout << "1. View Clubs\n";
      cout << "2. View Students\n";
      cout << "3. Remove Club\n";
      cout << "4. Back\n";

      cout << "Enter Choice: ";
      cin >> adminChoice;

      // VIEW CLUBS
      if (adminChoice == 1)
      {
        ifstream file("clubs.txt");

        string name, category, coordinator;

        while (file >> name >> category >> coordinator)
        {
          cout << "\nClub Name: " << name << endl;
          cout << "Category: " << category << endl;
          cout << "Coordinator: " << coordinator << endl;
        }

        file.close();
      }

      // VIEW STUDENTS
      else if (adminChoice == 2)
      {
        cout << "\nStudent Name: " << s.studentName << endl;
        cout << "USN: " << s.usn << endl;
        cout << "Branch: " << s.branch << endl;
        cout << "Interested Club: " << s.interestedclub << endl;
      }

      // REMOVE CLUB PLACEHOLDER
      else if (adminChoice == 3)
      {
        cout << "Remove Club Feature Coming Soon!\n";
      }

      // RETURN TO MAIN MENU
      else if (adminChoice == 4)
      {
        cout << "Returning to Main Menu...\n";
      }
    }

    // EXIT PROGRAM
    else if (choice == 9)
    {
      cout << "\nThank You For Using ClubHub System!\n";
      break;
    }

    // INVALID CHOICE
    else
    {
      cout << "Invalid Choice! Please Try Again.\n";
    }
  }
}
