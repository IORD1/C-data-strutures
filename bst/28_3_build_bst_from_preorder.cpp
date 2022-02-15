#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node * left;
    struct Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL; 
    }
};

Node* constrctBST(int preorder[], int* preorderIdx, int key, int min, int max, int n){
    if(*preorderIdx >= n){
        return NULL;
    }
    Node* root = NULL;
    if(key > min && key < max){
        root = new Node(key);
        *preorderIdx = *preorderIdx + 1;
        if(*preorderIdx < n){
            root->left = constrctBST(preorder, preorderIdx, preorder[*preorderIdx], min,key,n);
        }
        if(*preorderIdx < n){
            root->right = constrctBST(preorder, preorderIdx, preorder[*preorderIdx], key,max,n);
        }

    }

    return root;
}

void printPreorder(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}
int main(){
    int perorder[] = {10,2,1,13,11};
    int n= 5;
    int preorderIdx = 0;
    Node* root = constrctBST(perorder, &preorderIdx, perorder[0], INT8_MIN, INT8_MAX, n);
    printPreorder(root);


    return 0;
}