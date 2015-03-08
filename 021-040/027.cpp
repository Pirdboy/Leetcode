//Title:Remove Element
class Solution {
public:
    void swap(int A[],int i,int j){
        int t=A[i];
        A[i]=A[j];
        A[j]=t;
    }

    int removeElement(int A[], int n, int elem) {
        int j=n;
        int i=n-1;
        for(;i>=0;i--){
            if(A[i]==elem){
               swap(A,i,--j); 
            }
        }
        return j;
    }
};
