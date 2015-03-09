//Title:Factorial Trailing Zeroes 
//就是寻找因数中有多少个2和多少个5,尾数0的个数就是其中较少者
//注意:
//一、因为2的个数明显会比5多，所以只需要找5的个数即可
//5的倍数各有1个5,25的倍数各有2个5,125的倍数各有3个5.....
//所以ans=n/5 + n/25 + n/125 +......
//在代码实现方面,通过直接修改n（n/=5），会提高时间
//而不是用一个b=5,然后每次b*=5，这样会超时
class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        while(n>=5){
            n/=5;
            ans += n;
        }
        return ans;
    }
};
