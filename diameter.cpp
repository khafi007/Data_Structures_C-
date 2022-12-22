int findDiameter(Node* root){
  if(root==NULL)return 0;
  int lh=height(root->left);
  int rh=height(root->right);
  int ld=findDiameter(root->left);
  int rd=findDiameter(root->right);
  return max(lh+rh+1,max(ld,rd));
}
