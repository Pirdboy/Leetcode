//Title:Jump Game II
//greedy
class Solution {
public:
    int jump(int A[], int n) {
        int count=0;
        int i=0;
        while(i<n){
            int maxPos=i+A[i];
            if(maxPos>=n-1){
                count++;
                break;
            }
            int max=0;
            int newPos=0;
            for(int j=0;maxPos-j>i;j++){
                if(A[maxPos-j]-j>max){
                    max=A[maxPos-j]-j;
                    newPos=maxPos-j;
                }
            }
            i=newPos;
            count++;
        }
        return count;
    }
};