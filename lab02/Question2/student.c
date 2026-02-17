#include "student.h"
#include <stdlib.h>   // malloc, free
#include <stdbool.h>  // bool

MyCircularQueue* myCircularQueueCreate(int k) {
    // TODO:
    // - Allocate MyCircularQueue
    // - Allocate the internal buffer `data` of length k
    // - Initialize capacity, head, tail, size
    
    MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    
    if (q == NULL){
        return NULL;
    }

    q->data = (int*)malloc(sizeof(int) * (size_t)k);
    q->capacity = k;
    q->head = 0;
    q->tail = 0;
    q->size = 0;

    return q;

}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    // TODO:
    // - If full, return false
    // - Write value at tail, advance tail (wrap), size++
    if (obj == NULL){
        return false;
    }
    
    if (obj->size == obj->capacity){
        return false;
    }
    
    obj->data[obj->tail] = value;
    obj->tail = (obj->tail + 1) % (obj->capacity);
    obj->size = obj->size + 1;
    
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    // TODO:
    // - If empty, return false
    // - Advance head (wrap), size--
    if (obj == NULL){
        return false;
    }
    
    if (obj->size == 0){
        return false;
    }
    
    obj->head = obj->head + 1;
    obj->size = obj->size - 1;
    
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    // TODO:
    // - Return -1 if empty
    // - Otherwise return data[head]
    if (obj == NULL){
        return -1;
    }
    
    if (obj->size == 0){
        return -1;
    }
    
    return obj->data[obj->head];

}

int myCircularQueueRear(MyCircularQueue* obj) {
    // TODO:
    // - Return -1 if empty
    // - Otherwise return the last inserted element
    //   (tail points to next insertion position)
    if (obj == NULL){
        return -1;
    }
    
    if (obj->size == 0){
        return -1;
    }
    
    int i = obj->tail -1;
    if (i < 0){
        i = obj->capacity - 1;
    }
    
    return obj->data[i];
    
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    // TODO:
    // - Return true if size == 0
    
    return (obj->size == 0);
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    // TODO:
    // - Return true if size == capacity
    
    return (obj->size == obj->capacity);
}

void myCircularQueueFree(MyCircularQueue* obj) {
    // TODO:
    // - Free internal buffer then free obj
    free(obj->data);
    free(obj);
}
