/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int parent[1001];
 int findParent(int n)
 {
    if(parent[n] == -1) return n;
    else return findParent(parent[n]);
 }
 bool join(int x,int y)
 {
    x = findParent(x);
    y = findParent(y);
    if(x==y)return false;//重點是新加入的兩點有沒有共同祖先，有的話兩條連在一起會形成cycle
    parent[x]=y;
    return true;
 }
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) 
{
    for(int i=0;i<1001;i++)parent[i]=-1;
    int* answer = malloc(sizeof(int)*2);
    //printf("edgesSize = %d\n",edgesSize);
    answer[0] = 0;answer[1] = 0;
    for(int i=0;i<edgesSize;i++)
    {
        //printf("%d,%d\n",edges[i][0],edges[i][1]);
        if(!join(edges[i][0],edges[i][1]))
        {
            answer[0] = edges[i][0];
            answer[1] = edges[i][1];
            break;
        }
    }
    
    *returnSize = 2;
    return answer;
}