#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* inserBST(Node *root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left = inserBST(root->left,val);
    }else{
        root->right = inserBST(root->right, val);
    }
    return root;

}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int main(){
    Node *root = NULL;
    root = inserBST(root, 5);
    inserBST(root, 1);
    inserBST(root, 3);
    inserBST(root, 4);
    inserBST(root, 2);
    inserBST(root, 7);

    inorder(root);
    cout<<endl;

    return 0;
}