Node* lca(Node* root,int n1, int n2){
	if (root==NULL){
		return NULL;
	}
	if (root->data ==n1, || root->data == n2){
		return root;
	}
	Node* left = lca(root->left, n1,n2);
	Node* right = lca(root->right, n1,n2);

	if (left!=NULL && right!=NULL){
		return root;
	}
		if (left==NULL && right==NULL){
		return NULL;
		}
		if (left!=NULL){
			return lca(root->left,n1.n2);
		}
		return lca(root->right,n1.n2);
}

int findDist(Node *root, int k, int dist) {
	if (root==NULL){
		return;
	}
	if (root->data ==k){
		return dist;
	}
	int left =findDist(root->left,k,dist+1);
	if (left!= -1){
		return left;
	}
	return findDist(root->right,k,dist+1);
}
int distBtwNodes(Node *root, int n1, int n2) {
	Node *lca = lca( root, n1, n2) ;
	int d1 = findDist ( lca, nl, 0);
	int d2 = findDist ( lca, n2, 0);
		return dl+d2;
}

