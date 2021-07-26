#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Queue::Queue(){   
}

void Queue::CreateQueue(int n){
    head = tail = 0;
    size = n;

    list = new float[n];
}

// This function frees the memory allocated
// for the queue
void Queue::deleteQueue(){
    delete[] list;
}

// This function put a floating point number
// to the back of the queue
void Queue::enqueue(float value){
    // Check if the queue is full
    // if yes, show an error message on screen
    if(checkFull()){
        printf("OVERFLOW!!! Attempt to add an element to a full queue\n");
    }
    else{
        // Check if the current tail of the queue
        // is at the last index of the array
        // if yes, wrap the queue around by
        // setting the tail to be the first index of
        // the array and putting the new element at
        // the tail position
        list[tail] = value;
        if(tail == (size - 1)){
            tail = 0;
        }
        else{
            tail = tail + 1;
        }
    }
}

// This function remove the head element
// from the queue and return the value of
// that element
float Queue::dequeue(){
    // Check if the queue is empty
    // if yes, show an error message on screen
    // and return NULL
    if(checkEmpty()){
        printf("UNDERFLOW!!! Attempt to remove an element from an empty list\n");
        return -1;
    }
    else{
        float x = list[head];
        // Check if the current head of the queue
        // is at the last index of the array
        // if yes, set the head to be the 
        // first index of the array
        if(head == (size - 1)){
            head = 0;
        }
        else{
            head = head + 1;
        }
        return x;
    }
}

// This function checks if the queue is empty
bool Queue::checkEmpty(){
    if(head == tail){
        return true;
    }
    return false;
}

// This function checks if the queue is full
bool Queue::checkFull(){
    if((head == tail + 1) || ((head == 0) && (tail == size - 1))){
        return true;
    }
    return false;
}

// This function prints the current members of the queue
void Queue::printQueue(){
    if(checkEmpty()){
        printf("The queue is empty!\n");
    }
    else{
        int n = head;
        do{
            printf("%.2f ", list[n]);
            if(n == tail-1){
                printf("\n");
            }

            if((n == (size - 1)) && (n != tail)){
                n = 0;
            }
            else{
                n++;
            }
        }while(n != tail);
    }
}
