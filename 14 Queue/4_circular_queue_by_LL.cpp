#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* next;
    int data;
    Node(int d) {
        next = NULL;
        data = d;
    }
};
class Queue{
    Node* front;
    Node* back;
    public:
    Queue()
    {
        front=NULL;
        back=NULL;
    }
    void Hinsertion(int val) 
    {
        Node* n = new Node(val);
        if (front == NULL) {
            front=n;
            front->next=front;
            back=front;
            return;
        }
        back->next = n;
        n->next=front;
        back= n;
    }
void Tinsertion( int val) {
    if (front == NULL) {
        Hinsertion(val);
        return; // Return after inserting the first element
    }
    Node* n = new Node(val);
    Node* temp = front;
    while (temp->next != front) {
        temp = temp->next;
    }
    temp->next = n;
    n->next = front;
}
void deletion(int pos) {
    if (front == NULL) return; // Check if list is empty

    if (pos == 1) {
        Node* temp = front;
        if (front->next == front) 
        {
            delete front;
            front = NULL;
        } 
        else 
        {
            while (temp->next != front) 
            {
                temp = temp->next;
            }
            Node* todelete = front;
            temp->next = front->next;
            front = front->next;
            delete todelete;
        }
        return;
    }

    Node* temp = front;
    int k = 1;
    while (k < pos - 1 && temp->next != front) {
        temp = temp->next;
        k++;
    }
    if (temp->next == front) return; // If position is out of bounds

    Node* todelete = temp->next;
    temp->next = todelete->next;
    delete todelete;
}

void display() {
    if (front == NULL) return;

    Node* temp = front;
    do {
        cout << temp->data << "   ";
        temp = temp->next;
    } while (temp != front);
    cout << endl;
}

};

int main() {
    

    Queue q;
    q.Hinsertion(100);
    q.display();
    q.Tinsertion(200);
    q.display();
    q.Tinsertion(300);
    q.display();
    q.deletion(2);
    q.display();

    return 0;
}
