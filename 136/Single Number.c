int singleNumber(int* nums, int numsSize) {
    //1⊕3⊕1⊕5⊕3 is equivalent to (1⊕1)⊕(3⊕3)⊕5
    int xorResult = 0,i = 0;
    while(i<numsSize)
    {
        xorResult ^= *(nums++);
        i++;
    }
    
    return xorResult;
}