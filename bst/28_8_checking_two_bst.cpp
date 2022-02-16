#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

//isIdentical
bool idIdentical(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    else if(root1 == NULL || root2 == NULL){
        return false;
    }else{  //both not NULL
        bool cond1 = root1->data == root2->data;
        bool cond2 = idIdentical(root1->left, root2->left);
        bool cond3 = idIdentical(root1->right, root2->right);

        if(cond1 && cond2 && cond3){
            return true;
        }
        return false;
    }
}

int main(){
            // 2
        //    / \
        //   1   3

        Node* root = new Node(2);
        root->left = new Node(1);
        root->right = new Node(3);

                // 6
            //    / \
            //   3   8
            //   
        Node* root2 = new Node(6);
        root->left = new Node(3);
        root->right = new Node(8);
        if(idIdentical(root, root2)){
            cout<<" BST's are Identical"<<endl;
        }else{
            cout<<" BST's are not Identical"<<endl;
        }
    return 0;
}