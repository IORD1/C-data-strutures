#include <iostream>
using namespace std;

class node{           //imp 
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL; 
    }
};


void insertAthead(node* &head , int val){
    node* n=new node(val);
    n->next=head;
    head = n;
}

bool search(node* head, int key){
    node* temp = head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void insertAtTail(node* &head, int val){

    node* n= new node(val);

    if(head == NULL){
        head = n;
        return ; 
    }

    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next=n;
}

void deletAtHead(node* &head){
    node* todelete = head;
    head = head->next;
    
    delete todelete;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void deletion(node* &head, int val){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deletAtHead(head);
        return;
    }

    node* temp = head;
    while(temp->next->data!=val){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next=temp->next->next;

    delete todelete;
}


node* reverse(node* &head){
    node* preptr = NULL;
    node* currptr = head;
    node* nextptr ;

    while(currptr!=NULL){
        nextptr = currptr->next;
        currptr->next = preptr;

        preptr = currptr;
        currptr = nextptr; 
    }

    return preptr;
}

node* reverseRecurive(node* &head){

    if(head==NULL || head->next==NULL){
        return head;

    }

    node* newerhead = reverseRecurive(head->next);
    head->next->next = head;
    head->next= NULL;

    return newerhead;
}

void fun1(node* head){
    if(head == NULL){
        return;
    }
    fun1(head->next);{
        cout<<head->data;
    }
}

int main(){

    node* head=NULL;  //defining a linked list
    insertAtTail(head, 1);
    insertAtTail(head, 2); 
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);
    //deletion(head,3);
    //deletAtHead(head);
   // node* newhead = reverse(head);
    //display(newhead);
    //node* newerhead = reverseRecurive(newhead);
    //display(newerhead);
    // cout<<search(head, 3)<<endl;
    fun1(head);

 
    return 0;
}