void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int** arr, int low, int high) {
    int pivot1 = arr[low][0]; // 第一個元素作為基準值
    int pivot2 = arr[low][1]; // 第二個元素作為基準值
    int i = low - 1; // 初始化分割索引
    int j = high + 1;

    while (1) {
        do {
            i++;
        } while (arr[i][0] < pivot1 || (arr[i][0] == pivot1 && arr[i][1] < pivot2));

        do {
            j--;
        } while (arr[j][0] > pivot1 || (arr[j][0] == pivot1 && arr[j][1] > pivot2));

        if (i >= j)
            return j;

        swap(&arr[i][0], &arr[j][0]);
        swap(&arr[i][1], &arr[j][1]);
    }
}

void quickSort(int** arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi);//有重複數字的話一定要用pi，不然會錯，因為我們用的是Hoare partition scheme 
        quickSort(arr, pi + 1, high);
    }
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) 
{
    int i,j,oldRight = -1,rowCount = 0, oldLeft = 0;
    int** temp = NULL;
    bool isOverlap = false;
    quickSort(intervals, 0, intervalsSize-1);
    // for(i=0;i<intervalsSize;i++)
    // {
    //     printf("%d %d \n",intervals[i][0],intervals[i][1]);
    // }
    for(i=0;i<intervalsSize;i++)
    {
        if(intervals[i][0] <= oldRight)
        {
            if(intervals[i][1]>oldRight)
            {
                temp[rowCount-1][1] = intervals[i][1];
                if(intervals[i][0]<oldLeft) temp[rowCount-1][0] = intervals[i][0];
            }
        }
        else
        {
            rowCount++;
            temp = (int**)realloc(temp,rowCount*sizeof(int*));
            temp[rowCount-1] = (int*)malloc(sizeof(int)*2);
            temp[rowCount-1][0] = intervals[i][0];temp[rowCount-1][1] = intervals[i][1];
            oldLeft = intervals[i][0];
            oldRight = intervals[i][1];
        }
        if(i>0 && intervals[i][0]<=oldRight && !(intervals[i][0]>=oldLeft && intervals[i][1]<=oldRight))
        {
            oldLeft = intervals[i][0];
            oldRight = intervals[i][1];
        }
    }
    *returnSize = rowCount;//not fix
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for(int idx =0 ; idx < (*returnSize); idx++){
        (*returnColumnSizes)[idx] = 2;
    }
    return temp;
}