/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *cur = head, *pre = NULL, *next = NULL;
    while(cur){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;

}