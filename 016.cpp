//Title:3Sum Closest
//与15题类似3Sum
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        int dis=-1;
        int sum=0;
        for(int i=0;i<(int)num.size()-2;i++){
            int left=i+1;
            int right=num.size()-1;
            while(left<right){
                int temp=num[i]+num[left]+num[right];
                int temp_dis=temp-target;
                if(temp_dis<0){
                    temp_dis=-temp_dis;
                }
                else if(temp_dis==0){
                    return temp;
                }
                if(dis==-1 || temp_dis<dis){
                    dis=temp_dis;
                    sum=temp;
                }
                if(temp>target){
                    right--;
                }
                else if(temp<target){
                    left++;
                }
            }
        }
        return sum;
    }
};
