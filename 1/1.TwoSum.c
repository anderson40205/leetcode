/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct __attribute__((packed))
{
    int key;
    int value;
    bool use;
    struct Node* next;
} Node;

int hash(int key, int bucketSize)
{
    int hashValue = key % bucketSize;
    return (hashValue >= 0) ? hashValue : (hashValue + bucketSize);//Because testcase has a negative value
}

void put(Node* buckets, int bucketSize, int key, int value)
{
    int index = hash(key, bucketSize);
    //printf("hash result = %d\n",index);
    //printf("bucketSize=%d,key=%d,value=%d,index=%d\n",bucketSize,key,value,index);
    if(buckets[index].use == false)
    {
        buckets[index].key = key;
        buckets[index].value = value;
        buckets[index].use = true;
        buckets[index].next = NULL;
    }
    else
    {
        Node* current = &buckets[index];
        while(current->next!=NULL)
            current = current->next;
        //because next node is null, I need to allocate memory for Node
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->key = key;
        newNode->value = value;
        newNode->use = true;
        newNode->next = NULL;
        //printf("2 bucketSize=%d,key=%d,value=%d,index=%d\n",bucketSize,key,value,index);
        current->next = newNode;
        //printf("3 current->key=%d\n",current->key);
    }
}

bool search(Node* buckets, int numsSize, int key, int* answer)
{
    int index = hash(key, numsSize);
    if(buckets[index].use == true)
    {
        Node* current = &buckets[index];
        
        if(current->key == key)
        {
            *answer = current->value;
            return true;
        }
        while(current!=NULL)
        {
            if(current->key == key)
            {
                *answer = current->value;
                return true;
            }
            current = current->next;
        }
    }
    return false;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    Node* bucket = (Node*)malloc(sizeof(Node)*numsSize);
    int *answer = (int*)malloc(sizeof(int)*2);
    *returnSize = 2;// because only two sum
    
    //Initialize hashtable
    int i=0;
    for(i=0;i<numsSize;i++)
    {
        bucket[i].key = -1;
        bucket[i].value = -1;
        bucket[i].use = false;
        bucket[i].next = NULL;
    }
    
    //Insert into hashtable
    for(i=0;i<numsSize;i++)
    {
        put(bucket, numsSize, nums[i], i);
    }
    
    for(i=0;i<numsSize;i++)
    {
        int remainingTarget = target - nums[i];
        int ans = 0;
        bool found = search(bucket, numsSize, remainingTarget, &ans);
        //printf("ans=%d, num[%d]=%d, remainingTarget=%d\n",ans,i,nums[i],remainingTarget);
        if(found == true && ans != i)
        {
            //printf("answer = %d and %d\n",ans,i);
            if(ans <= i)
            {
                answer[0] = ans;
                answer[1] = i;
            }
            else
            {
                answer[0] = i;
                answer[1] = ans; 
            }
            break;
        }
    }
    return answer;
}