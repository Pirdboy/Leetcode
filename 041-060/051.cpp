//Title:N-Queens
//N皇后问题,backTracking
//《算法竞赛入门经典》上有
class Solution {
private:
    int* C; 
    void backTracking(vector<vector<string> >& answers,int cur,int n){
        if(cur==n){
            string str;
            for(int k=0;k<n;k++)
                str += ".";
            vector<string> ans;
            for(int l=0;l<n;l++){
                str[C[l]]='Q';
                ans.push_back(str);
                str[C[l]]='.';
            }
            answers.push_back(ans);
        }
        else{
            for(int i=0;i<n;i++){
                bool ok=true;
                C[cur]=i;
                for(int j=0;j<cur;j++){
                    if(C[j]==i||C[j]-j==i-cur||C[j]+j==i+cur){
                        ok=false;
                        break;
                    }
                }
                if(ok)
                    backTracking(answers,cur+1,n);
            }
        }
    }

public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > answers;
        C = new int[n];
        backTracking(answers,0,n);
        delete []C;
        return answers;
    }
};
