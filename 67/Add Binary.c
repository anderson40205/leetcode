void swap (char* a,char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
char* addBinary(char* a, char* b) {
    int alen = strlen(a);
    int blen = strlen(b);
    int longest = (alen>blen)?alen:blen;
    char* result = (char*)malloc(sizeof(char)*(longest+1));
    char xorResult = 0;
    char andResult = 0;
    unsigned char carry = 0;
    int diff = abs(alen-blen);
    int result_idx = 0;
    int i=0;
    char* aTemp = (char*)malloc(sizeof(char)*(longest));
    char* bTemp = (char*)malloc(sizeof(char)*(longest));

    if(alen>blen)
    {
        int bidx = 0;
        for(i=0;i<longest;i++)
        {
            aTemp[i] = a[i];
            bTemp[i] = (i>=diff)?b[bidx++]:'0';
        }
    }
    else if(blen>alen)
    {
        int aidx = 0;
        for(i=0;i<longest;i++)
        {
            bTemp[i] = b[i];
            aTemp[i] = (i>=diff)?a[aidx++]:'0';
        }
    }
    else
    {
        for(i=0;i<longest;i++)
        {
            aTemp[i] = a[i];
            bTemp[i] = b[i];
        }
    }

    for(i=longest-1;i>=0;i--)
    {
        xorResult = (aTemp[i]&0b1) ^ (bTemp[i]&0b1);
        //printf("a[%d]=%d,b[%d]=%d,xor=%d\n",i,aTemp[i]&0b1,i,bTemp[i]&0b1,xorResult);
        result[result_idx++] = (carry==1)? (xorResult ^ 0b1)+'0' : xorResult+'0';
        
        andResult = ((aTemp[i]&0b1) & (bTemp[i]&0b1));
        //printf("and=%d\n",andResult);
        carry = (andResult==1 || (carry&xorResult)==1)? 1:0;
        //printf("carry=%d\n",carry);
    }
    int realLen = 0;
    if(carry==1)
    {
        result = (char*)realloc(result,sizeof(char)*(longest+2));
        result[result_idx] = 1+'0';
        result[result_idx+1] = '\0';
        realLen = result_idx+1;
        //for(int j=0;j<longest+1;j++)printf("%c, ", result[j]);
    }
    else
    {
        result[result_idx] = '\0';
        realLen = result_idx;
        //for(int j=0;j<longest;j++)printf("%c, ", result[j]);
    }
    //reverse
    //printf("realLen=%d\n",realLen);
    for(int j=0;j<realLen/2;j++)
    {
        swap(&result[j],&result[realLen-j-1]);
    }
    free(aTemp);
    free(bTemp);
    return result;
}