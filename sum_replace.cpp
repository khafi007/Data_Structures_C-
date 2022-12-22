void sumReplace (Node* root) {
if(root == NULL) {
return;
}
sumReplace( root->left);
sumReplace ( root->right);
if(root->left != NULL) {
root->data += root->left->data
}
if(root->right != NULL) {
root->data += root->right->data;
}
}
