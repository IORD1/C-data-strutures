#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *left ;
    struct Node *right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* searchInBst(Node* root, int key){
    if(root == NULL){
        return NULL;
    }

    if(root->data == key){
        return root;
    }

    if(root->data > key){
        return searchInBst(root->left , key);
    }

    return searchInBst(root->right, key);
}


int main(){
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    // BST : 
    //     4
    //    / \
    //   2   5
    //  / \   \
    // 1   3   6

    if(searchInBst(root, 5) == NULL){
        cout<<"key doesn't exsit"<<endl;
    }else{
        cout<<"key exist"<<endl;
    }
    return 0;
}