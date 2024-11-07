#include <bits/stdc++.h>
using namespace std;
class Deque
{
    private:
      int *arr;
      int n;
      int front; 
      int rear;
    public:
      Deque(int size) 
      {
          n = size;
          arr = new int[size];
          front = -1;
          rear = -1;
      }
    void pushFront(int val) 
    {
      if(front == 0) 
      {
        cout << "Overflow" << endl;
      }
      else if(front == -1 && rear == -1) 
      {
        front++;
        rear++;
        arr[front] = val;
      }
      else 
      {
        front--;
        arr[front] = val;
      }
    }
    void popBack() 
    {
      if(front == -1 && rear == -1) 
      {
        cout << "Underflow" << endl;
      }
      else if(front == rear) {
        arr[rear] = -1;
        front = -1;
        rear = -1;
      }
      else {
        arr[rear] = -1;
        rear--;
      }
    }
    void pushBack(int val) {
      if(rear == n-1) 
      {
        cout << "Overflow" << endl;
      }
      else if(front==-1 && rear == -1) 
      {
        rear++;
        front++;
        arr[rear]= val;
      }
      else {
        rear++;
        arr[rear] = val;
      }
    }
    void popFront() {
      if(front==-1 && rear==-1) 
      {
        cout << "Underflow" << endl;
      }
      else if(front == rear) 
      {
        //single element
        arr[front] = -1;
        front = -1;
        rear = -1;
      }
      else {
        arr[front] = -1;
        front++;
      }
    }
    void print() 
    {
      for(int i=0; i<n; i++) 
      {
        cout << arr[i] << " ";
      }cout << endl;
    }
};



int main() 
{
  Deque dq(5);
  dq.pushFront(10);
  dq.print();
  dq.pushFront(20);
  dq.print();
  dq.pushBack(15);
  dq.print();
  dq.pushBack(35);
  dq.print();
  dq.pushFront(100);
  dq.print();
  dq.popFront();
  dq.print();
  dq.popFront();
  dq.print();
  cout<<"check"<<endl; 
  dq.popFront();
  dq.print();
  dq.pushFront(100);
  dq.print();
  dq.popFront();
  dq.print();
  // dq.popBack();
  // dq.print();
  // dq.popBack();
  // dq.print();
  // dq.popBack();
  // dq.print();
  // dq.popBack();
  // dq.print();
  return 0;
}