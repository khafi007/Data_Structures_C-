#include<iostream>
using namespace std;



struct Node
{
	int data;
	Node *left, *right;
};


class bst
{
	private:
		Node *temp;
	public:
		Node *root;
		int number;
		bst();
		~bst();
		void find_succesor(int key);
		void in_ord(Node *temp);
		void insert(Node *temp);
		void del(Node *temp);
		void delAll(Node *temp);
		bool Search (Node *root,int data);

};


bst::bst()
{
	temp = root = NULL;
}

bst::~bst()
{
	delAll(root);
}
bool bst::Search (Node *root,int data){
    if(root == NULL){
    return false;
    }
    else if (root -> data == data){
        return true;
}
    else if (data <= root->data){
        return Search(root->left ,data);
 }
    else{
        return Search (root->right, data);
    }

}

void bst::find_succesor(int key){
    Node *temp = Search (number,root);
    Node *succesor = NULL;
    if (temp == NULL){
        return NULL;
    }
    if (temp -> right != NULL){
        temp = temp -> right

    }
    return temp;
}
    else {
        Node *temp2 = root;
        while (temp2 != temp){
            if (temp2 -> value > temp -> value){
                succesor = temp2;
                temp2 = temp2 -> left;
            }
            else{
                temp2 =temp2 ->right;
            }
        }
        return succesor;
}




}

void bst::delAll(Node *temp)
{
	if (temp->left != NULL)
		delAll(temp->left);
	if (temp->right != NULL)
		delAll(temp->right);
	delete temp;
}


void bst:: in_ord(Node *temp)
{
	if (temp == NULL)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}
	if (temp->left != NULL)
	{
		in_ord(temp->left);
	}
	cout<<temp->data<<" ";
	if (temp->right != NULL)
	{
		in_ord(temp->right);
	}
}


void bst::insert(Node *temp)
{

	if (root == NULL)
	{
		temp = new Node;
		temp->data = number;
		temp->right = NULL;
		temp->left = NULL;
		root = temp;
		return;
	}
	if (temp->data == number)
	{
		cout<<"given number already in  tree"<<endl;
		return;
	}
	if (temp->data > number)
	{
		if (temp->left != NULL)
		{
			insert(temp->left);
		}
		else
		{
			Node *temp2 = new Node;
			temp2->data = number;
			temp2->right = NULL;
			temp2->left = NULL;
			temp->left = temp2;
			return;
		}
	}
	if (temp->data < number)
	{
		if (temp->right != NULL)
		{
			insert(temp->right);
		}
		else
		{
			Node *temp2 = new Node;
			temp2->data = number;
			temp2->right = NULL;
			temp2->left = NULL;
			temp->right = temp2;
			return;
		}
	}

}



void bst::del(Node *temp)
{
	if (root == NULL)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}
	if (temp->data == number && temp == root)
	{
		if (temp->left == NULL && temp->right == NULL)
		{
			delete temp;
			root = temp = NULL;
			return;
		}

		if (temp->left != NULL && temp->right == NULL)
		{
			root = temp->left;
			Node *temp2 = temp;
			delete temp2;
			temp = root;
			return;
		}
		if (temp->left == NULL && temp->right != NULL)
		{
			root = temp->right;
			Node *temp2 = temp;
			delete temp2;
			temp = root;
			return;
		}
		if (temp->left != NULL && temp->right != NULL)
		{
			Node *temp2 = temp;
			if (temp->left->right != NULL)
			{
				Node *temp3 = temp;
				temp3 = temp3->left;
				temp2 = temp2->left->right;
				while(temp2->right != NULL)
				{
					temp3 = temp2;
					temp2 = temp2->right;
				}
				if (temp2->left == NULL)
				{
					temp->data = temp2->data;
					delete temp2;
					temp3->right = NULL;
					return;
				}
				if (temp2->left != NULL)
				{
					temp3->right = temp2->left;
					temp->data = temp2->data;
					delete temp2;
					return;
				}

			}
			else
			{
				temp2 = temp->left;
				temp->left = temp2->left;
				temp->data = temp2->data;
				delete temp2;
				temp2 = NULL;
				return;
			}
		}

	}
	if (number < temp->data)
	{
		if (temp->left != NULL)
		{
			if (temp->left->data == number)
			{
				if (temp->left->left == NULL && temp->left->right == NULL)
				{
					delete temp->left;
					temp->left = NULL;
					return;
				}

				if (temp->left->left != NULL && temp->left->right == NULL)
				{
					Node *temp2 = temp->left;
					temp->left = temp->left->left;
					delete temp2;
					temp2 = NULL;
					return;
				}
				if (temp->left->left == NULL && temp->left->right != NULL)
				{
					Node *temp2 = temp->left;
					temp->left = temp->left->right;
					delete temp2;
					temp2 = NULL;
					return;
				}
				if (temp->left->left != NULL && temp->left->right != NULL)
				{
					Node *temp2 = temp;
					if (temp->left->left->right != NULL)
					{
						Node *temp3 = temp;
						temp3 = temp3->left->left;
						temp2 = temp2->left->left->right;
						while(temp2->right != NULL)
						{
							temp3 = temp2;
							temp2 = temp2->right;
						}
						if (temp2->left == NULL)
						{
							temp->left->data = temp2->data;
							delete temp2;
							temp3->right = NULL;
							return;
						}
						if (temp2->left != NULL)
						{
							temp3->right = temp2->left;
							temp->left->data = temp2->data;
							delete temp2;
							return;
						}

					}
					else
					{
						temp2 = temp->left;
						temp->left = temp2->left;
						temp->left->right = temp2->right;
						delete temp2;
						temp2 = NULL;
						return;
					}

				}

			}
			del(temp->left);
			return;
		}
	}
	if (number > temp->data)
	{
		if (temp->right != NULL)
		{
			if (temp->right->data == number)
			{
				if (temp->right->left == NULL && temp->right->right == NULL)
				{
					delete temp->right;
					temp->right = NULL;
					return;
				}

				if (temp->right->left != NULL && temp->right->right == NULL)
				{
					Node *temp2 = temp->right;
					temp->right = temp->right->left;
					delete temp2;
					temp2 = NULL;
					return;
				}
				if (temp->right->left == NULL && temp->right->right != NULL)
				{
					Node *temp2 = temp->right;
					temp->right = temp->right->right;
					delete temp2;
					temp2 = NULL;
					return;
				}
				if (temp->right->left != NULL && temp->right->right != NULL)
				{
					Node *temp2 = temp;
					if (temp->right->right->left != NULL)
					{
						Node *temp3 = temp;
						temp3 = temp3->right->right;
						temp2 = temp2->right->right->left;
						while(temp2->left != NULL)
						{
							temp3 = temp2;
							temp2 = temp2->left;
						}
						if (temp2->right == NULL)
						{
							temp->right->data = temp2->data;
							delete temp2;
							temp3->left = NULL;
							return;
						}
						if (temp->right != NULL)
						{
							temp3->left = temp2->right;
							temp->right->data = temp2->data;
							delete temp2;
							return;
						}

					}
					else
					{
						temp2 = temp->right;
						temp->right = temp2->right;
						temp->right->left = temp2->left;
						delete temp2;
						temp2 = NULL;
						return;
					}

				}

			}
			del(temp->right);
			return;
		}
	}
}







int main()
{

	bst obj;
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
	obj.number = 8;
	obj.insert(obj.root);
	obj.number = 14;
	obj.insert(obj.root);
	obj.in_ord(obj.root);
	cout<<endl;
	obj.number = 40;
	obj.del(obj.root);
	cout<<endl;
	//obj.in_ord(obj.root);
	// cout<<endl;
	// obj.number = 70;
	// obj.del(obj.root);
	obj.in_ord(obj.root);
	cout<<endl;
	obj.number = 70;
	obj.del(obj.root);
	cout<<endl;
    // obj.number = 20;
	// obj.insert(obj.root);
	obj.in_ord(obj.root);
	cout<<endl;
	obj.number= 7;
	cout<<endl;
	obj.insert(obj.root);
	//obj.in_ord(obj.root);
	return 0;
}
