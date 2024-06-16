/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void split(struct ListNode* head,struct ListNode** start,struct ListNode** end)
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    
    if(head==NULL)
    {
        *start = NULL;
        *end = NULL;
        return;
    }
    *start = head;
    while(fast->next!=NULL)
    {
        fast = fast->next;
        if(fast->next!=NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    *end = slow->next;
    slow->next = NULL;
}
struct ListNode* merge(struct ListNode* a,struct ListNode* b)
{
    if(a==NULL)return b;
    if(b==NULL)return a;
    struct ListNode* result;
    if(a->val > b->val)
    {
        result = b;
        result->next = merge(a,b->next);
        return result;
    }
    else
    {
        result = a;
        result->next = merge(a->next,b);
        return result;
    }
}

struct ListNode* mergeSort(struct ListNode* head)
{
    if(head==NULL || head->next==NULL)return head;
    struct ListNode* a = NULL;
    struct ListNode* b = NULL;
    split(head,&a,&b);
    a = mergeSort(a);
    b = mergeSort(b);
    return merge(a,b);
}
struct ListNode* sortList(struct ListNode* head) {
    struct ListNode* result = mergeSort(head);
    return result;
}