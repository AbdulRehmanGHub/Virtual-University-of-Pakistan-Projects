/*
	Name: Abdul Rehman
	VU-ID: BC220424444
*/
#include <iostream>
#include <conio.h>

using namespace std;

class Student {
public:
    string name;
    Student() : name(" ") {}
    Student(string n) : name(n) {}
};

class TreeNode {
public:
    Student* student;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : student(), left(NULL), right(NULL) {}
    TreeNode(Student* s) : student(s), left(NULL), right(NULL) {}

    // Inserting a new student into the tree
    TreeNode* insert(TreeNode* root, Student* student) {
        if (root == NULL) {
            return new TreeNode(student);
        }
        if (student->name < root->student->name) {
            root->left = insert(root->left, student);
        } else if (student->name > root->student->name) {
            root->right = insert(root->right, student);
        } else {
    // Handling the duplicate entries
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* temp = minValueNode(root->right);
            root->student = temp->student;
            root->right = remove(root->right, temp->student->name);
        }
        return root;
    }

    // Traverse the tree in-order
    void inorder(TreeNode* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->student->name << "\n";
            inorder(root->right);
        }
    }
	// Find the node with the smallest value
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }
	// Remove student from the tree
    TreeNode* remove(TreeNode* root, string name) {
        if (root == NULL) {
            return root;
        }
        if (name < root->student->name) {
            root->left = remove(root->left, name);
        } else if (name > root->student->name) {
            root->right = remove(root->right, name);
        } else {
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

    // Get the inorder successor
            TreeNode* temp = minValueNode(root->right);
    // Copy the inorder successor's data
            root->student = temp->student;
    // Delete the inorder successor
            root->right = remove(root->right, temp->student->name);
        }
        return root;
    }
};

//Starting the main function
int main() {
    TreeNode* root = NULL;
    TreeNode tree;
    int choice, numberOfStudent;
    string name;

    while (true) {
        cout << "Menu: Examination Seat Allocation";
        cout << "\n1. Allocate Seat";
        cout << "\n2. Remove Student";
        cout << "\n3. Display Seating According To alphabetical order";
        cout << "\n4. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter the number of Students for which you want to allocate the seat: ";
                cin >> numberOfStudent;
                cin.ignore();
                for (int i = 1; i <= numberOfStudent; i++) {
                    cout << "Enter student name: ";
                    getline(cin, name);
                    root = tree.insert(root, new Student(name));
                }
                break;
            case 2:
                cout << "Enter student name to remove: ";
                getline(cin, name);
                root = tree.remove(root, name);
                break;
            case 3:
                cout << "Seating Arrangement: \n";
                tree.inorder(root);
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}

