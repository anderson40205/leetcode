void inita2z(int* a2z,int length)
{
    for(int i=0;i<length;i++) a2z[i] = 0b0;
}
int lengthOfLongestSubstring(char* s) {
    int accumulate = 0;
    int maxAnswer = 0;
    int lenSize = 130;
    int a2z[lenSize];
    inita2z(a2z,lenSize);
    int length =  strlen(s);
    for(int i=0;i<length;i++)
    {
        for(int j=i;j<length;j++)
        {
            int convertIndex = (int)s[j];
            if(a2z[convertIndex]==1)
            {
                break;// Important!! Sliding window!!!
                accumulate = 1;
                inita2z(a2z,lenSize);
                a2z[convertIndex]=1;
            }
            else
            {
                a2z[convertIndex]=1;
                accumulate++;
                if(maxAnswer<accumulate)
                {
                    maxAnswer = accumulate;
                }
            }
        }
        inita2z(a2z,lenSize);
        accumulate = 0;        
    }
    return maxAnswer;
}