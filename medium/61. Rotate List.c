/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode* node = head;
    int count = 1;
    
    if(head == NULL)
        return NULL;
    
    while(node->next != NULL){
        node = node->next;
        count++;
    }
    
    if(k == 0)
        return head;
    k = k%count;
    
    int id = 0;
    struct ListNode* prev = head;
    struct ListNode* last = head;
    while(last->next != NULL){
        last = last->next;
        if(id >= k)
            prev = prev->next;
        id++;
    }
    
    last->next = head;
    head = prev->next;
    prev->next = NULL;
    
    return head;
}
