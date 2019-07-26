/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int val1 = 0, val2 = 0, val = 0, sum = 0, overflow= 0;
    struct ListNode* ret = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    struct ListNode* start = ret;
    
    while(l1 != NULL || l2 != NULL){
        val1 = (l1 != NULL)?l1->val:0;
        val2 = (l2 != NULL)?l2->val:0;
        
        sum = val1 + val2 + overflow;
        val = sum%10;
        overflow = sum/10;
        
        struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = val;
        ret->next = temp;
        ret = ret->next;
        
        if(l1 != NULL) l1 = l1->next;
        if(l2 != NULL) l2 = l2->next;
    }
    
    if(overflow == 1){
        struct ListNode* temp = (struct ListNode*)calloc(1, sizeof(struct ListNode));
        temp->val = 1;
        ret->next = temp;
    }
    
    return start->next;
}
