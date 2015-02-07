//Title:Search Insert Position
//与上一题Search for a Range差不多，都是要用二分查找
//个人感觉，对于目标值在数组两边的情况单独处理，这样写比较好一些
class Solution {
public:
    int binarySearch(int A[],int n,int target){
        if(target<=A[0])
            return 0;
        if(target>A[n-1])
            return n;
        if(target==A[n-1])
            return n-1;
        int mid=-1;
        int left=0;
        int right=n-1;
        while(left<=right){
            if(left+1==right){
                if(A[left]==target){
                    mid=left;
                }
                else if(A[right]==target){
                    mid=right;
                }
                else{
                    mid=left+1;
                }
                break;
            }
            int m=(left+right)/2;
            if(A[m]==target){
                mid=m;
                break;
            }
            else if(A[m]>target){
                right=m;
            }
            else{
                left=m;
            }
        }
        return mid;
    }
    int searchInsert(int A[], int n, int target) {
        return binarySearch(A,n,target);
    }
};
