char* longestPalindrome(char* s) {
    int startIndex = INT_MIN;
    int endIndex = INT_MIN;
    int diff = 0;
    int longestPalindromic = INT_MIN;
    int LstartIndex = INT_MIN;
    int LendIndex = INT_MIN;

    int slen = strlen(s);
    if(slen==1)
    {
        char* ans = (char*)malloc(sizeof(char)*2);
        ans[0] = s[0];ans[1] = '\0';
        return ans;
    }
    for(int i=0;i<slen;i++)
    {
        if(i>1 && s[i]==s[i-2])
        {
            startIndex = i-2;
            endIndex = i;
            while(startIndex>=0 && endIndex<slen && s[startIndex]==s[endIndex])
            {
                startIndex--;
                endIndex++;
            }
            diff = endIndex-startIndex;
            if(longestPalindromic<diff)
            {
                longestPalindromic = diff;
                LstartIndex = startIndex + 1;
                LendIndex = endIndex - 1;
            }
        }
        if(i>0 && s[i]==s[i-1])
        {
            startIndex = i-1;
            endIndex = i;
            while(startIndex>=0 && endIndex<slen && s[startIndex]==s[endIndex])
            {
                startIndex--;
                endIndex++;
            }
            diff = endIndex-startIndex;
            if(longestPalindromic<diff)
            {
                longestPalindromic = diff;
                LstartIndex = startIndex + 1;
                LendIndex = endIndex - 1;
            }
        }
    }
    if(longestPalindromic<0)
    {
        char* ans = (char*)malloc(sizeof(char)*2);
        ans[0] = s[0];ans[1] = '\0';
        return ans;
    }
    // printf("LstartIndex = %d\n",LstartIndex);
    // printf("LendIndex = %d\n",LendIndex);
    // printf("longestPalindromic = %d\n",longestPalindromic);
    char* ans = (char*)malloc(sizeof(char)*(longestPalindromic));
    int i = 0;
    int ansCount = 0;
    for(i=LstartIndex;i<=LendIndex;i++)
    {
        ans[ansCount++] = s[i];
    }
    ans[ansCount]='\0';
    return ans;
}