bool isHappy(int n) {
    int digit[10]={0};
    int temp = n;

    while(1)
    {
        for(int i=0;i<10;i++) digit[i]=0;
        int lasti = 0;
        //process digit
        for(int i=0;i<10;i++)
        {
            digit[i] = temp%10;
            //printf("%d, ",digit[i]);
            temp/=10;
            
            if(temp/10==0)
            {
                digit[i+1] = temp;
                lasti = i+1;
                break;
            }
        }
        //printf("\n");
        int sum = 0;
        //printf("lasti=%d\n",lasti);
        for(int i=0;i<=lasti;i++)
        {
            sum+=pow(digit[i],2);
            //printf("sum=%d\n",sum);
        }
        if(sum==1) return true;
        temp = sum;
        //printf("temp=%d\n",temp);
        if(sum==4) return false;
    }
}