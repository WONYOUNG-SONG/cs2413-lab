// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head){
      if (head == NULL || head->next == NULL) {
            return head;
      }
      
      struct ListNode* new_head = head->next;
      struct ListNode* prev_tail = NULL;
      struct ListNode* cur = head;
      
      while (cur != NULL && cur->next != NULL){
            struct ListNode* first = cur;
            struct ListNode* second = cur->next;
            struct ListNode* next_pair = second->next;
            
            second->next = first;
            first->next = next_pair;
            
            if (prev_tail != NULL){
                  prev_tail->next = second;
            }
            
            prev_tail = first;
            cur = next_pair;
      }
      return new_head;
}