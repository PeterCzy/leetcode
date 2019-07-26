/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* curr = head;
    struct ListNode* prev = head;
    
    int pos = 0;
    while(curr != NULL){
        curr = curr->next;
        if(pos > n) prev = prev->next;
        pos++;
    }
    
    if(pos > n){
        curr = prev->next;
        prev->next = prev->next->next;
        free(curr);
    }
    else{
        curr = head;
        head = head->next;
        free(curr);
    }
    
    return head;
}
