#include<iostream>
#include<stack>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
    Node(int val){
        data=val;
        left = NULL;
        right = NULL;
    }
};

void zigzagTraversal(Node* root){
    if(root == NULL){
        return;
    }
    stack<Node*> currlevel;
    stack<Node*> nextlevel;

    bool leftToRight = true;

    currlevel.push(root);

    while(!currlevel.empty()){
        Node* temp = currlevel.top();
        currlevel.pop();

        if(temp){
            cout<<temp->data<<" ";
            if(leftToRight){
                if(temp->left){
                nextlevel.push(temp->left);
                 }
                if(temp->right){
                nextlevel.push(temp->right);
                 }
            }else{      //Right to left
                    if(temp->right){    
                        nextlevel.push(temp->right);
                    }
                    if(temp->left){
                        nextlevel.push(temp->left);
                    }
            }
        }

        if(currlevel.empty()){
            leftToRight = !leftToRight;
            swap(currlevel,nextlevel);
        }
    }
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
    zigzagTraversal(root);
    cout<<endl;
    return 0;
}