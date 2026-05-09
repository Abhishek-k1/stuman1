#include <iostream> // Header files for input/outpuuut operations
#include <string>   // Header files for using string class

using namespace std; // Allows use of cout,  string without  std::

/*
CLASS: Social Media
A blueprint representing a social media user profile.
it store user information  and provides related function.
*/

class SocialMedia
{

private:
    /*
    ------------------PRIVATE DATA MEMBERS-------------------------
    variable accessible only inside the class.
    used for data hiding (Encapsulation).
    */

    string username; // store username of user
    int age;         // store age of user
    int friends;     // store number  of friends

    /*
    ---------------STATIC VARIABLE---------------------------------
    shared  by all objects of the class.
    only one copy exists in memory.

    */
    static int totalUsers;

public:
    /*
    --------------------------------- CONSTRUCTOR -------------------------
    special member function automatically called when object is created
    used for  initialization.
    */
    SocialMedia(string u, int a)
    {
        username = u; // Assign parameter to username
        age = a;      // Assignparameter to age
        friends = 0;  // Initially no friends
        totalUsers++; // Increase total users count
    }

    //  ------------------------- DISPLAY PROFILE()----------------------

    void displayProfile()
    {
        cout << "\n---- Profile Info ----" << endl;
        cout << "\n Username : " << username << endl;
        cout << "\n Age     : " << age << endl;
        cout << "\n Friends : " << friends << endl;
    }

    // -------------------------- ADD FRIEND()------------------------------

    void addFriend()
    {
        friends++; //  Increment friend count
        cout << username << " added a new friend.\n";
    }

    /*-------------------STATIC MEMBER FUNCTION -------------------------
    function belonging to class instead of object
    can be called using class name.
    */

    static void showTotalUsers()
    {
        cout << "\nTotal Users: " << totalUsers << endl;
    }

    /*----------------------NESTED CLASS ----------------------------
    A class declared inside another class
    used for logical grouping.
    */

    class Message
    {

    public:
        // -------------------- SEND MESSAGE()------------------------

        void sendMessage(const string &sender, const string &receiver)
        {
            cout << sender
                 << " sent a message to "
                 << receiver << endl;
        }
    };

    /*--------------------FRIEND FUNCTION DECLARATION -------------------
    A non member  function allowed to acces private member  of class.
    */

    friend void compareFriends(const SocialMedia &s1, const SocialMedia &s2);
};

/*----------------STATIC MEMBERINITIALIZATION -------------------------
Static variables must be defined outside class.
*/
int SocialMedia::totalUsers = 0;

// commpare friend counts of two users

void compareFriends(const SocialMedia &s1, const SocialMedia &s2)
{

    cout << "\n----- Friend Comparison ------" << endl;

    if (s1.friends > s2.friends)
        cout << s1.username << " has more friends.\n";
    else if (s1.friends < s2.friends)
        cout << s2.username << " has more friends.\n";
    else
        cout << "Both have same number of friends.\n";
}

/*  --------------------- MAIN FUNCTION ----------------------------
    Execution of program starts  from here.
*/
int main()
{

    /*
    object creation
    constructor automatically called
    */
    SocialMedia user1("Rahul", 20);
    SocialMedia user2("Anjali", 21);

    // calling member function

    user1.addFriend();

    user2.addFriend();

    // Display profile information

    user1.displayProfile();
    user2.displayProfile();

    // call  friend function

    compareFriends(user1, user2);

    // call static funnction using class name

    SocialMedia::showTotalUsers();

    // create object of nested class

    SocialMedia::Message msg;

    // call  nested class function

    msg.sendMessage("Rahul", "Anjali");

    return 0; // Indicates sucessfully execution
}