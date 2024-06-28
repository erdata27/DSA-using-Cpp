#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    //constructor 
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
class DNode{
    public:
      int data;
      DNode*prev;
      DNode*next;
      DNode(int data){
          this->data=data;
          this->prev=nullptr;
          this->next=nullptr;
      }
};

class LinkedList{
    private:
       Node* head;
    public:
       LinkedList(){
                head=nullptr;
       }
       void display(){
           Node *current=head;
           while(current!=nullptr){
                 cout<<current->data<<"->";
                 current=current->next;
           }
            cout<<"NULL"<<endl;
            
       }

       void append(int data){
             Node*newnode=new Node(data);
             if(head==nullptr){
                head=newnode;
             }else{
                Node*current=head;
                while(current->next!=nullptr){
                    current=current->next;
                }
                current->next=newnode;
             }
       }
       void insert(int data,int index){
            Node*newnode=new Node(data);
            Node*current=head;
            for(int i=0;i<index-1;i++){
                current=current->next;
            }
            newnode->next=current->next;
            current->next=newnode;
       }
      void deleteNode(int key) {
        if (head == nullptr) return;

        Node* current = head;
        Node* prev = nullptr;

        if (current != nullptr && head->data == key) {
            head = current->next; 
            delete current; 
            return;
        }
        while (current != nullptr && current->data != key) {
            prev = current;
            current = current->next;
        }
        if (current ==nullptr) return;
        prev->next = current->next;
        delete current;
    }
};

class CircularLinkedList{
   private:
       Node* head;
   public:
       CircularLinkedList(){
        head=nullptr;
       }
       void append(int data){
            Node*current=head;
            Node*newnode=new Node(data);            
            while(current->next!=head && current!=nullptr){
                current=current->next;
            }
            current->next=newnode;
            newnode->next=head;
       }
       void prepend(int data){
            Node*current=head;
            Node*newnode=new Node(data);
            while(current->next!=head && current!=nullptr){
                current=current->next;
            }
            current->next=newnode;
            newnode->next=head;
            head=newnode;
       }
       void insert(int index,int data){
            Node*current=head;
            Node*newnode=new Node(data);
            for(int i=0;i<index-1;i++){
               current=current->next;
            }
            newnode->next=current->next;
            current->next=newnode;
       }
        void deleteNode(int key) {
        if (head == nullptr) return;
        Node* current = head;
        Node* prev = nullptr;
        if (current->data == key && current->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        if (current->data == key) {
            while (current->next != head) {
                current = current->next;
            }
            Node* temp = head;
            current->next = head->next;
            head = head->next;
            delete temp;
            return;
        }
        while (current->next != head && current->data != key) {
            prev = current;
            current = current->next;
        }
        if (current->data == key) {
            prev->next = current->next;
            delete current;
        }
    }

       void display(){
           Node *current=head;
           while(current!=nullptr && current->next!=head){
                 cout<<current->data<<"->";
                 current=current->next;
           }
            cout<<current->data<<endl;
            
       }
};


class DoublyLinkedList {
private:
    DNode* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }
    void append(int data) {
        DNode* newNode = new DNode(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            DNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    void deleteNode(int key) {
        if (head == nullptr) return;

        DNode* current = head;

        if (current != nullptr && current->data == key) {
            head = current->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete current;
            return;
        }

        while (current != nullptr && current->data != key) {
            current = current->next;
        }

        if (current == nullptr) return;

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        }

        delete current;
    }

    void display(){
        DNode* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    
    
}