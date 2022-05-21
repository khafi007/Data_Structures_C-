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
		string convert_infix_to_postfix(string infix_exp,string postfix);
		bool Is_operator(char c);
		bool Is_operand(char c);
		int precedence(char op);
		bool eql_or_higher (char op1, char op2);
		string convert_postfix_to_infix(string postfix, string infix);
				
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
bool stack::Is_operator(char c)  
{  
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' )  
		return true;     
		return false;  
}  
  
// IsOperand() function is used to validate whether the character is operand.  
bool stack::Is_operand(char c)  
{  
	if( c >= 'A' && c <= 'Z')   
	return true;  
	
	if (c >= 'a' && c <= 'z')  
	return true;  
	
	if(c >= '0' && c <= '9')   
	return true;  
	
	return false;  
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
int stack::precedence(char op)  
{  										//rank of the operator::precenedence
	if(op == '+' || op == '-')                   /* it defines the lowest precedence */  
		return 1;  
	if (op == '*' || op == '/')  
		return 2;  
	if(op == '^')                                  //square has the highest precedence 
	return 3;       
	
	return 0; 
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
bool stack::eql_or_higher (char op1, char op2)  
{  
	int p1 = precedence(op1);	// This function is used to check the whether the precedence
	int p2 = precedence(op2);	//of the two operators is higher or equal in infix expression.  

	if (p1 == p2)  
	{  
		if (op1 == '^' )  
			return false;  
		
		return true;  
}  
	return  (p1>p2 ? true : false);  
}  
string stack::convert_infix_to_postfix(string infix_exp,string postfix)  
{  
	stack s1(20);    
	char ch;  
	s1.push( '(' );  
	infix_exp += ')';  
	for(int i = 0; i<infix_exp.length(); i++)  
	{  
	ch = infix_exp[i];  
	if(ch == ' ')  
	continue;  
	else if(ch == '(')  
	s1.push(ch);  
	else if(Is_operand(ch))  
	postfix += ch;  
	else if(Is_operator(ch))  
	{  
	while(!s1.is_empty() && eql_or_higher(s1.top_value(), ch))  
	{  
		postfix += s1.top_value();  
		s1.pop();  
	}  
		s1.push(ch);  
	}  
	else if(ch == ')')  
	{  
	while(!s1.is_empty() && s1.top_value() != '(')  
	{  
		postfix += s1.top_value();  
		s1.pop();  
		}  
		s1.pop();  
		}  
	}  
	return postfix;  
}
string stack::convert_postfix_to_infix(string postfix,string infix)  
{  
	stack S2(20);   
	char ch;  
  
	S2.push( '(' );  
	postfix += ')';  
  
	for(int i = 0; i<postfix.length(); i++)  
	{  
		ch = postfix[i];  
  
		if(ch == ' ')  
		continue;  
		else if(ch == '(')  
		S2.push(ch);  
		else if(Is_operand(ch))  
		infix += ch;  
		else if(Is_operator(ch))  
	{  
	while(!S2.is_empty() && eql_or_higher(S2.top_value(), ch))  
		{  
		infix += S2.top_value();  
		S2.pop();  
	}	  
		S2.push(ch);  
	}  
	else if(ch == ')')  
		{  
			while(!S2.is_empty() && S2.top_value() != '(')  
		
		{  
			infix += S2.top_value();  
			S2.pop();  
		
		}  
		
		S2.pop();  
		}  
		}  

	return infix;  

}  


int main()
{
	stack s(20);
	string infix_exp = "a+b*(c^d-e)^(f+g*h)-I";
	string postfix = " ";
    string infix = " ";
    cout<<"Infix to Postfix conversion: "<<s.convert_infix_to_postfix(infix_exp,postfix)<<endl;
    cout<<"Postfix to infix conversion: "<<s.convert_postfix_to_infix(postfix,infix)<<endl;
    
    
}

