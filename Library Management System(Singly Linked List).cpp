#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class lms {
public:
    int bookid, price, copies;
    string title, author;
    lms *next;

    // Constructor to initialize next pointer to nullptr
    lms() {
        next = nullptr;
    }

    // Function to create a new record
    void create();

    // Function to display all records
    void display();

    // Function to search for a record by book id
    void search();

    // Function to update a record
    void update();

    // Function to delete a record
    void Delete();

    // Function to save records to a file
    void saveToFile(string filename);

    // Function to load records from a file
    void loadFromFile(string filename);
};

// Global pointer to the start of the linked list
lms *start = nullptr;

// Function definitions

void lms::create() {
    // Create a new record
    lms *temp = new lms;

    // Input record details from user
    cout << "Enter the records :\n";
    cout << "Book_id :";
    cin >> temp->bookid;
    cout << "Book_name :";
    cin >> temp->title;
    cout << "Book Author :";
    cin >> temp->author;
    cout << "Price :";
    cin >> temp->price;
    cout << "Copies :";
    cin >> temp->copies;

    // Insert the new record at the beginning of the list
    temp->next = start;
    start = temp;
}

void lms::display() {
    // Display all records in the list
    lms *temp = start;
    if (temp == nullptr) {
        cout << "List is empty\n";
    }
    else {
        cout << "BID\tNAME\tAUTHOR\tPRICE\tCOPIES\n";
        while (temp != nullptr) {
            cout << temp->bookid << "\t" << temp->title << "\t" << temp->author << "\t" << temp->price << "\t" << temp->copies << endl;
            temp = temp->next;
        }
    }
}

void lms::search() {
    // Search for a record by book id
    int bid, f = 0;
    cout << "Enter the book id you want to search:";
    cin >> bid;
    lms *temp = start;
    while (temp != nullptr) {
        if (temp->bookid == bid) {
            f = 1;
            cout << "Book Found!!!\n";
            cout << temp->bookid << "\t" << temp->title << "\t" << temp->author << "\t" << temp->price << "\t" << temp->copies << endl;
        }
        temp = temp->next;
    }
    if (f == 0) {
        cout << "Book record not found";
    }
}

void lms::update() {
    // Update a record by book id
    int bid, f = 0;
    cout << "Enter the book id you want to search:";
    cin >> bid;
    lms *temp = start;
    while (temp != nullptr) {
        if (temp->bookid == bid) {
            f = 1;
            cout << "Enter new details of book : " << endl;
            cout << "\nBook_id :";
            cin >> temp->bookid;
            cout << "Book_name :";
            cin >> temp->title;
            cout << "Book Author :";
            cin >> temp->author;
            cout << "Price :";
            cin >> temp->price;
            cout << "Copies :";
            cin >> temp->copies;
        }
        temp = temp->next;
    }
    if (f == 1) {
        cout << "Book record is updated\n";
        display();
    }
    else if (f == 0) {
        cout << "Book Record Not Found!!!!";
    }
}

void lms::Delete() {
    // Delete a record by book id
    int id1;
    cout << "Enter the id to delete: ";
    cin >> id1;

    lms *temp = start;
    lms *prev = nullptr;

    while (temp != nullptr) {
        if (temp->bookid == id1) {
            if (prev == nullptr) {
                start = temp->next;
            }
            else {
                prev->next = temp->next;
            }
            delete temp;
            cout << "Book with ID " << id1 << " deleted successfully." << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "Book with ID " << id1 << " not found." << endl;
}

void lms::saveToFile(string filename) {
    // Save records to a file
    ofstream file(filename);
    lms *temp = start;
    while (temp != nullptr) {
        file << temp->bookid << " " << temp->title << " " << temp->author << " " << temp->price << " " << temp->copies << endl;
        temp = temp->next;
    }
    file.close();
    cout << "Data saved to file: " << filename << endl;
}

void lms::loadFromFile(string filename) {
    // Load records from a file
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file " << filename << endl;
        return;
    }
    start = nullptr;
    lms *prev = nullptr;
    while (file >> bookid >> title >> author >> price >> copies) {
        lms *temp = new lms;
        temp->bookid = bookid;
        temp->title = title;
        temp->author = author;
        temp->price = price;
        temp->copies = copies;
        if (start == nullptr) {
            start = temp;
        }
        else {
            prev->next = temp;
        }
        temp->next = nullptr;
        prev = temp;
    }
    file.close();
    cout << "Data loaded from file: " << filename << endl;
}

int main() {
    int ch;
    char x;
    lms l;
    string filename = "library_data.txt";
    l.loadFromFile(filename);

    do {
        // Display menu
        cout << "\n1. Accept the records\n";
        cout << "2. Display the records\n";
        cout << "3. Search the records\n";
        cout << "4. Update Record\n";
        cout << "5. Delete the records\n";
        cout << "6. Save to File\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        // Perform action based on user choice
        switch (ch) {
            case 1:
                l.create();
                // Prompt for adding more records
                while (true) {
                    cout << "Do you want to add more records? Y/N";
                    cin >> x;
                    if (x == 'y' || x == 'Y') {
                        l.create();
                    }
                    else {
                        break;
                    }
                }
                break;
            case 2:
                l.display();
                break;
            case 3:
                l.search();
                break;
            case 4:
                l.update();
                break;
            case 5:
                l.Delete();
                break;
            case 6:
                l.saveToFile(filename);
                break;
            case 7:
                l.saveToFile(filename);
                exit(0);
            default:
                cout << "INVALID CHOICE!";
                break;
        }
    } while (ch != 0);

    return 0;
}
