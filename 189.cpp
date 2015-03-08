//Title:Rotate Array
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k=k%n;
        int* nums2=new int[k];
        int total=n+k;
        for(int i=total-1;i-k>=0;i--){
            if(i>n-1){
                nums2[i-n]=nums[i-k];
            }
            else{
                nums[i]=nums[i-k];
            }
        }
        for(int i=0;i<k;i++){
            nums[i]=nums2[i];
        }
        delete []nums2;
    }
};
