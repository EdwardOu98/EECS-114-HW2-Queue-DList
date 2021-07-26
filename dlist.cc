#include "dlist.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

DList::DList(){
    size = 0;
    head = NULL;
    tail = NULL;
}

// This function allocates memory for and
// creates a new node from the given value
ListNode* DList::CreateNode(int value){
    ListNode* node = new ListNode; // Allocates memory
    node->val = value;
    node->prev = NULL;
    node->next = NULL;
    
    return node;
}

// This function frees the allocated 
// memory for the given node
void DList::DeleteNode(ListNode* node){
    assert(node);
    delete node; //frees memory
}

// This function adds a new integer
// to the front of the list
void DList::add_to_front(int value){
    ListNode* node;
    node = CreateNode(value);
    assert(node);
    
    // If the list is not empty
    // connect the new node with 
    // the original head of the 
    // list and make the head 
    // pointer pointing to the 
    // new node
    if(head){
        node->next = head;
        head->prev = node;
        head = node;
        size++;
    }
    else{
        head = node;
        tail = node;
        size++;
    }
}

// This function adds a new integer
// to the back of the list
void DList::add_to_back(int value){
    ListNode* node;
    node = CreateNode(value);
    assert(node);

    // If the list is not empty
    // connect the new node with
    // the original tail of the 
    // list and make the tail 
    // pointer points to the 
    // new node
    if(tail){
        node->prev = tail;
        tail->next = node;
        tail = node;
        size++;
    }
    else{
        head = node;
        tail = node;
        size++;
    }
}

// This function returns the first
// node of the list
int DList::first(){
    return head->val;
}

// This function returns the last
// node of the list
int DList::last(){
    return tail->val;
}

// This function removes the given
// node from the list
void DList::remove(ListNode* node){
    assert(node);

    // If the given node is not the 
    // head of the list, connects the
    // node before the given node with
    // the node after the given one.
    if(node->prev){
        node->prev->next = node->next;
    }
    else{
        head = node->next;
    }

    // If the given node is not the 
    // tail of the list, connects the
    // node before the given one with
    // the node after the given one
    if(node->next){
        node->next->prev = node->prev;
    }
    else{
        tail = node->prev;
    }

    // Free the memory allocated for
    // the given node
    DeleteNode(node);
    
    size--;
}

// This function returns the node
// before the given node
ListNode* DList::previous(ListNode* node){
    assert(node);
    return node->prev;
}

// This function returns the node
// after the given node
ListNode* DList::next(ListNode* node){
    assert(node);
    return node->next;
}

// This function searches for a given
// value in the list and return the 
// corresponding node
ListNode* DList::search_value(int value){
    ListNode* node;
    node = head;

    while((node->val != value) && (node->next)){
        node = node->next;
    }

    return node;
}

// This function prints the current
// content of the list
void DList::printList(){
    ListNode* node;
    node = head;

    while(node){
        printf("%d ", node->val);
        if(tail == node){
            printf("\n");
        }
        node = node->next;
    }
}

// This function deletes the whole
// list after the program is finished
void DList::deleteList(){
    ListNode* node;
    node = head;

    while(node){
        remove(node);
        node = node->next;
    }
}
