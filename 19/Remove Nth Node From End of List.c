/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{
    struct ListNode* current = head;
    int count = 0;
    while(current!=NULL)
    {
        current = current->next;
        count++;
    }
    current = head;
    for(int i=0;i<count-n-1;i++)
    {
        current = current->next;
    }
    if(count == n)
    {
        current = current->next;
        return current;
    }
    else if(current!=NULL && current->next!=NULL && current->next->next!=NULL) current->next = current->next->next;
    else if(current!=NULL && current->next!=NULL && current->next->next==NULL && n==1) current->next = NULL;
    else if(current!=NULL && current->next==NULL) return NULL;
    current = head;
    //
    return current;
}