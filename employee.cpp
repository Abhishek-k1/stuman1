#include <iostream>
using namespace std;
/*============================================================================================================================================
                                                EMPLOYEE MANAGEMENT SYSTEM
  ============================================================================================================================================
*/
class person
{
protected:
  int EmployeeID;
  string name;

public:
  static int totalEmployee;

  person()
  {
    EmployeeID = 0;
    name = "Unknown";
    totalEmployee++;
    cout << "Person connstructor called" << endl;
  }
  person(int id, string n)
  {
    EmployeeID = id;
    name = n;

    totalEmployee++;

    cout << "Person parameterized Constructor called" << endl;
  }

  void showPerson()
  {
    cout << "Employee ID : " << EmployeeID << endl;
    cout << "Name        : " << name << endl;
  }

  static void showTotalEmployees()
  {
    cout << "\nTotal Employees : "
         << totalEmployee << endl;
  }
};

int person::totalEmployee = 0;

class Developer : virtual public person
{
protected:
  string programmingLanguage;

public:
  Developer()
  {
    programmingLanguage = "c++";
  }

  Developer(int id, string n, string lang)
      : person(id, n)
  {
    programmingLanguage = lang;

    cout << "Developer Parameterized Constructor Called" << endl;
  }

  void showDeveloper()
  {
    showPerson();

    cout << "Programming Language: "
         << programmingLanguage << endl;
  }
};

class Manager : virtual public person
{
protected:
  int teamSize;

private:
  int salary;

  void validatesalary()
  {
    if (salary < 0)
    {
      cout << "Invalid Salary!" << endl;
    }
  }

public:
  Manager()
  {
    teamSize = 0;
    salary = 0;

    cout << "Manager Constructor Called " << endl;
  }

  Manager(int id, string n, int t, int s)
      : person(id, n)
  {
    teamSize = t;
    salary = s;

    validatesalary();

    cout << "Manager Parameterized Constructor  Called" << endl;
  }

  void showManager()
  {
    showPerson();

    cout << "Team Size :"
         << teamSize << endl;

    cout << "Salary  :"
         << salary << endl;
  }

  int getSalary()
  {
    return salary;
  }
  friend void compareSalary(Manager n, class TeamLead t);
};

class TeamLead : public Developer, public Manager
{
private:
  int bonus;

public:
  TeamLead(int id, string n, string lang, int t, int s, int b)
      : person(id, n),
        Developer(id, n, lang),
        Manager(id, n, t, s)
  {
    bonus = b;

    cout << "TeamLead Constructor Called" << endl;
  }

  void showTeamLead()
  {
    Developer::showDeveloper();

    cout << "Team Size : "
         << teamSize << endl;

    cout << "Bonus : "
         << bonus << endl;

    cout << "Total Salary : "
         << getSalary() + bonus << endl;
  }

  int totalIncome()
  {
    return getSalary() + bonus;
  }
};

void compareSalary(Manager m, TeamLead t)
{
  if (m.salary > t.totalIncome())
  {
    cout << "\nManager earns more." << endl;
  }
  else if (m.salary < t.totalIncome())
  {
    cout << "\nTeamLead earns more." << endl;
  }
  else
  {
    cout << "\nBoth earn same salary." << endl;
  }
}

int main()
{
  cout << "\n==== MANAGER DETAILS ====\n";

  Manager m1(101, "Abhishek", 10, 8000000);

  m1.showManager();

  cout << "\n==== TEAM LEAD DETAILS ====\n";

  TeamLead t1(201, "Aman", "python", 5, 70000, 15000);

  t1.showTeamLead();

  cout << "\n==== SALARY COMPARISON ====\n";

  compareSalary(m1, t1);
  person::showTotalEmployees();

  return 0;
}

 
