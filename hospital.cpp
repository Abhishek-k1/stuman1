#include <iostream>
using namespace std;
class Patient
{
private:
    // ================ DATA MEMBERS =======================================

    int patientID;
    string name;
    int age;
    string disease;
    float fees;

    // static variable shared by all objects
    static int totalPatients;

public:
    // =========== DEFAULT CONSTRUCTOR ======================================
    // Automatically called when object is created without values

    Patient()
    {
        patientID = 0;
        name = "None";
        age = 0;
        disease = "None";
        fees = 0;
    }

    // =============== PARAMETERIZED CONSTRUCTOR ==============================
    // called when object is created with __value

    Patient(int id, string n, int a, string d, float f)
    {
        patientID = id;
        name = n;
        age = a;
        disease = d;
        fees = f;

        totalPatients++;
    }
    // ================== MEMBER FUNCTION ==========================================
    //  Input patient details

    void addPatient()
    {
        cout << "\nEnter Patient ID: ";
        cin >> patientID;

        cout << "\nEnter Name: ";
        cin >> name;

        cout << "\nEnter age: ";
        cin >> age;

        cout << "\nEnter Disease: ";
        cin >> disease;

        cout << "\nEnter fees:  ";
        cin >> fees;

        totalPatients++;
    }

    // ===================== MEMBER FUNCTION =======================================
    // Display patient details

    void showPatient()
    {
        cout << "\n------------------------";
        cout << "\nPatient ID : " << patientID;
        cout << "\nName       : " << name;
        cout << "\nAge        : " << age;
        cout << "\nDisease    : " << disease;
        cout << "\nFees       : " << fees;
        cout << "\n------------------------\n";
    }

    // ================= GETTER FUNCTION =========================================
    //  return patient ID

    int getID()
    {
        return patientID;
    }

    // ====================== NORMAL FUNCTION ==================================
    //  Assign traetment to patient

    void treatmentDetails()
    {
        cout << "Treatment Assigned successfully.\n";
    }

    // ================= STATIC FUNCTION ==========================================
    //  Display total number of patients

    static void showTotalPatient()
    {
        cout << "\nTotal Patient: " << totalPatients << endl;
    }

    // ========================== FRIEND FUNCTION ==============================
    // Friend function declaration
    friend void generateBill(Patient p);

private:
    // ======================= PRIVATE FUNCTION =================================
    //  can only be used inside class

    void checkPatient()
    {
        cout << "Checking patient records...\n";
    }
};

//  ===================== STATIC VARIABLE DEFINITION ===========================
// Static variable must be defined outside class

int Patient::totalPatients = 0;

// ========================== FRIEND FUNCTION DEFINITION =========================
//  can access private numbers directly

void generateBill(Patient p)
{
    cout << "\n====BILL RECEIPT =====";
    cout << "\nPatientID : " << p.patientID;
    cout << "\nPatient Name : " << p.name;
    cout << "\nTotal Fees : " << p.fees;
    cout << "\n========================\n";
}
int main()
{
    // ==================== ARRAY OF OBJECTS ====================================
    // can store maximum 10 patients

    Patient patients[10];

    int choice;
    int n = 0;
    int searchID;
    int found = 0;

    // =============================== MENU LOOP ========================================

    do
    {
        cout << "\n===== HOSPITAL MANAGEMENT SYSTEM =====\n";

        cout << "1. Add Patient\n";
        cout << "2. Show All Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Assign Treatment\n";
        cout << "5. Generate Bill\n";
        cout << "6. Total patients\n";
        cout << "7. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {

            // =========================== CASE 1 ===========================
            // Add patient

        case 1:

            if (n < 10)
            {
                patients[n].addPatient();
                n++;
            }
            else
            {
                cout << "Hospital Full!\n";
            }
            break;

            // ============================ CASE 2 =============================
            // show  all patients

        case 2:

            if (n == 0)
            {
                cout << "No Patient Records Found.\n";
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    patients[i].showPatient();
                }
            }

            break;

            // =============================== CASE 3 ==========================
            // search patient by ID

        case 3:

            cout << "\nEnter Patient ID to Search: ";
            cin >> searchID;

            found = 0;

            for (int i = 0; i < n; i++)
            {
                if (patients[i].getID() == searchID)
                {
                    patients[i].showPatient();
                    found = 1;
                    break;
                }
            }
            if (found == 0)
            {
                cout << "Patient Not Found.\n";
            }
            break;

            // ========================== CASE 4 ==================================
            // Assign treatment

        case 4:

            cout << "\nEnter Patient ID for Treatment: ";
            cin >> searchID;

            found = 0;

            for (int i = 0; i < n; i++)
            {
                if (patients[i].getID() == searchID)
                {
                    generateBill(patients[i]);
                    found = 1;
                    break;
                }
            }
            if (found == 0)
            {
                cout << "Patient Not Found.\n";
            }
            break;

            // ========================= CASE 5 =================================
            // Generate  bill

        case 5:

            cout << "\nEnter Patient ID for Bill: ";
            cin >> searchID;

            found = 0;

            for (int i = 0; i < n; i++)
            {
                if (patients[i].getID() == searchID)
                {
                    generateBill(patients[i]);
                    found = 1;
                    break;
                }
            }
            if (found == 0)
            {
                cout << "Patient Not Found.\n";
            }
            break;

            //   ============================ CASE 6 ===============================
            //  show total patient

        case 6:

            Patient::showTotalPatient();

            break;

        case 7:

            cout << "\nExiting Program...\n";

            break;

        default:

            cout << "\nInvalid Choice.\n";
        }

        //  =============================== case 7 ============================
        //  Exit program

    } while (choice != 7);

    return 0;
}