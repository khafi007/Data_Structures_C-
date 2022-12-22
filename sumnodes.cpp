int sumNodes(Node* root){
	if (root == NULL){
		return;
	}
	return sumNodes(root->left) = sumNodes(root->right) + root->data;
	
}
