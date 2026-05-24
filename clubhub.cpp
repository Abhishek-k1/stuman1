#include <iostream>    // For cout, cin
#include <fstream>    // For file handling
#include <vector>

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
  string adminUsername = "admin";
  string adminPassword = "1234";


int main()
{
  vector<Club> clubs;             // Object of Club class
  vector<Student> students;          // object of student class
  string searchClub;  // variable for searching club
  vector<Event> events;            // Object  of Event class
  int choice;         // Store menu choice

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
       Club c;

      cout << "Enter Club Name: ";
      cin.ignore();                  // Clears newline from buffer
      getline(cin, c.clubName);      // Takes full line input

      cout << "Enter Club Category: ";
      cin >> c.category;

      cout << "Enter Coordinator Name: ";
      cin.ignore();
      getline(cin, c.coordinator);

      clubs.push_back(c);

      cout << "Club Added Successfully!\n";
    }

    // Display CLUB FEATURE
    else if (choice == 2)
    {
        for(int i = 0; i < clubs.size(); i++)
        {
          cout << "\nClub Name: "
               << clubs[i].clubName << endl;

          cout << "Category: "
               << clubs[i].category << endl;

          cout << "Coordinator:  "
               << clubs[i].coordinator << endl;
        }
    }

  // STUDENT REGISTRATION
    else if (choice == 3)
    {
      Student s;
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

      students.push_back(s);

      cout << "Student Registered Successfully!\n";
    }

    // DISPLAY STUDENT DETAILS
    else if (choice == 4)
    {
      for(int i = 0; i < students.size(); i++)
      {
         cout << "\nStudent Name: " 
               << students[i].studentName << endl;

         cout << "USN: "
               << students[i].usn << endl;

         cout << "Branch: " 
               << students[i].branch << endl;

         cout << "Interested Club: " 
              << students[i].interestedclub << endl;
    }
  }

    // SEARCH CLUB FEATURE
    else if (choice == 5)
    {
      bool found = false;

      cout << "Enter club Name to Search: ";
      cin.ignore();
      getline(cin, searchClub);

      for(int i = 0; i < clubs.size(); i++)
      {
      if (searchClub == clubs[i].clubName)
      {
        cout << "\nClub Found!\n";

        cout << "Club Name: "
             << clubs[i].clubName << endl;

        cout << "Category: " 
             << clubs[i].category << endl;

        cout << "Coordinator: " 
             << clubs[i].coordinator << endl;
        
             found = true;

            }
          }
          if(found == false)
      {
        cout << "Club Not Found!\n";
      }
    }

    // ADD EVENT FEATURE
    else if (choice == 6)
    {

      Event e;

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

      events.push_back(e);

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
      string username;
      string password;

      cout << "Enter Username: ";
      cin >> username;

      cout << "Enter Password: ";
      cin >> password;
   
      if(username == adminUsername &&
         password == adminPassword)
      {
        cout << "\nLogin Successful!\n";
      
      
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
        for(int i = 0; i < students.size(); i++)
        {
          cout << "\nStudent Name: "
               << students[i].studentName << endl;

        cout << "USN: " 
             << students[i].usn << endl;

        cout << "Branch: " 
            << students[i].branch << endl;
            
        cout << "Interested Club: "
             << students[i].interestedclub << endl;
      }
      }
      
      // REMOVE CLUB PLACEHOLDER
      else if  (adminChoice == 3)
      {
        cout << "Remove Club Feature Coming Soon!\n";
      }

      // RETURN TO MAIN MENU
      else if (adminChoice == 4)
      {
        cout << "Returning to Main Menu...\n";
      }
    }

     else 
      {
        cout << "Acccess Denied!\n";
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
