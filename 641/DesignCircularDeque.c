typedef struct element
{
    int val;
	struct element* pre;
	struct element* next;
}element;

typedef struct {
    struct element* head;
    struct element* tail;
    int currentSize;
    int maxSize;
} MyCircularDeque;


MyCircularDeque* myCircularDequeCreate(int k) {
    
	MyCircularDeque* node = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    node->maxSize = k;
    node->currentSize = 0;
	node->head = (element*)malloc(sizeof(element));
    node->head->val = -1;
    node->tail = (element*)malloc(sizeof(element));
    node->tail->val = -1;
    node->head->pre = node->tail;
    node->head->next = NULL;
    node->tail->next = node->head;
    node->tail->pre = NULL;
    
    return node;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    //printf("currentSize = %d\n",obj->currentSize);
    if(obj->currentSize == obj->maxSize)return false;
    element* newNode = (element*)malloc(sizeof(element));
	newNode->val = value;
	newNode->pre = obj->head->pre;
	newNode->next = obj->head;
	obj->head->pre->next = newNode;
	obj->head->pre = newNode;
    //printf("maxSize=%d\n",maxSize);
    obj->currentSize+=1;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if(obj->currentSize == obj->maxSize)return false;
    element* newNode = (element*)malloc(sizeof(element));
	newNode->val = value;
	newNode->pre = obj->tail;
	newNode->next = obj->tail->next;
	obj->tail->next->pre = newNode;
	obj->tail->next = newNode;
    obj->currentSize+=1;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if(obj->currentSize == 0)return false;
    obj->head->pre->pre->next = obj->head;
    obj->head->pre = obj->head->pre->pre;
    obj->currentSize-=1;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if(obj->currentSize == 0)return false;
    obj->tail->next->next->pre = obj->tail;
    obj->tail->next = obj->tail->next->next;
    obj->currentSize-=1;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    //printf("%d\n",obj->head->pre->val);
    return obj->head->pre->val;
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    //printf("%d\n",obj->tail->next->val);
    return obj->tail->next->val;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    if(obj->currentSize == 0)return true;
    else return false;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    if(obj->currentSize == obj->maxSize)return true;
    else return false;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/