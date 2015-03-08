//Title:Combination Sum 
//回朔
class Solution {
private:
    void backTracking(vector<vector<int> >& answers,vector<int>& ans,int index,vector<int> &candidates,int target){
        if(target==0){
            answers.push_back(ans);
            return;
        }
        if(index==candidates.size() || candidates[index]>target)
            return;
        for(int i=target/candidates[index];i>=0;i--)
            ans.push_back(candidates[index]);
        for(int i=target/candidates[index];i>=0;i--){
            ans.pop_back();
            backTracking(answers,ans,index+1,candidates,target-i*candidates[index]);
        }
    }

public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>::iterator pos = unique(candidates.begin(), candidates.end());  
        candidates.erase(pos, candidates.end());  
        vector<vector<int> > answers;
        vector<int> ans;
        backTracking(answers,ans,0,candidates,target);
        return answers;
    }
};
