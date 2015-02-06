//Title:Remove Duplicates from Sorted Array
//参考了别人的代码:用两个指针i,j,如果A[i]<A[j],那么i+1这个位置一定该放A[j]
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0 || n==1)
            return n;
        int i,j;
        for(i=0,j=1;j<n;j++){
            if(A[i]<A[j]){
                A[++i]=A[j];
            }
        }
        return i+1;
    }
};
