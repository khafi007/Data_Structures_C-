#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//structure declaration 
struct Node{
  int data;
  Node* left;
  Node* right;
};
//create function
Node* create(int x){
  Node* temp=(Node*)malloc(sizeof(Node));
  temp->data=x;
  temp->left=NULL;
  temp->right=NULL;
}
//function to build balanced BST from a sorted array
Node* buildBalancedBST(int arr[],int begin,int last){
  if(begin>last)return NULL;
  int middle=(begin+last)/2;
  Node* temp=create(arr[middle]);
  //divide the array in left subtree and right subtree from middle
  temp->left=buildBalancedBST(arr,begin,middle-1);
  temp->right=buildBalancedBST(arr,middle+1,last);
  return temp;
}
//inorder traversal of balanced BST
void inorder(Node* root){
  if(root==NULL)return;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}
//main function
int main(){
  int Sortedarr[]={1,2,3,4,5,6,7};
  //return a root node
  Node* root=buildBalancedBST(Sortedarr,0,6);
  cout<<" inorder traveral of the balanced BST is: ";
  inorder(root);
}
