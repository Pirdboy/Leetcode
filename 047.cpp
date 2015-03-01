//Title:Permutations II
//下一个排列算法,加上去重
class Solution {
private:
    void swap(vector<int>& num,int i,int j){
        int t=num[i];
        num[i]=num[j];
        num[j]=t;
    }
    bool havePermute(vector<int>& num){
        int i=-1;
        bool ok=false;
        for(i=num.size()-1;i>0;i--){
            if(i-1>=0 && num[i]>num[i-1]){
                break;
            }
        }
        if(i<=0){
            return false;
        }
        else{
            for(int k=num.size()-1;k>=i;k--){
                if(num[k]>num[i-1]){
                    swap(num,k,i-1);
                    break;
                }
            }
            int len=num.size()-i;
            for(int j=0;j<len/2;j++)
                swap(num,i+j,i+len-1-j);
            return true;
        }
    }
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(),num.end());
        vector<vector<int> > answers;
        answers.push_back(num);
        while(true){
            bool ok=havePermute(num);
            if(ok){
                vector<int>& last = answers[answers.size()-1];
                bool repeat=true;
                for(int a=0;a<last.size();a++){
                    if(last[a]!=num[a]){
                        repeat=false;
                        break;
                    }
                }
                if(!repeat)
                    answers.push_back(num);
            }
            else
                break;
        }
        return answers;
    }
};
