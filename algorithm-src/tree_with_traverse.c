#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

// このファイルの関数まとめ
Node* new_node(int x); //作成
Node* insert_tree(int x, Node* root); //追加
Node* search_tree(int x, Node* root); // 検索
void traverse_pre_order(Node* root); // 行きがけ
void traverse_in_order(Node* root); // 通りがけ
void traverse_post_order(Node* root); // 帰りがけ
void free_tree(Node* root); // 二分木のメモリの開放
void traverse_level_order(Node* root); // 幅優先探索
void enqueue(Node* data); //　幅優先探索で使うキューのための
Node* dequeue(void); // 幅優先探索で使うキューのための



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

void traverse_pre_order(Node* root)
{
    if(root==NULL)return;
    printf("%d\t",root->data);
    traverse_pre_order(root->left);
    traverse_pre_order(root->right);
}

void traverse_in_order(Node* root)
{
    if(root==NULL)return;
    traverse_in_order(root->left);
    printf("%d\t",root->data);
    traverse_in_order(root->right);
}

void traverse_post_order(Node* root)
{
    if(root==NULL)return;
    traverse_post_order(root->left);
    traverse_post_order(root->right);
    printf("%d\t",root->data);
}

void free_tree(Node* root)
{
    if(root==NULL)return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}


Node* queue[MAX_NUM];
int first=0;
int last=0;
 
void enqueue(Node* data)
{
    if( (last+1)%MAX_NUM == first ){
        printf("キューは満杯で、追加できません\n");
        return;
   }
    queue[last]=data;
    last=(last+1)%MAX_NUM;
    return;
}
 
Node* dequeue(void)
{
    Node* ret;
    if(first==last){
        //printf("キューにデータがありません\n");
        return NULL;
   }
    ret=queue[first];
    first=(first+1)%MAX_NUM;
    return ret;
}

void traverse_level_order(Node* root)
{
    int x;
    Node* p;
    enqueue(root);
    while(1){
        p=dequeue();
        if(p==NULL)return;
        printf("%d\t",p->data);
        if(p->left!=NULL) enqueue(p->left);
        if(p->right!=NULL) enqueue(p->right);
    }
}