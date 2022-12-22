void rightview(Node* root) {
if(root == NULL) {
return;
}
queue <Node*> q
q.push(root);
q.push(NULL);
while(!q. empty ()) {
		int n=q.size();
		for (int=0;i<n;i++){
			Node* curr= q.front();
			q.pop();
			
			if (i == n-1){
				cout<<curr->data<<" ";
			}
			if (curr->left!= NULL){
				q.push(curr->left);
			}
			if (curr->right!= NULL){
				q.push(curr->right);
			}
		}
		
	}
}
