#include <iostream>
using namespace std;


struct Node
{
	int data;
	Node *next;
};


class queue
{

	private:
		Node *front;
		Node *rear;
		int size;
	public:
		queue(int s);
		~queue();
		void dQueue();
		void eQueue(int info);
		void display();
};


queue::queue(int s)
{
	front = NULL;
	rear = NULL;
	size = s;
}


queue::~queue()
{
	if (front == NULL)
	{
		return;
	}
	Node *temp = front;
	while(temp != rear)
	{
		front = front->next;
		delete temp;
		temp = front;
	}
	delete front, rear;
}


void queue::dQueue()
{
	if (front == NULL)
	{
		cout<<"underflow"<<endl;
		return;
	}

	if (front == rear)
	{
		Node *temp = front;
		delete temp;
		front = NULL;
		rear = NULL;
		return;
	}
	Node *temp = front;
	front = front->next;
	size++;
	delete temp;
	return;
}

void queue::eQueue(int info)
{
	if (size == 0)
	{
		cout<<"Overflow"<<endl;
		return;
	}
	if (rear == NULL)
	{
		rear = new Node;
		rear->next = NULL;
		rear->data = info;
		front = rear;
		size--;
		return;
	}
	rear->next = new Node;
	rear = rear->next;
	rear->next = NULL;
	rear->data = info;
	size--;
	return;
}

void queue::display()
{
	Node *temp = front;
	while(temp != rear)
	{
		cout<<temp->data;
		temp= temp->next;
	}
	cout<<rear->data<<endl;
}






int main()
{
	queue obj(4);
	obj.dQueue();
	obj.eQueue(5);
	obj.dQueue();
	obj.eQueue(8);
	obj.eQueue(7);
	obj.eQueue(91);
	obj.eQueue(3);
	obj.eQueue(1);

	obj.dQueue();
	obj.dQueue();
	obj.eQueue(6);
	obj.display();


	return 0;
}
