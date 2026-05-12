#include <iostream>
using namespace std;
/*======================================================================================================================================================================
                                                      LIBRARY MANAGEMENT SYSTEM
  =======================================================================================================================================================================
  This program demonstrate
1. classes and objects 
2. inheritance
3. constructors
4. static data member  and static function
5. friend function
6. array of objects
7. function calling
8. encapuslation
9. code reusability
10. object copying

*/

/*---------------------- BASE CLASS --------------------
  commom details for all library items
*/

class LibraryItem
{
   protected:
         int itemID;        // stores ID of item
         string title;      // stores title of item
   
  public:
       static int totalItems;    // shared  counter for all items

 //---------------------------- DEFAULLT CONSTRUCTOR ------------------
       LibraryItem()
       {
              itemID = 0;
              title = "Unknown";
              totalItems++;
       }

//-------------------------- PARAMETERIZED CONSTRUCTOR --------------
       LibraryItem(int id, string t)
       {
        itemID = id;
        title = t;
        totalItems++;
       }

// ------------------------ COPY CONSTRUCTOR ------------------------

       LibraryItem(const LibraryItem &obj)
       {
        itemID = obj.itemID;
        title = obj.title;
       }

//  show basic details

       void showBasicInfo()
       {
        cout  << "Item ID : " << itemID << endl;
        cout <<  "Title   : " <<  title << endl;
       }

// ------------------------------ STATIC FUNNCTION ---------------------
       static void showTotalitems()
       {
        cout << "\nTotal Library Items : "
             << totalItems << endl;
       }
};

// initialized static variable

int LibraryItem::totalItems = 0;

/*-------------------------- DERIVED CLASS -----------------------------
 add book specific features
*/

class Book: public LibraryItem
{
    private:
        string author;
        bool  issued;

// Helper function = internal use only

        void checkIssuedStatus()
        {
            if(issued)
               cout << "Status :  Issued" << endl;
        else 
        cout << "status : Available" << endl;
        }

    public:

//------------------------ DEFAULT CONSTRUCTOR ------------------------- 
       
      Book() : LibraryItem()
      {
        author = "Unknown";
        issued = false;
      }

//-------------------------- PARAMETERIZED CONSTRUCTOR ------------------

      Book(int id, string t, string a, bool i)
                   : LibraryItem(id, t)
     {
        author = a;
        issued = i;
     }
    Book(const Book  &b) : LibraryItem(b)
    {
        author = b.author;
        issued = b.issued;
    }

//-------------------------- COPY CONNSTRUCTOR -------------------------- 
     void issueBook()
     {
        if(issued)
        {
            cout  << "Book already issued.\n";
        }
        else
        {
            issued = true;
            cout << "Book issued successfully.\n";
        }
     }

//  Return book = resets status

     void returnBook()
     {
        if(issued)
        {
            issued = false;
            cout << "Book  returned successfully.\n";
        }
        else
        {
            cout <<  "Book  was not issued.\n";
        }
     }

// Display full book info

     void displayBook()
     {
        showBasicInfo();  // from base class

        cout << "Author : "
             << author << endl;

             checkIssuedStatus();
     }

// search book by title

     bool searchBook(string bookTitle)
     {
        return (title == bookTitle);
     }

//------------------------------- FRIEND FUNCTION ----------------------

     friend void compareBooks(Book b1, Book b2);
};

//--------------------------- DERIVED CLASS --------------------------
class EBook : public Book
{
    private:
         float fileSize;

    public:

// CONSTRUCTOR
       EBook(int id, string t, string a, bool i, float size)
                            : Book(id, t, a, i)
     {
        fileSize = size;
     }

// Display ebook details
     void showEBook()
     {
        displayBook(); // reuse Book function

        cout << "File Size : "
             << fileSize << "MB" << endl;
     }
};

//--------------------- FRIEND FUNCTION ----------------------------
 void compareBooks(Book b1, Book b2)
 {
    cout << "\nComparing Books:\n";

    if(b1.searchBook("C++"))
    cout << "First book is c++ related.\n";

    if(b2.searchBook ("Python"))
    cout << "Second book is pyhton related.\n";
 }
 
 //---------------MAIN FUNCTION ---------------------------
 int main()
 {

    // Creating objects
    Book books[2];

    books[0] = Book(101, "C++", "Bjarne", false);
    books[1] = Book(102, "python", "Guide", true);

    // copy objject
    Book b3 = books[0];

    //Display book
    cout << "\n==== BOOK 1 ====\n";
    books[0].displayBook();

    cout << "\n==== BOOK 2 ====\n";
    books[1].displayBook();

    cout << "\n==== COPY BOOK ====\n";
    b3.displayBook();

    //issue and return flow
    cout << "\n====  ISSUE BOOK ====\n";
    books[0].issueBook();

    cout << "\n==== AFTER ISSUE ====\n";
    books[0].displayBook();

    cout << "\n==== RETURN BOOK ====\n";
    books[0].returnBook();

    // Ebbok object
    EBook e1(201, "java", "James Gosling", false, 15.5);

    cout << "\n==== EBOOK DETAILS ====\n";
    e1.showEBook();

    // friend function
    compareBooks(books[0], books[1]);

    // static function
    LibraryItem::showTotalitems();

    return 0;
 }