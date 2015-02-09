//Title:3Sum
//O(n^2)
class Solution {
public:
    int cmp(const int& a,const int& b){
        return a<b;
    }

    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(),num.end());
        vector<vector<int> > answers;
        for(int i=0;i<(int)num.size()-1;i++){
            if(i>0 && num[i]==num[i-1])
                continue;
            int left=i+1;
            int right=num.size()-1;
            while(left<right){
                if(num[left]+num[right]==-num[i]){
                    bool notExist=false;
                    if(answers.size()<=0)
                        notExist=true;
                    else{
                        int a=answers[answers.size()-1].at(0);
                        int b=answers[answers.size()-1].at(1);
                        int c=answers[answers.size()-1].at(2);
                        if(a!=num[i] || b!=num[left] || c!=num[right]){
                            notExist=true;
                        }
                    }
                    if(notExist){
                        vector<int> answer;
                        answer.push_back(num[i]);
                        answer.push_back(num[left]);
                        answer.push_back(num[right]);
                        answers.push_back(answer);
                    }
                    left++;right--;
                }
                else if(num[left]+num[right]>-num[i]){
                    right--;
                }
                else if(num[left]+num[right]<-num[i]){
                    left++;
                }
            }
        }
        return answers;
    }
};
