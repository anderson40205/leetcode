/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* answer = NULL;
    struct ListNode* head = NULL;
    while(list1 || list2)
    {
        if(list1==NULL)
        {
            if(answer == NULL)
            {
                head = list2;
                answer = list2;
            } 
            else answer->next = list2;
            break;
        }
        else if(list2==NULL)
        {
            if(answer == NULL){
                head = list1;
                answer = list1;
            } 
            else answer->next = list1;
            break;
        }
        else if(list1->val < list2->val)
        {
            struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode->val = list1->val;
            newNode->next = NULL;
            if(answer == NULL)
            {
                head = newNode;
                answer = newNode;
            }
            else
            {
                answer->next = newNode;
                answer = answer->next;
            }
            list1 = list1->next;
        }
        else if(list1->val == list2->val)
        {
            struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
            struct ListNode* newNode2 = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode->val = list1->val;
            newNode->next = NULL;
            newNode2->val = list2->val;
            newNode2->next = NULL;
            if(answer == NULL)
            {
                head = newNode;
                answer = newNode;
                answer->next = newNode2;
                answer = answer->next;
            }
            else
            {
                answer->next = newNode;
                answer = answer->next;
                answer->next = newNode2;
                answer = answer->next;
            }
            list1 = list1->next;
            list2 = list2->next;
        }
        else
        {
            struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode->val = list2->val;
            newNode->next = NULL;
            if(answer == NULL)
            {
                head = newNode;
                answer = newNode;
            }
            else
            {
                answer->next = newNode;
                answer = answer->next;
            }
            list2 = list2->next;
        }
    }
    
    return head;
}