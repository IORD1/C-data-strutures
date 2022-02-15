#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left , *right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool isBST(Node* root, Node* min, Node* max){
    if(root == NULL){
        return true;
    }

    if(min != NULL && root->data <= min->data){
        return false;
    }

    if(max != NULL && root->data >= max->data){
        return false;
    }
    
    bool leftValid = isBST(root->left, min , root);
    bool rightValid = isBST(root->right, root, max);

    return leftValid and rightValid;
}

int main(){
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(7);
    root->right->right = new Node(6);

    // BST : 
    //     4
    //    / \
    //   2   5
    //  / \   \
    // 1   7   6

    if(isBST(root, NULL, NULL)){
        cout<<"valid BST"<<endl;
    }else{
        cout<<"Not a valid BST"<<endl;
    }

    return 0;
}