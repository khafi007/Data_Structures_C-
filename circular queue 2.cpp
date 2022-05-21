#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
class Queue
{
	
    int rear;
	int front;
 
    // Circular Queue
    int size;
    int *arr;
public:
 	Queue(int s);
 	~Queue();
    void enQueue(int val);
    int  deQueue();
    void isFull();
    void isEmpty();
};
 
Queue::Queue(int s)
    {
       front = rear = -1;
       size = s;
       arr = new int[s];
    }
Queue::~Queue()
{
	delete arr;
	front == 0;
	rear == 0;
	size = 0;
}

void Queue::enQueue(int val)
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


int Queue::deQueue()
{
    if (front == -1)
    {
        cout<<"Queue is Empty('Add elements for dequeue')"<<endl;
        return INT_MIN;
    }
 
    int data = arr[front];
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

 


int main()
{
    Queue q(5);
 
    q.enQueue(14);
    q.enQueue(22);
    q.enQueue(13);
    q.enQueue(-6);
 	//q.deQueue();
    cout<<"Deleted value = "<<q.deQueue()<<endl;
    cout<<"Deleted value = "<<q.deQueue()<<endl;
 
 
    q.enQueue(9);
    q.enQueue(20);
 
    q.enQueue(5);
    q.enQueue(20);
    q.isEmpty();
    return 0;
}
