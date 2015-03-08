//Title:Maximum Subarray
//最大子数组
//算法导论上分治法讲过。
class Solution {
private:
    int findMaxSubSum(int A[],int low,int high){
        if(low==high){
            return A[low];
        }
        int mid=(low+high)/2;
        int sumLeft=findMaxSubSum(A,low,mid);
        int sumMid=findMaxSubSumCrossingMid(A,low,high,mid);
        int sumRight=findMaxSubSum(A,mid+1,high);
        if(sumLeft>=sumMid && sumLeft>=sumRight)
            return sumLeft;
        if(sumMid>=sumLeft && sumMid>=sumRight)
            return sumMid;
        if(sumRight>=sumLeft && sumRight>=sumMid)
            return sumRight;
    }
    int findMaxSubSumCrossingMid(int A[],int low,int high,int mid){
        int left=INT_MIN;
        int sum=0;
        int i;
        for(i=mid;i>=low;i--){
            sum+=A[i];
            if(sum>left)
                left=sum;
        }
        int right=INT_MIN;
        sum=0;
        for(i=mid+1;i<=high;i++){
            sum+=A[i];
            if(sum>right)
                right=sum;
        }
        return left+right;
    }

public:
    int maxSubArray(int A[], int n) {
        return findMaxSubSum(A,0,n-1);
    }
};
