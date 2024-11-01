#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node * next;
    Node(int value)
    {
        data=value;
        next=NULL;    
    }
};
Node * Headinsertion(int value,Node* &head,Node* &tail)
{
    if(head==NULL && tail==NULL)
    {
        Node* newnode=new Node(value);
        head=newnode;
        tail=newnode;
    }
    else
    {
        Node* newnode=new Node(value);
        newnode->next=head;
        head=newnode;
    }
    return head;
}
Node * Tailinsertion(int value,Node* &head,Node* &tail)
{
    if(head==NULL && tail==NULL)
    {
        Node* newnode=new Node(value);
        head=newnode;
        tail=newnode;
    }
    else
    {
        Node* newnode=new Node(value);
        tail->next=newnode;
        tail=newnode;
    }
    return tail;
}
void print(Node * &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl<<endl;
}
Node* findMid(Node* head) {
    Node* slow = head;
    Node* fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next; 
    }
    return slow;
}

Node* merge(Node* left, Node* right) {
    
    if(left == NULL)
        return right;
    
    if(right == NULL)
        return left;
    
    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left != NULL && right != NULL) {
        if(left -> data < right -> data ) {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else
        {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    
    while(left != NULL) {
        temp -> next = left;
        temp = left;
        left = left -> next;
    }
    
    while(right != NULL) {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    
    ans = ans -> next;
    return ans;
    
}


Node* mergeSort(Node *head) {
    //base case
    if( head == NULL || head -> next == NULL ) {
        return head;
    }
    
    // break linked list into 2 halvs, after finding mid
    Node* mid = findMid(head);
    
    Node* left = head;
    Node* right = mid->next;
    mid -> next = NULL;
    
    //recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);
    
    //merge both left and right halves
    Node* result = merge(left, right);
    
    return result;
}
int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    Headinsertion(2,head,tail);
    Headinsertion(3,head,tail);
    Headinsertion(1,head,tail);
    Headinsertion(4,head,tail);
    Headinsertion(6,head,tail);
    Headinsertion(5,head,tail);
    print(head);
    head=mergeSort(head);
    print(head);
}
