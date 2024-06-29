uint32_t reverseBits(uint32_t n) {
    unsigned char bit[32] = {0};
    unsigned char bit_idx = 31;
    for(int i=0;i<32;i++)
    {
        bit[bit_idx--] = (n>>i)&0x1;
    }
    uint32_t sum = 0;
    for(int i=0;i<32;i++)
    {
        if(bit[i]&0x1 == 1)
        {
            sum += pow(2,i);
        }
    }
    return sum;
}