//Title:Search for a Range
//二分查找的写法，对于target处于两边，和不在数组中的情况
//真没有找到一个好的通用的写法，只能单独处理
//还有就是只有一个元素的时候，也是单独写的
//希望能改进一下
class Solution {
public:
    int binarySearch(int A[],int n,int target){
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
            if(left==right)
                break;
        }
        return mid;
    }
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> answers(2);
        int pos=binarySearch(A,n,target);
        if(pos>=0)
        {
            int start=-1;
            int end=-1;
            int i;
            for(i=pos;i>=0;i--){
                if(A[i]!=target){
                    break;
                }
            }
            start=i+1;
            for(i=pos;i<n;i++){
                if(A[i]!=target){
                    break;
                }
            }
            end=i-1;
            answers[0]=start;
            answers[1]=end;
        }
        else{
            answers[0]=-1;
            answers[1]=-1;
        }
        return answers;
    }
};