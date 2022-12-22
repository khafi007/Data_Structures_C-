int calcheight(Node* root){
	if (root == NULL){
		return;
	}
	int lheight = calcheight(root->left);
	int rheight = calcheight(root->right);
	return max(lheight,rheight) + 1;
	
}
