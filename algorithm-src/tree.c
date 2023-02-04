#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

Node* new_node(int x)
{
    Node* p;
    p=(Node*)malloc(sizeof(Node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

Node* insert_tree(int x, Node* root)
{
    if(root==NULL) return new_node(x);
    if(x < root->data) root->left=insert_tree(x,root->left);
    else root->right=insert_tree(x,root->right);
    return root;
}

Node* search_tree(int x, Node* root)
{
    if(root==NULL) return NULL;
    if(x == root->data) return root;
    if(x < root->data) return search_tree(x,root->left);
    else return search_tree(x,root->right);
}

void free_tree(Node* root)
{
    if(root==NULL)return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}