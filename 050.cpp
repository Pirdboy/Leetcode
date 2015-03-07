//Title:Pow(x,n);
//二分法,有许多特殊情况要处理
class Solution {
private:
    double specialCase(double x,int n){
        if(n<0)
            n=-n;
        if(x==1)
            return 1;
        if(x==0){
            if(n==0)
                return 1;
            else if(n>0)
                return 0;
        }
        if(x==-1){
            if(n&1)
                return -1;
            else
                return 1;
        }
    }

public:
    double pow(double x, int n) {
        if(x==1 || x==-1 || x==0)
            return specialCase(x,n);
        if(n<0)
            return 1.0/pow(x,-n);
        if(x<0)
            return pow(-1,n)*pow(-x,n);
        if(n==0)
            return 1.0;
        if(n==1)
            return x;
        double re=1.0;
        if(n%2==1){
            re=x;
            n--;
        }
        double re2=pow(pow(x,n/2),1);
        return re*re2*re2;
    }
};
