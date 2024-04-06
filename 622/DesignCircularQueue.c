typedef struct {
    int front;
    int rear;
    int* arr;
    int len;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* newQueue = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    newQueue->front = -1;
    newQueue->rear = -1;
    newQueue->arr = (int*)malloc(sizeof(int)*k);
    newQueue->len = k;
    return newQueue;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    //printf("enqueue\n");
    if(((obj->rear+1)%(obj->len)) == obj->front)
        return false;
    else
    {
        if(obj->front == -1)
            obj->front = 0;
        obj->rear = (obj->rear+1)%obj->len;
        obj->arr[obj->rear] = value;
        //printf("rear=%d\n",obj->rear);
        return true;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    //printf("dequeue\n");
    if(obj->front == -1)
        return false;
    else
    {
        if(obj->rear == obj->front)
        {
            obj->rear = -1;
            obj->front = -1; 
        }
        else
        {
            obj->front = ((obj->front+1)%(obj->len));//Not really delete, just move front pointer
        }
        //printf("front=%d\n",obj->front);
        return true;
    }
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(obj->front == -1)
        return -1;
    else
    {
        return obj->arr[obj->front];
    }
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj->front == -1)
        return -1;
    else
    {
        return obj->arr[obj->rear];
    }
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if(obj->front == -1)
        return true;
    else
        return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if(((obj->rear+1)%(obj->len)) == obj->front)
        return true;
    else
        return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj);
}