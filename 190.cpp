//Title:Reverse Bits 
//If this function is called many times, how would you optimize it?
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        char reBits[32]={0};
        int c=0;
        while(c<32){
            if(n&1)
                reBits[c++]='1';
            else
                reBits[c++]='0';
            n >>= 1;
        }
        int b=1;   
        int re=0;
        while(c>0){
            re += (reBits[--c]-'0')*b;
            b*=2;
        }
        return re;
    }
};
