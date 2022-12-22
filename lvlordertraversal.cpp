void printLevelOrder (Node* root) {
if(root == NULL) {
return;
}
queue <Node*> q
q.push(root);
q.push(NULL);
while(!q. empty ()) {
	Node* node = q.front () ;
	q.pop();
	if(node != NULL){
		Node* node = q.front();
		if (node!- NULL){
			cout<<node->data<<" ";
		if (node->left)
			q.push(node->left);
		if (node->right)
			q.push(node->right);
		}
	else if (!q.empty())
		q.push(NULL);
	}
	}
}
