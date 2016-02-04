// https://www.hackerrank.com/challenges/tree-preorder-traversal

void Preorder(node *root) {
    
    printf("%d ", root -> data);
    if(root -> left != NULL)
        Preorder(root -> left);
    if (root -> right != NULL)
        Preorder(root -> right); 

}
