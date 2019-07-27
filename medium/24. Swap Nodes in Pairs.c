/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* prev = head;
    struct ListNode* curr;
    struct ListNode* tail = head;
    
    if(head == NULL || head->next == NULL)
        return head;
    
    head = head->next;
    while(prev != NULL && prev->next != NULL){
        curr = prev->next;
        
        tail->next = curr;
        prev->next = curr->next;
        curr->next = prev;
        
        tail = prev;
        
        prev = prev->next;
    }
    
    return head;
}
