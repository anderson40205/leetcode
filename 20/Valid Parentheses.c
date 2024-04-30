typedef struct 
{
    char arr[10000];
    int top;
}Stack;
void init(Stack* s)
{
    s->top = 0;//這行一職抱錯
}
void push(Stack* s,char ch)
{
    s->arr[s->top++] = ch;
}
char pop(Stack* s)
{
    if(s->top==0)return 'e';
    return s->arr[--s->top];
}
bool isEmpty(Stack* s)
{
    if(s->top!=0)return false;
    else return true;
}
bool isValid(char* s) {
    Stack* s1 = (Stack*)malloc(sizeof(Stack));
    init(s1);
    printf("%d\n",strlen(s));
    int len = strlen(s);
    if(len==1)return false;
    else if(len%2!=0) return false;
    bool backward = false;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='(' || s[i]=='[' || s[i]=='{' )
        {
            printf("s[%d] is %c\n",i,s[i]);
            push(s1,s[i]);
        }
        else if(s[i]==')' || s[i]==']' || s[i]=='}')
        {
            if(s[i]==')' && pop(s1)!='(') return false;
            if(s[i]==']' && pop(s1)!='[') return false;
            if(s[i]=='}' && pop(s1)!='{') return false;
            //printf("pop is %c\n",pop(s1));
            backward = true;
        }
    }
    if(!backward)return false;
    if(!isEmpty(s1))return false;
    return true;
}