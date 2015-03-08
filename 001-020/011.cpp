//Title:Container With Most Water
//从两边向中间寻找,使用left和right两个指针
//看谁造成的容量缺陷,谁就移动
class Solution {
public:
    int maxArea(vector<int> &height) {
        int left=0;
        int right=height.size()-1;
        int maxarea=-1;
        while(left<right){
            int area=(right-left)*(height[left]>height[right]?height[right]:height[left]);
            if(maxarea<area)
                maxarea=area;
            if(height[left]>height[right])
                right--;
            else
                left++;
        }
        return maxarea;
    }
};
