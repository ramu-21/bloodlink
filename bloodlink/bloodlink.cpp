#include <iostream>
#include <string>
using namespace std;

// Store donor details
struct Donor
{
    int id;
    string name;
    int age;
    string bloodGroup;
    string phone;
};

// Maximum number of donors
const int MAX_DONORS = 100;

Donor donors[MAX_DONORS];
int donorCount = 0;

// Blood available
int A_positive = 0;
int A_negative = 0;
int B_positive = 0;
int B_negative = 0;
int AB_positive = 0;
int AB_negative = 0;
int O_positive = 0;
int O_negative = 0;


// Add a donor
void addDonor()
{
    if (donorCount >= MAX_DONORS)
    {
        cout << "\nDonor list is full.\n";
        return;
    }

    cout << "\nEnter Donor ID: ";
    cin >> donors[donorCount].id;

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, donors[donorCount].name);

    cout << "Enter Age: ";
    cin >> donors[donorCount].age;

    cout << "Enter Blood Group: ";
    cin >> donors[donorCount].bloodGroup;

    cout << "Enter Phone Number: ";
    cin >> donors[donorCount].phone;

    donorCount++;

    cout << "\nDonor added successfully!\n";
}


// Show all donors
void viewDonors()
{
    if (donorCount == 0)
    {
        cout << "\nNo donors available.\n";
        return;
    }

    cout << "\n========== DONORS ==========\n";

    for (int i = 0; i < donorCount; i++)
    {
        cout << "\nDonor ID     : " << donors[i].id;
        cout << "\nName         : " << donors[i].name;
        cout << "\nAge          : " << donors[i].age;
        cout << "\nBlood Group  : " << donors[i].bloodGroup;
        cout << "\nPhone        : " << donors[i].phone;
        cout << "\n----------------------------\n";
    }
}


// Find donors by blood group
void findDonor()
{
    string group;
    bool found = false;

    cout << "\nEnter Blood Group: ";
    cin >> group;

    cout << "\nDonors with blood group " << group << ":\n";

    for (int i = 0; i < donorCount; i++)
    {
        if (donors[i].bloodGroup == group)
        {
            cout << "\nID    : " << donors[i].id;
            cout << "\nName  : " << donors[i].name;
            cout << "\nPhone : " << donors[i].phone;
            cout << "\n----------------------------\n";

            found = true;
        }
    }

    if (!found)
    {
        cout << "\nNo donor found.\n";
    }
}


// Add blood
void addBlood()
{
    string group;
    int units;

    cout << "\nEnter Blood Group: ";
    cin >> group;

    cout << "Enter number of units: ";
    cin >> units;

    if (group == "A+")
        A_positive += units;

    else if (group == "A-")
        A_negative += units;

    else if (group == "B+")
        B_positive += units;

    else if (group == "B-")
        B_negative += units;

    else if (group == "AB+")
        AB_positive += units;

    else if (group == "AB-")
        AB_negative += units;

    else if (group == "O+")
        O_positive += units;

    else if (group == "O-")
        O_negative += units;

    else
    {
        cout << "\nInvalid blood group.\n";
        return;
    }

    cout << "\nBlood added successfully!\n";
}


// Show available blood
void viewBlood()
{
    cout << "\n====== AVAILABLE BLOOD ======\n";

    cout << "A+  : " << A_positive << " units\n";
    cout << "A-  : " << A_negative << " units\n";
    cout << "B+  : " << B_positive << " units\n";
    cout << "B-  : " << B_negative << " units\n";
    cout << "AB+ : " << AB_positive << " units\n";
    cout << "AB- : " << AB_negative << " units\n";
    cout << "O+  : " << O_positive << " units\n";
    cout << "O-  : " << O_negative << " units\n";
}


// Need blood
void needBlood()
{
    string group;
    int units;

    cout << "\nEnter Blood Group Needed: ";
    cin >> group;

    cout << "Enter number of units needed: ";
    cin >> units;

    if (group == "A+")
    {
        if (A_positive >= units)
        {
            A_positive -= units;
            cout << "\nBlood given successfully.\n";
        }
        else
            cout << "\nNot enough A+ blood available.\n";
    }

    else if (group == "A-")
    {
        if (A_negative >= units)
        {
            A_negative -= units;
            cout << "\nBlood given successfully.\n";
        }
        else
            cout << "\nNot enough A- blood available.\n";
    }

    else if (group == "B+")
    {
        if (B_positive >= units)
        {
            B_positive -= units;
            cout << "\nBlood given successfully.\n";
        }
        else
            cout << "\nNot enough B+ blood available.\n";
    }

    else if (group == "B-")
    {
        if (B_negative >= units)
        {
            B_negative -= units;
            cout << "\nBlood given successfully.\n";
        }
        else
            cout << "\nNot enough B- blood available.\n";
    }

    else if (group == "AB+")
    {
        if (AB_positive >= units)
        {
            AB_positive -= units;
            cout << "\nBlood given successfully.\n";
        }
        else
            cout << "\nNot enough AB+ blood available.\n";
    }

    else if (group == "AB-")
    {
        if (AB_negative >= units)
        {
            AB_negative -= units;
            cout << "\nBlood given successfully.\n";
        }
        else
            cout << "\nNot enough AB- blood available.\n";
    }

    else if (group == "O+")
    {
        if (O_positive >= units)
        {
            O_positive -= units;
            cout << "\nBlood given successfully.\n";
        }
        else
            cout << "\nNot enough O+ blood available.\n";
    }

    else if (group == "O-")
    {
        if (O_negative >= units)
        {
            O_negative -= units;
            cout << "\nBlood given successfully.\n";
        }
        else
            cout << "\nNot enough O- blood available.\n";
    }

    else
    {
        cout << "\nInvalid blood group.\n";
    }
}


// Main function
int main()
{
    int choice;

    while (true)
    {
        cout << "\n\n==============================\n";
        cout << "          BLOODLINK\n";
        cout << "      Blood Bank System\n";
        cout << "==============================\n";

        cout << "1. Add Donor\n";
        cout << "2. View Donors\n";
        cout << "3. Find Donor\n";
        cout << "4. View Available Blood\n";
        cout << "5. Add Blood\n";
        cout << "6. Need Blood\n";
        cout << "7. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addDonor();
                break;

            case 2:
                viewDonors();
                break;

            case 3:
                findDonor();
                break;

            case 4:
                viewBlood();
                break;

            case 5:
                addBlood();
                break;

            case 6:
                needBlood();
                break;

            case 7:
                cout << "\nThank you for using BloodLink!\n";
                return 0;

            default:
                cout << "\nInvalid choice. Try again.\n";
        }
    }

    return 0;
}