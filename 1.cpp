#include <iostream>
#include <vector>
#include <map>
using namespace std;
//Title:Two Sum
//利用哈希表的查找在常数时间内,
//这里用的C++ STL的map,在实际情况不够用时才换成hash_map
//但hash_map还不是C++ STL中内容
//可以使用Java中的hashtable
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        map<int,int> nums;
        for(int i=0;i<numbers.size();i++)
        {
			//哈希表并不能添加重复元素,
			//所以需要特别处理一下
            if(nums.find(numbers[i])==nums.end()){
                nums[numbers[i]]=i;
            }
			
            if(nums.find(target-numbers[i])!=nums.end()){
                int a=nums[target-numbers[i]];
                int b=i;
				//a<b保证找到的两个加数不是处于同一位置的一个数
                if(a<b){
                    result.push_back(a+1);
                    result.push_back(b+1);
                    return result;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);
    v.push_back(15);
    int target=6;
    vector<int> v2 = s.twoSum(v,target);
    cout << v2[0] << " " << v2[1] << endl;
    return 0;
}
