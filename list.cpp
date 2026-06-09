#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node* &head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 🎯 NAYA OPERATION: Linked List mein key search karne ke liye
bool searchKey(Node* head, int key) {
    Node* temp = head; // Shuruat se shuru karenge
    
    while (temp != NULL) {
        if (temp->data == key) {
            return true; // Key mil gayi!
        }
        temp = temp->next; // Agle node par move karein
    }
    return false; // Puri list check kar li, par nahi mili
}

void displayList(Node* head) {
    Node* temp = head;
    cout << "Linked List Chain: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl << endl;
}

int main() {
    cout << "--- DSA Linked List: Searching Masterclass ---" << endl << endl;

    Node* head = NULL;

    // Ek standard list taiyar karte hain
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtHead(head, 5); // Ab list hai: 5 -> 10 -> 20 -> 30 -> NULL
    
    displayList(head);

    // 🔥 TEST 1: Jo element list mein MAJOUD HAI use search karte hain
    int target1 = 20;
    cout << "Searching for element: " << target1 << "..." << endl;
    if (searchKey(head, target1)) {
        cout << "✅ Success: Element " << target1 << " is present in the Linked List!" << endl;
    } else {
        cout << "❌ Error: Element " << target1 << " NOT found." << endl;
    }
    cout << "-----------------------------------------------" << endl << endl;

    // 🔥 TEST 2: Jo element list mein NAHI HAI use search karte hain
    int target2 = 99;
    cout << "Searching for element: " << target2 << "..." << endl;
    if (searchKey(head, target2)) {
        cout << "✅ Success: Element " << target2 << " is present in the Linked List!" << endl;
    } else {
        cout << "❌ Error: Element " << target2 << " NOT found in the system." << endl;
    }

    return 0;
}