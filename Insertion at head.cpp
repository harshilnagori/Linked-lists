//Harshil Nagori
//24070123046
//CODE:

#include <iostream>
using namespace std;

// Node class for linked list
class Link {
    public:
    int data;
    Link* next;

    // Constructor
    Link(int num) {
        data = num;
        next = NULL;
    }
};

// Insert a new node at the head
void insert_head(Link* &head, int data) {
    Link* new_node = new Link(data);   // create new node
    new_node->next = head;             // link to current head
    head = new_node;                   // update head
}

// Display linked list
void disp(Link* head) {
    Link* temp = head;  // traversal pointer
    while (temp != NULL) {
        cout << temp->data << " --> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Link* head = NULL;  // start with empty list

    // Insert elements at head and show list
    insert_head(head, 30);
    disp(head);

    insert_head(head, 32);
    disp(head);

    insert_head(head, 35);
    disp(head);

    return 0;
}

//OUTPUT:
//30 --> NULL
//32 --> 30 --> NULL
//35 --> 32 --> 30 --> NULL
