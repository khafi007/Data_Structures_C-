void leftview (Node* root) {
if(root == NULL) {
return;
}
queue <Node*> q
q.push(root);
q.push(NULL);
while(!q. empty ()) {
		int n=q.size();
		for (int=0;i<n;i++){
			Node* temp= q.front();
			q.pop();
			
			if (i == 1){
				cout<<curr->data<<" ";
			}
			if (temp->left!= NULL){
				q.push(temp->left);
			}
			if (temp->right!= NULL){
				q.push(temp->right);
			}
		}
		
	}
}
