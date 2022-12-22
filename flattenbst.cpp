void flatten(Treenode * root) {
  Treenode * curr = root;
  while (curr != NULL) {
    if (curr - > left != NULL) {
      Treenode * prev = curr - > left;
      while (prev - > right)
        prev = prev - > right;
      prev - > right = curr - > right;
      curr - > right = curr - > left;
      curr - > left = NULL;
    }
    curr = curr - > right;
  }
}

//recursion
Treenode * prev = NULL;

//void flatten(Treenode * root) {
//  if (!root)
//    return;
//  flatten(root - > right);
//  flatten(root - > left);
//
//  root - > right = prev;
//  root - > left = NULL;
//  prev = root;
//}
