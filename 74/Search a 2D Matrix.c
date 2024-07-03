bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    // matrixSize 列數
    // matrixColSize 行數
    int left = 0;
    int out_middle = matrixSize/2;
    int right = matrixSize;
    
    while(left<right)
    {
    	if(target>matrix[out_middle][*matrixColSize-1])
        {
            left = out_middle;
            out_middle = (left+right)/2;
            if(left==out_middle)break;
            printf("1\n");
        }
        else if(target<=matrix[out_middle][*matrixColSize-1])
        {
            if(target>=matrix[out_middle][0])
            {
                int in_left = 0;
                int in_middle = (0+*matrixColSize)/2;
                int in_right = *matrixColSize;
                while(in_left < in_right)
                {
                    if(target == matrix[out_middle][in_middle]) return true;
                    else if(target > matrix[out_middle][in_middle])
                    {
                        in_left = in_middle;
                        in_middle = (in_left+in_right)/2;
                        if(in_left==in_middle)break;
                    }
                    else if(target < matrix[out_middle][in_middle])
                    {
                        in_right = in_middle;
                        in_middle = (in_left+in_right)/2;
                    }
                }
                return false;
            }
            else
            {
                right = out_middle;
                out_middle = (left+right)/2;
                printf("3\n");
            }
        } 
    }
    
    return false;
}