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

void insertatHead(node* &head , int val){
    node* n=new node(val);
    n->next=head;
    head = n;
}
void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;

    }
    cout<<"NULL"<<endl;
}

node* reversek(node* &head, int k ){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    int count = 0;
    while(currptr!=NULL && count<k){
        nextptr= currptr->next;
        currptr->next=prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if(nextptr!=NULL){
        head->next= reversek(nextptr,k);
    }
    return prevptr;
}

int main(){
    node* head = NULL;
    insertatHead(head, 6);
    insertatHead(head, 5);
    insertatHead(head, 4);
    insertatHead(head, 3);
    insertatHead(head, 2);
    insertatHead(head, 1);
    display(head);

    int k = 2;
    node* newhead  = reversek(head, k);
    display(newhead);


}