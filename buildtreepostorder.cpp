Node* buildTree (int postorder [], int inorder[], int start, int end) {
static int idx =4;
if(start > end){
	return NULL:|
}
int val = postorder [idx] ;
idx--;
Node* curr = new Node (val) ;
if(start = end) {
	return curr;
}
int pos = search(inorder, start, end, val);
curr->right = buildTree(postorder,inorder, pos+1,end) ;
Curr-left = buildTree(postorder,inorder.start.Dos-1:
return curr;
}

int search(int inorder[],int start, int end, int val)
for(int i=start; i<=end ; i++) {
	if(inorder [il == val) {
			return i;
		}
	return -1;
}
inorderPrint(Node *root){
	if (root==NULL)
		return;
	inorderPrint( root->left);
		cout < root->data;
	inorderPrint(root->right);
}
int main( ){
int postorder [] = {4, 2, 5, 3, 1};
int inorder [] = {4, 2, 1, 5, 3;
//build tree
Nodex root
buildTree (posto rder, inorder, 0, 4);
inorderPrint ( root)
cout < "\n":||
return 0;
}
