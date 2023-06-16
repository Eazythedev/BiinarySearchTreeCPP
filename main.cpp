#include <iostream>
#include <string>

using namespace std;

struct Contact {
    string name;
    string phone;
};

struct Node {
    Contact contact;
    Node* left;
    Node* right;
};

class Phonebook {
private:
    Node* root;

    Node* createNode(Contact contact) {
        Node* newNode = new Node;
        newNode->contact = contact;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    Node* insertNode(Node* root, Contact contact) {
        if (root == nullptr) {
            return createNode(contact);
        }

        if (contact.name < root->contact.name) {
            root->left = insertNode(root->left, contact);
        } else if (contact.name > root->contact.name) {
            root->right = insertNode(root->right, contact);
        }

        return root;
    }

    Node* searchNode(Node* root, string name) {
        if (root == nullptr || root->contact.name == name) {
            return root;
        }

        if (name < root->contact.name) {
            return searchNode(root->left, name);
        } else {
            return searchNode(root->right, name);
        }
    }

    void inorderTraversal(Node* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << root->contact.name << ": " << root->contact.phone << endl;
            inorderTraversal(root->right);
        }
    }

public:
    Phonebook() {
        root = nullptr;
    }

    void addContact(Contact contact) {
        root = insertNode(root, contact);
    }

    void searchContact(string name) {
        Node* result = searchNode(root, name);
        if (result != nullptr) {
            cout << "Contact Found: " << result->contact.name << ": " << result->contact.phone << endl;
        } else {
            cout << "Contact Not Found!" << endl;
        }
    }

    void displayPhonebook() {
        if (root == nullptr) {
            cout << "Phonebook is empty!" << endl;
        } else {
            cout << "--- Phonebook Contacts ---" << endl;
            inorderTraversal(root);
        }
    }
};

int main() {
    Phonebook phonebook;

    Contact contact1;
    contact1.name = "John Doe";
    contact1.phone = "1234567890";
    phonebook.addContact(contact1);

    Contact contact2;
    contact2.name = "Jane Smith";
    contact2.phone = "9876543210";
    phonebook.addContact(contact2);

    Contact contact3;
    contact3.name = "Alice Johnson";
    contact3.phone = "5555555555";
    phonebook.addContact(contact3);

    phonebook.displayPhonebook();

    string searchName;
    cout << "Enter a name to search: ";
    getline(cin, searchName);
    phonebook.searchContact(searchName);

    return 0;
}
