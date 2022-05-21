#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

};

class linklist {
private:
    Node *head;
    Node *tail;
    Node *temp;
    Node *temp1;


public:
    linklist();
    ~linklist();
    add_to_start(int key);
    add_any_point(int value,int key1);
    showlist();



};
linklist::linklist(){
    head = NULL;
    tail = NULL;


}
linklist::~linklist(){
    delete head;

}
linklist::add_to_start(int key){
    Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;
    if (head == NULL){
		head = temp;
		tail = temp;
	}
	else
	{
		temp->next = head;
		head = temp;

    }
}
linklist::add_any_point(int value,int key){
    if (head != NULL){
    temp = head;
    }
    while (temp != NULL){
    if (temp -> data == value){
            if(head->data == value)
		{
			Node *temp = new Node;
			temp->next = NULL;
			temp->data = key;
			head ->next = temp;
			tail = temp;
		}
	}
	else
	{
		Node *query;
		query = head;
		while(query != NULL)
		{
			if(query->next == tail->next && query->data == value)
			{
				Node *temp = new Node;
				temp->data = key;
				temp->next = NULL;
				tail->next = temp;
				tail = temp;
				//return;
			}
			else if(query->data == value)
			{
				Node *temp = new Node;
				temp->data = key;
				temp->next = query->next;
				query->next = temp;
				//return;
			}
			query = query->next;
		}
	}
}

linklist::showlist(){
    if (head == NULL){
        cout<<"Empty list"<<endl;
    }
    else{
            Node *temp;
    temp = head;
    while (temp != NULL){
        cout<<temp->data;
        temp =temp->next;
          }
    }
}
int main(){
    linklist l;
        l.add_to_start(3);
        l.showlist();
        l.add_any_point(2,4);
        l.showlist();


}
