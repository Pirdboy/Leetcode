//Title:First Missing Positive
//参考了别人的代码
//保证A[i]处的正数处在正确位置:即A[i]-1(如果A[i]>0 && A[i]<=n的话)
class Solution {
private:
    void swap(int A[],int i,int j){
        int t=A[i];
        A[i]=A[j];
        A[j]=t;
    }

public:
    int firstMissingPositive(int A[], int n) {
        for(int i=0;i<n;i++){
            while(A[i]>0 && A[i]<=n && A[i]!=A[A[i]-1])
                swap(A,i,A[i]-1);
        }
        for(int i=0;i<n;i++){
            if(A[i]!=i+1)
                return i+1;
        }
        return n+1;
    }
};
