#include<iostream>
#include<string>
#define MAX_SIZE 20
using namespace std;

class FMT {
private:
    int generation, age, leftChildCount = 0, rightChildCount = 0, totalCount = 0;
    string name, gender;
    FMT *leftChild, *rightChild;

public:
    // Function to create the family tree
    void create();

    // Function to insert a new member into the family tree
    void insert(FMT *root, FMT *next);

    // Function to display the family tree
    void display(FMT *root);

    // Function to determine the total number of generations in the family tree
    void totalGen();

    // Function to display leaf nodes (members without children) of the family tree
    void leafNodes(FMT *root);
}*root, *next, *stack[MAX_SIZE], *temp;

// Function definitions

void FMT::create() {
    int choice;
    FMT *next;
    // Create the root node of the family tree
    root = new FMT;
    cout << "Enter your records\n";
    cout << "Enter name: ";
    cin >> root->name;
    cout << "Enter gender: ";
    cin >> root->gender;
    cout << "Enter age: ";
    cin >> root->age;
    cout << "Enter generation number: ";
    cin >> root->generation;
    root->leftChild = root->rightChild = NULL;
    totalCount = leftChildCount = rightChildCount = 1;

    // Add more members to the family tree if desired
    do {
        cout << "Do you want to add more records? (1/0): ";
        cin >> choice;
        if (choice == 1) {
            // Create a new member and insert into the family tree
            next = new FMT;
            cout << "\nEnter the data for the new node\n";
            cout << "Enter name: ";
            cin >> next->name;
            cout << "Enter gender: ";
            cin >> next->gender;
            cout << "Enter age: ";
            cin >> next->age;
            cout << "Enter generation number: ";
            cin >> next->generation;
            next->leftChild = next->rightChild = NULL;
            insert(root, next);
        }
    } while (choice == 1);
}

void FMT::insert(FMT *root, FMT *next) {
    char chr;
    cout << "\nOn which side do you want to insert the data, 'L' or 'R'? ";
    cin >> chr;
    // Insert the new member as the left child of the current node
    if (chr == 'L' || chr == 'l') {
        if (root->leftChild == NULL) {
            root->leftChild = next;
            leftChildCount++;
        } else {
            insert(root->leftChild, next);
        }
    }
    // Insert the new member as the right child of the current node
    if (chr == 'R' || chr == 'r') {
        if (root->rightChild == NULL) {
            root->rightChild = next;
            rightChildCount++;
        } else {
            insert(root->rightChild, next);
        }
    }
}

void FMT::display(FMT *root) {
    if (root == NULL) {
        return;
    } else {
        // Display member details
        cout << root->name << "\t\t" << root->gender << "\t\t" << root->age << "\t\t" << root->generation << endl;
        // Recursively display left and right subtrees
        display(root->leftChild);
        display(root->rightChild);
    }
}

void FMT::totalGen() {
    // Determine the total number of generations in the family tree
    if (leftChildCount >= rightChildCount) {
        cout << "\nTotal generation number: " << leftChildCount;
    } else {
        cout << "\nTotal generation number: " << rightChildCount;
    }
}

void FMT::leafNodes(FMT *root) {
    int top = -1;
    temp = root;
    // Display leaf nodes (members without children) of the family tree
    if (root != NULL) {
        do {
            while (temp != NULL) {
                // Push nodes onto the stack until a leaf node is reached
                top++;
                stack[top] = temp;
                temp = temp->leftChild;
            }
            if (top != -1) {
                temp = stack[top];
                // If leaf node, display member details
                if (temp->leftChild == NULL && temp->rightChild == NULL) {
                    cout << "\nNAME\t\tGENDER\t\tAGE\t\tGENERATION\n";
                    cout << temp->name << "\t\t" << temp->gender << "\t\t" << temp->age << "\t\t" << temp->generation << endl;
                }
                // Move to the right child of the current node
                temp = temp->rightChild;
                top--;
            }
        } while (top != -1 || temp != NULL);
    }
}
  
int main() {
    int choice;
    FMT f;
    // Menu-driven program to interact with the family tree
    do {
        cout << "\n1. Enter the records\n";
        cout << "2. Display the records\n";
        cout << "3. Total generation records\n";
        cout << "4. Display Leaf node\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                f.create();
                break;
            case 2:
                 cout << "\nNAME\t\tGENDER\t\tAGE\t\tGENERATION\n";
                f.display(root);
                break;
            case 3:
                f.totalGen();
                break;
            case 4:
                f.leafNodes(root);
                break;
            case 5:
                exit(0);
            default:
                cout << "\nINVALID CHOICE!\n";
                break;
        }
    } while (choice != 5);
    return 0;
}
