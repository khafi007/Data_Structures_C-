#include<iostream>
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
 
class Queue
{
	
    int rear;
	int front;
 
    // Circular Queue
    int size;
    string *arr;
public:
 	Queue(int s);
 	~Queue();
    void enQueue(string val);
    string  deQueue();
    void timestamp();
    void isFull();
    void isEmpty();
};
 
Queue::Queue(int s)
    {
       front = rear = -1;
       size = s;
       arr = new string[s];
    }
Queue::~Queue()
{
	delete arr;
	front == 0;
	rear == 0;
	size = 0;
}

void Queue::enQueue(string val)
{
    if ((front == 0 && rear == size-1) ||
            (rear == (front-1)%(size-1)))
    {
        cout<<"Queue is Full('Can't add more elements')"<<endl;
        return;
    }
 
    else if (front == -1)
    {
        front = rear = 0;
        arr[rear] = val;
    }
 
    else if (rear == size-1 && front != 0)
    {
        rear = 0;
        arr[rear] = val;
    }
 
    else
    {
        rear++;
        arr[rear] = val;
    }
}


string Queue::deQueue()
{
    if (front == -1)
    {
        cout<<"Queue is Empty('Add elements for dequeue')"<<endl;
        //return INT_MIN;
    }
 
    string data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size-1)
        front = 0;
    else
        front++;
 
    return data;
}

void Queue::isEmpty(){
	
	if (front == -1)
    {
        cout<<"Queue is Empty"<<endl;
    }
	else
	cout<<"Queue is not Empty";
	
	
}	
	
	
	
void Queue::isFull(){
	
	if ((front == 0 && rear == size-1) ||
            (rear == (front-1)%(size-1)))
    {
        cout<<"Queue is Full"<<endl;
    }
    else 
    cout<<"Queue is not Full"<<endl;
}

void Queue::timestamp()
{
	cout<<"User is offline(press any key to make user online.)"<<endl;
	getch();
	
    if (front == -1)
    {
        cout<<"Inbox empty (No messages)"<<endl;
        return;
    }
    cout<<"Messages: "<<endl;
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            cout<<arr[i]<<" "<<endl;
    }
    else
    {
        for (int i = front; i < size; i++)
            cout<<arr[i]<<" ";
 
        for (int i = 0; i <= rear; i++)
            cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    Queue q(5);
 
    q.enQueue("message 1");
    q.enQueue("message 2");
    q.enQueue("message 3");
    q.enQueue("message 4");

    q.timestamp();
//    q.dQueue(20);
//    q.isEmpty();
    return 0;
}


