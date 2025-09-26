//Harshil Nagori
//24070123046
//CODE:

#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node*next;
    
    Node(int data){
        val=data;
        next=NULL;
    }
};

int main() {
    Node*n1=new Node(10);
    Node*n2=new Node(20);
    Node*n3=new Node(30);
    
    n1->next=n2;//1->2
    n2->next=n3;//2->3
    //n3->next is NULL
    
    Node*temp=n1;//start from head
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }

    return 0;
}

//OUTPUT
//10 20 30 
