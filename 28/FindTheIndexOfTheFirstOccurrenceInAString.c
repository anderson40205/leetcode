int strStr(char* haystack, char* needle) 
{
    int answer = -1, i=0, j=0;
    int haystackLength = strlen(haystack);
    int needleLength = strlen(needle);
    do
    {
        if(haystackLength<needleLength)break;
        //printf("haystackLength = %d\n",haystackLength);
        //printf("needleLength = %d\n",needleLength);
        int temp = i;
        j=0;
        while(j<needleLength && haystack[temp]==needle[j])
        {
            temp++;j++;
        }
        if(j == needleLength)
        {
            //printf("Find answer: j=%d, i=%d\n",j,i);
            answer = i;
            break;
        }
        i++;
        haystackLength--;
    }while(haystack[i]!=NULL);
    return answer;
}