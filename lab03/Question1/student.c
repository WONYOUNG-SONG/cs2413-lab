#include "student.h"

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* next_node =s NULL;
    
    while (cur != NULL){
        next_node = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next_node;
    }
    
    return prev;
}