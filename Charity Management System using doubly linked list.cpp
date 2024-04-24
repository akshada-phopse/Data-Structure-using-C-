#include<iostream>
#include<string>
#include<fstream> 
using namespace std;

// Define the CMS class
class CMS {
public:
    // Member variables
    int donarid;
    long int amt, cno;
    string name, address;
    CMS *next, *temp, *prev; // Pointers for linked list operations

    // Member functions
    void create(); // Function to create a new record
    void display(); // Function to display all records
    void search(); // Function to search for a record
    void update(); // Function to update a record
    void Delete(); // Function to delete a record
}*start = NULL, *end1; // Initialize pointers for the start and end of the linked list

// Function to create a new record
void CMS::create() {
    // Allocate memory for a new CMS object
    temp = new CMS;
    cout << "Enter the records:\n";
    cout << "\nDonar_id: ";
    cin >> temp->donarid;
    cin.ignore(); // Clear the newline character from the buffer
    cout << "Donar name: ";
    cin.ignore(); // Clear any remaining newline characters
    getline(cin, temp->name); // Input the name using getline to allow spaces in the name
    cout << "Donar Address: ";
    getline(cin, temp->address);
    cout << "Amount: ";
    cin >> temp->amt;
    cout << "Phone no.: ";
    cin >> temp->cno;
    temp->next = temp->prev = NULL; // Initialize next and prev pointers
    // Add the new record to the linked list
    if (start == NULL) {
        end1 = start = temp;
    } else {
        end1->next = temp;
        temp->prev = end1;
        end1 = temp;
    }
}

// Function to display all records
void CMS::display() {
    int cnt = 0;
    CMS *temp = start;
    if (temp == NULL) {
        cout << "List is empty\n";
    } else {
        // Display record details in a tabular format
        cout << "DONAR RECORDS\n";
        cout << "-----------------------------------------------------------\n";
        cout << "DID\tNAME\t\tADDRESS\t\t\tAMOUNT\tCONTACT_NO\n";
        cout << "-----------------------------------------------------------\n";
        while (temp != nullptr) {
            cout << temp->donarid << "\t" << temp->name << "\t\t" << temp->address << "\t\t" << temp->amt << "\t" << temp->cno << endl;
            cnt++;
            temp = temp->next;
        }
    }
}

// Function to search for a record
void CMS::search() {
    int did, f = 0;
    CMS *temp = start;
    cout << "Enter the donar id you want to search: ";
    cin >> did;
    // Search for the record with the given ID
    while (temp != NULL) {
        if (temp->donarid == did) {
            f = 1;
            cout << "Record Found!!!\n";
            cout << "-----------------------------------------------------------\n";
            cout << "DID\tNAME\t\tADDRESS\t\t\tAMOUNT\tCONTACT_NO\n";
            cout << "-----------------------------------------------------------\n";
            cout << temp->donarid << "\t" << temp->name << "\t\t" << temp->address << "\t\t" << temp->amt << "\t" << temp->cno << endl;
            break;
        }
        temp =temp->next;
    }
    if (f == 0) {
        cout << "Donar record not found";
    }    
}

// Function to update a record
void CMS::update() {
    int did;
    CMS *temp = start;
    cout << "Enter the donar id you want to update: ";
    cin >> did;
    // Search for the record with the given ID
    while (temp != NULL) {
        if (temp->donarid == did) {
            cout << "Enter the new records\n";
            cout << "Enter the records :\n";
            cout << "Donar_id :";
            cin >> temp->donarid;
            cout << "Donar name :";
            cin >> temp->name;
            cout << "Donar Addres:";
            cin >> temp->address;
            cout << "Amount:";
            cin >> temp->amt;
            cout << "Phone no. :";
            cin >> temp->cno;
            cout << "RECORD UPDATED";
        }
        temp =temp->next;
    }
}

// Function to delete a record
void CMS::Delete() {
    int del;
    CMS *temp, *p;
    temp = start;
    cout << "Enter the donar id whose record you want to delete. ";
    cin >> del;
    // Check if the list is empty
    if (start == NULL) {
        cout << "List is empty\n";
        return;
    }
    // Search for the record with the given ID
    while (temp != NULL) {
        if (temp->donarid == del) {
            break;
        }
        p = temp;
        temp = temp->next;
    }
    // Delete the record if found
    if (temp == NULL) {
        cout << "Donar record not found";
        return;
    }
    if (temp == start) {
        start = start->next;
        start->prev = NULL;
        delete temp;
    } else if (temp == end1) {
        p->next = NULL;
        end1 = p;
        delete temp;
    } else {
        p->next = temp->next;
        temp->next->prev = p;
        delete(temp);
    }
    cout << "DONAR RECORD DELETED SUCCESSFULLY";
}

// Main function
int main() {
    int ch;
    char x;
    CMS c;
    // Menu-driven loop
    do {
        cout << "\n1. Enter the records\n";
        cout << "2. Display the records\n";
        cout << "3. Search the records\n";
        cout << "4. Update the records\n";
        cout << "5. Delete the records\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            c.create();
            while (true) {
                cout << "Do you want to add more records? Y/N";
                cin >> x;
                if (x == 'y' || x == 'Y') {
                    c.create();
                } else {
                    break;
                }
            }
            break;
        case 2:
            c.display();
            break;
        case 3:
            c.search();
            break;
        case 4:
            c.update();
            break;
        case 5:
            c.Delete();
            break;
        case 6:
            exit(0);
        default:
            cout << "INVALID CHOICE!";
            break;
        }
    } while (ch != 0);
    return 0;
}
