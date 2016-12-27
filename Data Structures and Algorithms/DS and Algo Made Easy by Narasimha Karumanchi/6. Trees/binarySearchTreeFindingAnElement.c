#include <stdio.h>
#include <stdlib.h>

typedef struct BinarySearchTreeNode {
    int data;
    struct BinarySearchTreeNode *left;
    struct BinarySearchTreeNode *right;
} BinarySearchTreeNode;

char* recursiveFind(BinarySearchTreeNode *root, int data);
//char* nonRecursiveFind(BinarySearchTreeNode *root, int data);
void printBinarySearchTreeSorted(BinarySearchTreeNode *root);

int main() {

    // Creating a binary search tree manually
    BinarySearchTreeNode *root = (BinarySearchTreeNode*)malloc(sizeof(BinarySearchTreeNode));
    
    root->data = 10;
    root->left =  (BinarySearchTreeNode*)malloc(sizeof(BinarySearchTreeNode));
    root->right = (BinarySearchTreeNode*)malloc(sizeof(BinarySearchTreeNode));
    BinarySearchTreeNode *no2 = root->left;
    BinarySearchTreeNode *no3 = root->right;

    no2->left = (BinarySearchTreeNode*)malloc(sizeof(BinarySearchTreeNode));
    no2->right = (BinarySearchTreeNode*)malloc(sizeof(BinarySearchTreeNode));
    no2->data = 6;
    BinarySearchTreeNode *no4 = no2->left;
    BinarySearchTreeNode *no5 = no2->right;

    no3->data = 16;
    no3->right = NULL;
    no3->left = (BinarySearchTreeNode*)malloc(sizeof(BinarySearchTreeNode));
    BinarySearchTreeNode *no6 = no3->left;

    no4->data = 4; no5->data = 9; no6-> data = 13;
    no4->left = NULL; no4->right = NULL;
    no5->left = NULL; no5->right = NULL;
    no6->left = NULL; no6->right = NULL;


    // Actual functions like finding and printing
    
    printBinarySearchTreeSorted(root);
    printf("\n\n");

    printf("Is 9 present in the binary search tree %s \n", recursiveFind(root, 9));
    printf("Is 4 present in the binary search tree %s \n", recursiveFind(root, 4));
    printf("Is 2 present in the binary search tree %s \n", recursiveFind(root, 2));


    // Freeing memory
    free(root); free(no2); free(no3); free(no4); free(no5); free(no6);


    return 0;
}

char* recursiveFind(BinarySearchTreeNode *root, int data) {

    char* yes = "true";
    char* no = "false";

    if (root->data == data)
        return yes;
    if (root->data > data) {
        if (root->left != NULL)
            return recursiveFind(root->left, data);
        else
            return no;
    }

    else if (root->data < data) {
        if (root->right != NULL)
            return recursiveFind(root->right, data);
        else
            return no;
    }
}

void printBinarySearchTreeSorted(BinarySearchTreeNode *root) {

    if (root->left != NULL)
        printBinarySearchTreeSorted(root->left);

    printf("%d ", root->data);

    if (root->right != NULL)
        printBinarySearchTreeSorted(root->right);
}
