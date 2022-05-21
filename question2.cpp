#include <iostream>
#include<math.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
};


class stack
{
	private:
		Node *top;
		int size;
	public:
		stack(int s);
		~stack();
		void push(int info);
		void pop();	
		void display();
		int top_value();
		bool is_empty();
		bool brackets_check(string exp);
};



stack::stack(int s)
{
	top = NULL;
	size = s;
}



stack::~stack()
{
	Node *temp = top;
	while(temp != NULL)
	{
		top = temp;
		temp = temp->next;
		delete top;
	}
	delete temp;
}



void stack::push(int info)
{
	if (size == 0)
	{
		cout<<"Stack Overflow"<<endl;
		return;
	}	
	Node *temp = new Node; 
	temp->next = top;
	temp->data = info;
	top = temp;
	size--;
}

void stack::pop()
{
	
	if (top == NULL)
	{
		cout<<"Stack Underflow"<<endl;
		return;
	}
	Node *temp = top;
	top = top->next;
	size++;
	delete temp;
}

int stack::top_value()
{
         return top->data;
        
}
bool stack::is_empty()
{
        if (size==0)
            return true;
        return false;      
}


void stack::display()
{
	Node *temp = top;
	while(temp != NULL)
	{
		cout<<temp->data<<endl;
		temp = temp->next;
	}
}
bool stack::brackets_check(string exp){
    stack s1(20);
    char x;
    for (int i = 0; i < exp.length(); i++)
    		//Push on stack if opening brackets
	{
        if (exp[i] == '(' || exp[i] == '['
            || exp[i] == '{')
        {
            s1.push(exp[i]);   
        }
        //if closing bracket then
        //check if the stack is empty then return false or
        //pop the top most element from the stack
        //and compare them.
    
        switch (exp[i]) {
        case ')':
            x = s1.top_value();
            s1.pop();
            if (x == '{' || x == '[')
                return false;
            break;
 
        case '}':
            x = s1.top_value();
            s1.pop();
            if (x == '(' || x == '[')
                return false;
            break;
 
        case ']':
            x = s1.top_value();
            s1.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }

    return (s1.is_empty());
}

int main()
{
	stack s1(20);
	if (s1.brackets_check("(54+9)+((4*2){"))
        cout << "Equation Balanced"<<endl;
    else
        cout << "Equation Not Balanced"<<endl;
    return 0;
}
