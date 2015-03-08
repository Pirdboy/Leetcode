//Title:Combination Sum II
class Solution {
private:
    set<string> tests;
    void backTracking(vector<vector<int> >& answers,vector<int>& ans,string data,int index,vector<int>& num,int target){
        if(target==0){
            if(tests.find(data)==tests.end()){
                answers.push_back(ans);
                tests.insert(data);
            }
            return;
        }
        if(index==num.size() || num[index]>target){
            return;
        }
        string temp;
        stringstream ss;
        ss << num[index];
        ss >> temp;
        ss.clear();
        ans.push_back(num[index]);
        backTracking(answers,ans,data+"."+temp,index+1,num,target-num[index]);
        ans.pop_back();
        backTracking(answers,ans,data,index+1,num,target);
    }

public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        vector<int> ans;
        vector<vector<int> > answers;
        string data="";
        backTracking(answers,ans,data,0,num,target);
        return answers;
    }
};
