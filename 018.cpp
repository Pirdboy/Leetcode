//Title:4Sum
//O(n^3)
//其中利用C++ STL中set集合模板，以及将数据以字符形式存储到字符串中来去重的方法比较巧妙
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        vector<vector<int> >answers;
        set<string> strs;
        vector<int> ans(4);
        for(int i=0;i<(int)num.size()-3;i++){
            for(int j=i+1;j<(int)num.size()-2;j++){
                int left=j+1;
                int right=num.size()-1;
                int tmp=target-num[i]-num[j];
                while(left<right){
                    int sum=num[left]+num[right];
                    if(sum==tmp){
                        string str;
                        str += num[i];
                        str += num[j];
                        str += num[left];
                        str += num[right];
                        if(strs.find(str)==strs.end()){
                            ans[0]=num[i];
                            ans[1]=num[j];
                            ans[2]=num[left];
                            ans[3]=num[right];
                            answers.push_back(ans);
                            strs.insert(str);
                        }
                        left++;
                        right--;
                    }
                    else if(sum>tmp){
                        right--;
                    }
                    else if(sum<tmp){
                        left++;
                    }
                }
            }
        }
        return answers;
    }
};
