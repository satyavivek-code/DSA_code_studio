#include <bits/stdc++.h> 
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node (int data){
        this -> data = data;
        this -> next = NULL;
    }
};

// Insert Node at beginning 

void insertAtHead(Node* &head, int d){ // [&head] taken because it dosent take any extra space
    
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

// Insert Node at end

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail->next;

}
// Insert Node at particular position 

void insertAtPosition(Node* &tail, Node* &head, int position, int d){

    // insert at start

    if (position ==1){
        insertAtHead(head,d);
        return;
    }
    Node* temp = head;
    int count = 1;
    
    // traversing the list

    while (count < position-1){
        temp = temp->next;
        count++;
    }
    // insert at last
    if (temp -> next == NULL){
        insertAtTail(tail,d);
        return;
    }
    
    Node* nodeAtPosition = new Node(d);
    nodeAtPosition->next = temp->next;
    temp->next = nodeAtPosition;
    
}


Node* reverseLinkedList(Node* &head)
{
    // either single element in list or no element
    // check if head is empty or the head next is empty

    if (head == NULL || head -> next == NULL){
		return head;
	}

	Node* previous = NULL;
	Node* current = head;
	Node* forward = NULL;

	while (current != NULL){
		forward = current -> next;
		current -> next = previous;
        
		previous = current;
		current = forward;
	}
	return previous;
}

void print(Node* &list){
    Node* temp = list;
    while (temp!= NULL){
        cout << temp -> data << " " ;
        temp = temp -> next;
    }cout << endl;
}

int main(){

    Node* node1 = new Node(2);
    
    Node* head = node1;
    Node* tail = node1;

    insertAtPosition(tail, head, 1, 3);
    print(head);
    insertAtPosition(tail,head , 2, 4);
    print(head);
    insertAtPosition(tail, head, 3, 5);
    print(head);
    cout << " The reverse of the given Linked list is :"; 
    print(head); 
    Node* newhead = reverseLinkedList(head);
    cout << "Reversed list " <<" ";
    print(newhead);



}

