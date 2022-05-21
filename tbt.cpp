#include<iostream>
using namespace std;



struct Node
{
	int data;
	int lCh;
	int rCh;
	Node *left, *right;
};


class tbt
{
	private:
		Node *temp;
	public:
		Node *root;
		Node *dummy;
		int number;
		int flag;
		tbt();
		~tbt();


		void fastInOrder(Node *temp);
		Node* nextInOrder(Node *temp);
		void insert(Node *temp);
		void deleete(int key, Node *temp);
		void delete_node(Node *temp,Node *parent);
		void find_succesor(Node *temp,Node *successor_parent);
};


tbt::tbt()
{
	flag = 0;
	dummy = new Node;
    temp = new Node;
    temp->data = number;
    temp->right = dummy;
    temp->left = dummy;
    root = temp;
    root->lCh = 0;
    root->rCh = 0;
    flag = 1;
    dummy->left = root;
    dummy->right = dummy;
    dummy->lCh = 1;
    dummy->rCh = 1;
}

tbt::~tbt()
{
	delete dummy;
	delete root;
}



void tbt:: fastInOrder(Node *temp)
{

	while((temp=nextInOrder(temp)) != dummy)
	{
		cout<<temp->data<<" ";
	}
	cout<<endl;
}


Node* tbt:: nextInOrder(Node *temp)
{
	if (temp->rCh == 0)
	{
		return temp->right;
	}
	else
	{
		temp= temp->right;
		while(temp->lCh == 1)
			temp = temp->left;
		return temp;
	}
}





void tbt::insert(Node *temp)
{

	if (flag == 0)
	{
		temp = new Node;
		temp->data = number;
		temp->right = dummy;
		temp->left = dummy;
		root = temp;
		root->lCh = 0;
		root->rCh = 0;
		flag = 1;
		dummy->left = root;
		dummy->right = dummy;
		dummy->lCh = 1;
		dummy->rCh = 1;

		return;
	}
	if (temp->data == number)
	{
		cout<<"given number already in  tree"<<endl;
		return;
	}
	if (temp->data > number)
	{
		if (temp->lCh != 0)
		{
			insert(temp->left);
		}
		else
		{
			Node *temp2 = new Node;
			temp2->data = number;
			temp->lCh = 1;
			if (temp == root)
			{
				temp2->right = temp;
				temp2->left = dummy;
				temp2->rCh = 0;
				temp2->lCh = 0;
				temp->left = temp2;
			}
			else
			{
				temp2->left = temp->left;
				temp2->right = temp;
				temp2->rCh = 0;
				temp2->lCh = 0;
				temp->left = temp2;
			}
			return;
		}
	}
	if (temp->data < number)
	{
		if (temp->rCh != 0)
		{
			insert(temp->right);
		}
		else
		{
			Node *temp2 = new Node;
			temp2->data = number;
			temp->rCh = 1;
			if (temp == root)
			{
				temp2->right = dummy;
				temp2->left = temp;
				temp2->rCh = 0;
				temp2->lCh = 0;
				temp->right = temp2;
			}
			else
			{
				temp2->left = temp;
				temp2->right = temp->right;
				temp2->rCh = 0;
				temp2->lCh = 0;
				temp->right = temp2;
			}
			return;
		}
	}

}
void deleete(int key,Node *temmp){

	if(root == NULL){
		cout<<"Tree is Empty";
		return;
	}

	if (temp -> left-> data == key){
	delete_node(temp -> left,temp);
	return;
	}

	if ((temp != dummy) && (temp->right->data == key)){

	delete_node(temp->right,temp);
	return;
	}
	if (temp == dummy){
	delete_node(temp->right,temp);
	return
	}

	if((key > temp->data) && (temp->rightbit == 1)){

	delete_node(key,temp->left);
	return;

	}
	if ((key< temp->value) && (temp ->leftbit == 1)){

	delete_node(key,temp->left);
	return;

	}
	cout<<"value doesnt exist";
	return;
}

void delete_node(temp, parent){

	if ((temp ->leftbit == 1) && (temp->rightbit == 1)){
	Node *successor_parent = temp;
	Node *successor = find_succesor(temp->right,successor_parent);
	temp->value = succesor->value;
	delete_node(successor,successor_parent);
	return;
	}
	if ((temp->leftbit == 1) && (temp->rightbit == 0)){
		if (temp->vale < parent->value){
		parent->left = temp_left;
		parent->leftbit = temp->leftbit;
		parent->right = temp->left;
		parent->rightbit = temp->leftbit;
		}
	Node *temp2=temp->left;
	while(temp2->rightbit != 0){
		temp2=temp2->right;
		}
	temp2->right = temp->right;
	delete temp;
	return;
	if ((temp->leftbit == 0) && (temp->rightbit == 0)){
		if (parent ->left == temp){
			parent ->left = temp->left;
			parent->leftbit = 0;
			}
		if ((parent->right == temp) && (parent != dummy)){
			parent ->right = temp->right;
			parent->rightbit = 0;
			}
		if (temp == root){
			root = NULL;
			dummy->left = dummy;
			dummy->leftbit = 0;
			delete temp;
			return;
			}
		}
	}
}

void find_successor(temp,successor_parent){
	if (temp->leftbit = 1){
		return temp;
	}
	parent = temp;
	return find_successor(temp->left,parent)
}




int main()
{

	tbt obj;
	obj.number = 70;
	obj.insert(obj.root);
	obj.number = 150;
	obj.insert(obj.root);
	obj.number = 22;
	obj.insert(obj.root);
	obj.number = 10;
	obj.insert(obj.root);
	obj.number = 30;
	obj.insert(obj.root);
	obj.number = 12;
	obj.insert(obj.root);
	obj.number = 40;
	obj.insert(obj.root);
	obj.number = 7;
	obj.insert(obj.root);
	obj.number = 3;
	obj.insert(obj.root);
	obj.fastInOrder(obj.dummy);
	// obj.number = 70;
	// obj.del(obj.root);
	obj.fastInOrder(obj.dummy);
	// obj.number = 14;
	// obj.insert(obj.root);
	// obj.pre_ord(obj.root);
	// cout<<endl;
	// obj.in_ord(obj.root);
	// cout<<endl;
	// obj.post_ord(obj.root);
	// cout<<endl;
	// obj.number = 40;
	// obj.del(obj.root);
	// cout<<endl;
	// obj.in_ord(obj.root);
	// cout<<endl;
	obj.number = 70;
	obj.insert(obj.root);
	// obj.in_ord(obj.root);
	// cout<<endl;
	// obj.number = 20;
	// obj.insert(obj.root);
	// obj.in_ord(obj.root);
	// cout<<endl;
	return 0;
}
