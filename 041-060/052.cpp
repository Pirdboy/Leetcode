//Title:N-Queens II
//与上一题相同
class Solution {
private:
    int num;
    int* C; 
    void backTracking(int cur,int n){
        if(cur==n){
            num++;
        }
        else{
            for(int i=0;i<n;i++){
                bool ok=true;
                C[cur]=i;
                for(int j=0;j<cur;j++){
                    //test
                    if(C[j]==i||C[j]-j==i-cur||C[j]+j==i+cur){
                        ok=false;
                        break;
                    }
                }
                if(ok)
                    backTracking(cur+1,n);
            }
        }
    }
public:
    int totalNQueens(int n) {
        num=0;
        C=new int[n];
        backTracking(0,n);
        delete []C;
        return num;
    }
};
