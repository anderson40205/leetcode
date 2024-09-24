/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
    if(head==NULL) return NULL;
	struct Node* current;
	current = head;
	// 1. 每個node後面都插入一個該node的copy
	while(current!=NULL)
	{
		//printf("%d\n",current->val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = current->val;
        newNode->next = current->next;
        newNode->random = NULL;
        current->next = newNode;
        current = current->next->next;
	}
	// 2. 開始處理new node 的 random 指標
    current = head;
    while(current!=NULL)
    {
    	if(current->random!=NULL)
        	current->next->random = current->random->next;
        else
        	current->next->random = NULL;
        current = current->next->next;
    }
    // 3. random和next都指好了,接著要將old node和new node切開
    struct Node* oldLink = head;
    struct Node* newLink = head->next;
    struct Node* answer = head->next;
    while(oldLink!=NULL)
    {
        if(oldLink->next->next!=NULL)
        {
            oldLink->next = oldLink->next->next;
    	    newLink->next = newLink->next->next;
        }
        else
        {
            oldLink->next = NULL;
    	    newLink->next = NULL;
        }
    	
    	oldLink = oldLink->next;
    	newLink = newLink->next;
    }
	return answer;
}
