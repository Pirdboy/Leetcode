//Title:Divide Two Integers
//只利用加、减和位运算符来做除法
//核心思想是二分法：位运算符, <<1 和 >>1 分别表示乘2和除以2
//所以用除数不断乘2来逼近被除数，对剩下的被除数部分进行同样的操作
//直到被除数的剩余部分小于除数
//D=a*2^m + a*2^n +..... 
//那么商就是2^m+2^n...
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0)
            return INT_MAX;
        long long D1=dividend;
        long long D2=divisor;
        bool negativeD1=false;
        bool negetiveD2=false;
        if(D1<0){
            negativeD1=true;
            D1=-D1;
        }
        if(D2<0){
            negetiveD2=true;
            D2=-D2;
        }
        if(D1<D2)
            return 0;
        long long result=0;
        while(D2<=D1){
            long long rePart=1;
            long long a=D2;
            while(a<D1){
                a <<= 1;
                rePart <<= 1;
            }
            if(a==D1){
                result+=rePart;
                break;
            }
            else{
                a >>= 1;
                rePart >>= 1;
                result+=rePart;
                D1 -= a;
            }
        }
        if(negativeD1!=negetiveD2){
            result = -result;
        }
        if(result<INT_MIN || result>INT_MAX){
            return INT_MAX;
        }
        else
            return (int)result;
    }
};
