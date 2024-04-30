int min(int a,int b)
{
    return (a<b)?a:b;
}
int maxArea(int* height, int heightSize) {
    //正規做法是在一個while(left<right) 中，兩邊一個箭頭，左跟右比大小成寬度，大的那邊不動，小的那邊移動，每輪寬度會一直減一
    char contain[10001];
    int farAndBig[heightSize];
    int tempMax = 0,tempIndex=0;
    for(int i=0;i<10001;i++)contain[i]=0;
    for(int i=heightSize-1;i>=0;i--)
    {
        farAndBig[i] = tempIndex;
        if(height[i]>tempMax)
        {
            tempMax = height[i];
            tempIndex = i;
        }
    }
    //for(int i=0;i<heightSize;i++)printf("fab=%d\n",farAndBig[i]);
    int sameHeight = 0;
    int area = 0;
    int maxArea = INT_MIN;
    for(int i=0;i<heightSize-1;i++)
    {
        //printf("i=%d\n",i);
        if(contain[height[i]]==1)continue;
        if(height[i]*(heightSize-i-1)<maxArea)continue;
        for(int j=farAndBig[i];j<heightSize;j++)
        {
            sameHeight = min(height[i],height[j]);
            area = (j-i)*sameHeight;
            if(maxArea<area)maxArea=area;
        }
        contain[height[i]] = 1;
    }
    return maxArea;
}