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
		int postfix(string exp);
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
//cout<<"hello";

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
int stack::postfix(string exp)
{
 
    stack s1(20);

    for(int i = 0; i < exp.length(); i++) {
        char c = exp[i];
 
        if(c >= '0' && c <= '9')		//operand check
            s1.push(c-'0');
        							
        							
        //IF OPERATOR
        else if (c=='+'){		//Addition
            int a,b,c;
            a= s1.top_value();		//we pop the top two elements from the stack
            s1.pop();				// and save them in two integers vars
            b= s1.top_value();
            s1.pop();
            c= b+a;					//Perform mathematical operation accordingly using third int var. 	
            s1.push(c);
            
        }
        else if (c=='-'){		//Subtraction
            int a,b,c;
            a= s1.top_value();
            s1.pop();
            b= s1.top_value();
            s1.pop();
            c= b-a;
            s1.push(c);
        }
          else if (c=='*'){		//Multipication
            int a,b,c;
            a= s1.top_value();
            s1.pop();
            b=s1.top_value();
            s1.pop();
            c= b*a;
            s1.push(c);
        }
          else if (c=='/'){		//division
            int a,b,c;
            a= s1.top_value();
            s1.pop();
            b= s1.top_value();
            s1.pop();
            c= b/a;
            s1.push(c);
        }
          else if (c=='^'){		//Power
            char a,b,res;
            a= s1.top_value();
            s1.pop();
            b= s1.top_value();
            s1.pop();
            s1.push(pow(b,a));
        }
        
    }
    return s1.top_value();
}
int main()
{
	stack s1(20);
    string exp = "343+-622/+*2^3+";
    cout<<"Answer of equation: "<<s1.postfix(exp)<<endl;
    
    return 0;
}




    
