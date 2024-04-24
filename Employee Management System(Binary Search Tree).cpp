#include<iostream>
#define MAX_SIZE 20
using namespace std;

int totalCount = 0; // Global variable to count total number of nodes in the tree

class Employee
{
public:
    string name, dob; // Employee's name and date of birth
    int age, salary; // Employee's age and salary
    Employee *leftChild, *rightChild; // Pointers to left and right children

    // Function prototypes
    void create();
    void insert(Employee *root, Employee *next);
    void display(Employee *root);
    void height();
    void leafNodes(Employee *root);
    void displayMinSalary(Employee *root);
    void displayMaxSalary(Employee *root);

}*root; // Declare root node and stack for tree traversal

// Custom stack implementation
class Stack {
private:
    Employee *elements[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(Employee *element) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        elements[++top] = element;
    }

    Employee *pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return nullptr;
        }
        return elements[top--];
    }

    bool isEmpty() {
        return top < 0;
    }
};

// Function to create the binary tree
void Employee::create()
{
    int choice;
    Employee *next;
    root = new Employee; // Allocate memory for root node
    cout << "Enter the company employee information: \n";
    cout << "Enter name: ";
    cin >> root->name;
    cout << "Enter date of birth (DOB): ";
    cin >> root->dob;
    cout << "Enter salary: ";
    cin >> root->salary;
    cout << "Enter age: ";
    cin >> root->age;

    totalCount = 1; // Initialize total node count
    root->leftChild = root->rightChild = NULL;

    do {
        cout << "Do you want to add a new node? (0/1): ";
        cin >> choice;
        if (choice == 1) {
            next = new Employee; // Allocate memory for new node
            cout << "Enter employee information: \n";
            cout << "Enter name: ";
            cin >> next->name;
            cout << "Enter date of birth (DOB): ";
            cin >> next->dob;
            cout << "Enter salary: ";
            cin >> next->salary;
            cout << "Enter age: ";
            cin >> next->age;

            next->leftChild = next->rightChild = NULL;
            insert(root, next); // Insert new node in the tree
        }
    } while (choice == 1);
}

// Function to insert a node into the binary tree
void Employee::insert(Employee *root, Employee *next)
{
    if (root->salary > next->salary) {
        if (root->leftChild == NULL) {
            root->leftChild = next;
        } else {
            insert(root->leftChild, next); // Recursively call insert function for left subtree
        }
    } else if (root->salary < next->salary) {
        if (root->rightChild == NULL) {
            root->rightChild = next;
        } else {
            insert(root->rightChild, next); // Recursively call insert function for right subtree
        }
    }
}

// Function to display employees with minimum salary
void Employee::displayMinSalary(Employee *root)
{
    Employee *temp = root;

    while (temp->leftChild != NULL) {
        temp = temp->leftChild;
    }

    cout << "Employees with minimum salary:\n";
    cout << "NAME\t\tDOB\t\tSALARY\t\tAGE\n";
    cout << temp->name << "\t\t" << temp->dob << "\t\t" << temp->salary << "\t\t" << temp->age << endl;
}

// Function to display employee with maximum salary
void Employee::displayMaxSalary(Employee *root)
{
    Employee *temp = root;

    while (temp->rightChild != NULL) {
        temp = temp->rightChild;
    }

    cout << "Employee with maximum salary:\n";
    cout << "NAME\t\tDOB\t\tSALARY\t\tAGE\n";
    cout << temp->name << "\t\t" << temp->dob << "\t\t" << temp->salary << "\t\t" << temp->age << endl;
}

// Function to display the binary tree
void Employee::display(Employee *root)
{
    if (root == NULL) {
        return;
    }
    cout << endl;
    cout << root->name << "\t\t" << root->dob << "\t\t" << root->salary << "\t\t" << root->age << endl;
    display(root->leftChild);
    display(root->rightChild);
}

// Function to calculate and display the height of the tree
void Employee::height()
{
    int leftHeight = 0, rightHeight = 0;

    // Calculate height of left subtree
    if (root->leftChild != NULL) {
        Employee *temp = root->leftChild;
        while (temp != NULL) {
            leftHeight++;
            temp = temp->leftChild;
        }
    }

    // Calculate height of right subtree
    if (root->rightChild != NULL) {
        Employee *temp = root->rightChild;
        while (temp != NULL) {
            rightHeight++;
            temp = temp->rightChild;
        }
    }

    // Display maximum height
    if (leftHeight >= rightHeight) {
        cout << "Height of the tree is: " << leftHeight << endl;
    } else {
        cout << "Height of the tree is: " << rightHeight << endl;
    }
}

// Function to display leaf nodes of the tree
void Employee::leafNodes(Employee *root)
{
    Employee *temp = root;
    Stack s;
    s.push(temp);
    while (!s.isEmpty()) {
        temp = s.pop();
        if (temp->leftChild == NULL && temp->rightChild == NULL) {
            cout << temp->name << endl;
        }
        if (temp->rightChild) {
            s.push(temp->rightChild);
        }
        if (temp->leftChild) {
            s.push(temp->leftChild);
        }
    }
}

// Main function
int main()
{
    int choice;
    Employee empTree;

    do {
        cout << "\nEnter your Choice: ";
        cout << "\n1. CREATE";
        cout << "\n2. DISPLAY";
        cout << "\n3. HEIGHT of tree ";
        cout << "\n4. LEAF nodes of tree ";
        cout << "\n5. MIN SALARY:";
        cout << "\n6. MAX SALARY: ";
        cout << "\n7. EXIT: ";
        cout << "\nEnter your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                empTree.create();
                break;
            case 2:
                cout << "NAME\t\tDOB\t\tSALARY\t\tAGE\n";
                empTree.display(root);
                break;
            case 3:
                empTree.height();
                break;
            case 4:
                cout << "Leaf nodes of the tree:\n";
                empTree.leafNodes(root);
                break;
            case 5:
                empTree.displayMinSalary(root);
                break;
            case 6:
                empTree.displayMaxSalary(root);
                break;
            case 7:
                exit(0);
                break;
            default:
                cout << "Invalid Choice!!";
                break;
        }
    } while (choice != 7);

    return 0;
}
