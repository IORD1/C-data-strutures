#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int val){
            data = val;
            next = NULL;
        }


};

void insertathead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

void display(node* head){
    node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<"-";
        temp = temp->next;
        
    }cout<<"NULL"<<endl;
}

void evenafterodd(node* &head){

    node* odd = head;
    node* even = head->next;
    node* evenstart = even;
    while(odd->next!=NULL && even->next != NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even= even->next;
    }

    odd->next = evenstart;
    if(odd->next != NULL){
        even->next = NULL;
    }
}






int main(){
    node* head = NULL;

    for(int i = 6;i>0; i--){
        insertathead(head, i);
    }

    display(head);
    evenafterodd(head);
    display(head);



    return 0;
}