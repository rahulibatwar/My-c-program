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

// 🎯 FUNCTION: Specific value wale node ko delete karne ke liye
void deleteNode(Node* &head, int val) {
    // Case 0: Agar list pehle se khali hai
    if (head == NULL) {
        cout << "[System Error]: List is empty, cannot delete!" << endl;
        return;
    }

    // Case 1: Agar pehla hi node (Head) delete karna ho
    if (head->data == val) {
        Node* nodeToDelete = head;
        head = head->next; // Head ko agle par shift kiya
        delete nodeToDelete; // Purani memory clean ki
        cout << "[Deleted]: " << val << " from the Head." << endl;
        return;
    }

    // Case 2: Beech ka ya aakhiri node delete karna ho
    Node* temp = head;
    // Hum target node ke theek PEHLE wale node tak traverse karenge
    while (temp->next != NULL && temp->next->data != val) {
        temp = temp->next;
    }

    // Agar value list mein mili hi nahi
    if (temp->next == NULL) {
        cout << "[Notice]: Element " << val << " not found for deletion." << endl;
        return;
    }

    // Link bypass logic
    Node* nodeToDelete = temp->next; // Target node
    temp->next = temp->next->next;   // Target ke agle node se pointer joda
    delete nodeToDelete;             // Memory free ki
    cout << "[Deleted]: " << val << " from the list." << endl;
}

void displayList(Node* head) {
    Node* temp = head;
    cout << "Current Linked List Chain: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    cout << "--- DSA Linked List: Deletion Masterclass ---" << endl << endl;

    Node* head = NULL;

    // Standard list banana: 5 -> 10 -> 20 -> 30
    insertAtTail(head, 5);
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    
    displayList(head);
    cout << "-----------------------------------------------" << endl;

    // 🔥 TEST 1: Beech ka element (20) delete karte hain
    deleteNode(head, 20);
    displayList(head); // Output hona chahiye: 5 -> 10 -> 30 -> NULL
    cout << "-----------------------------------------------" << endl;

    // 🔥 TEST 2: Head element (5) delete karte hain
    deleteNode(head, 5);
    displayList(head); // Output hona chahiye: 10 -> 30 -> NULL

    return 0;
}