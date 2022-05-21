#include<iostream>
using namespace std;


class Node{
	public:
		int data;
		Node *left;
		Node *right;
		Node(int data){
			this->data=data;
			left = right = NULL;
		}

};

class bst{
	public:
		Node *root;
		bst(){
			root = NULL;
		}
		Node *Insert(Node *root,int val);
		void remove(Node *root,int val);


		void Inorder(Node *root);
		void Preorder(Node *root);
		void Postorder(Node *root);
	
	
};

Node *bst::Insert(Node *r, int val)
{
	if (r == NULL){
		Node *t = new Node(val);
		if(r == root){
			root=r=t;
		}
		else{
		r = t;
		}
		return r;
		}
	else if (val == r->data){
		cout<<"Duplicate data: "<<val<<endl;
	}
	else if (val< r->data){
		r->left =Insert(r->left,val);
	}
	else if (val> r->data){
		r->right = Insert(r->right,val);
	}
}

void bst::Inorder(Node *r)
{
	if (r == NULL)
		return;
	Inorder(r->left);
	cout<<r->data<<" -> ";
	Inorder(r->right);
	
	
}

void bst::Preorder(Node *r)
{
	if (r == NULL)
		return;
	cout<<r->data<<" -> ";
	Inorder(r->left);
	Inorder(r->right);
	
}

void bst::Postorder(Node *r)
{
	if (r == NULL)
		return;
	Inorder(r->left);
	Inorder(r->right);
	cout<<r->data<<" -> ";
}



int main()
{
	bst obj;
	obj.Insert(obj.root,8);
	obj.Insert(obj.root,3);
	obj.Insert(obj.root,10);
	obj.Insert(obj.root,12);
	cout<<"Inorder Traversal: ";
	obj.Inorder(obj.root);
	cout<<endl<<"Preorder Traversal: ";
	obj.Preorder(obj.root);
	cout<<endl<<"Postorder Traversal: ";
	obj.Postorder(obj.root);
	return 0;
}
