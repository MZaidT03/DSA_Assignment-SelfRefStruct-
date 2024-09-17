#include <iostream>
using namespace std; 
struct Node{
    int data;
    Node * ptr1, *ptr2;
};
int main(){
    Node *start = new Node;
    // 1
    start->data =30;
    start->ptr1 = new Node;
    start->ptr2 = new Node;

    // 2
    start->ptr1->data = 50;
    start->ptr1->ptr1 = new Node;
    start->ptr1->ptr2 = nullptr;

    // 3
    start->ptr1->ptr1->data = 40;
    start->ptr1->ptr1->ptr1 = new Node;
    start->ptr1->ptr1->ptr2 = nullptr;

    // 4
    start->ptr1->ptr1->ptr1->data = 90;
    start->ptr1->ptr1->ptr1->ptr1 = new Node;
    start->ptr1->ptr1->ptr1->ptr2 = nullptr;

    // 5
    start->ptr1->ptr1->ptr1->ptr1->data = 70;
    start->ptr1->ptr1->ptr1->ptr1->ptr1 = nullptr;
    start->ptr1->ptr1->ptr1->ptr1->ptr2 = nullptr;
    // Ptr 1 Done !!!!!!!!!!!!!!!!!!!!!!

    // start to ptr2 
    start->ptr2->data=60;
    start->ptr2->ptr1 = new Node;
    start->ptr2->ptr2 = new Node;
    
    //start to Ptr2 to ptr1
    start->ptr2->ptr1->data = 90;
    start->ptr2->ptr1->ptr1 = new Node;
    start->ptr2->ptr1->ptr2 = nullptr;

    //start to Ptr2 to ptr1 to ptr1
    start->ptr2->ptr1->ptr1->data = 30;
    start->ptr2->ptr1->ptr1->ptr1 = nullptr;
    start->ptr2->ptr1->ptr1->ptr2 = new Node;
    
    //
    start->ptr2->ptr1->ptr1->ptr2->data = 60;
    start->ptr2->ptr1->ptr1->ptr2->ptr1 = nullptr;
    start->ptr2->ptr1->ptr1->ptr2->ptr2 = nullptr;

    // start ptr2 to ptr2

    start->ptr2->ptr2->data = 20;
    start->ptr2->ptr2->ptr1 = start->ptr1->ptr1;
    start->ptr2->ptr2->ptr2 = new Node;
    //
    start->ptr2->ptr2->ptr2->data = 50;
    start->ptr2->ptr2->ptr2->ptr1 = nullptr;
    start->ptr2->ptr2->ptr2->ptr2 = nullptr;



    // Print The Path A
    cout<<"Path A"<<endl;
    cout<<start->data<<endl;
    cout<<start->ptr2->data<<endl;
    Node *ptr = start->ptr2->ptr1;
    while(ptr!=nullptr){
        cout<<ptr->data<<endl;
        ptr = ptr->ptr1;
    }

    // Print Path B 
    cout<<"Path B"<<endl;
    cout<<start->data<<endl;
    cout<<start->ptr2->data<<endl;
    cout<<start->ptr2->ptr2->data<<endl;
    ptr = start->ptr2->ptr2->ptr1;
    while(ptr!=nullptr){
        cout<<ptr->data<<endl;
        ptr = ptr->ptr1;
    }

    // Find 40 in Path B 
    ptr = start;
    int i = 0;
    while(i<3){
        if(ptr->data == 40){
            cout<<"40 Founded at: "<<ptr<<endl;
            break;
        }
        ptr = ptr->ptr2;
        i++;
    }
    ptr = start->ptr2->ptr2->ptr1;
    while(ptr!=nullptr){
        if(ptr->data == 40){
            cout<<"40 Founded at: "<<ptr<<endl;
            break;
        }
        ptr = ptr->ptr1;
    }
}