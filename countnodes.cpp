int countNodes(Node* root){
	if (root == NULL){
		return;
	}
	return countNodes(root->left) + countNodes(root->right) + 1;
	
}
