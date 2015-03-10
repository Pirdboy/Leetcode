//Title:Spiral Matrix II
class Solution {
private:
    int dr[4]={0,1,0,-1};
    int dc[4]={1,0,-1,0};
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > answers;
        for(int i=0;i<n;i++){
            vector<int> ans(n);
            answers.push_back(ans);
        }
        int count=1;
        int i=0,j=0;
        int dir=0,upBound=-1,downBound=n,leftBound=-1,rightBound=n;
        while(count<=n*n){
           answers[i][j]=count;
           if(j+dc[dir]>=rightBound){
               upBound++;
               dir = (dir+1)%4;
           }
           else if(i+dr[dir]>=downBound){
               rightBound--;
               dir = (dir+1)%4;
           }
           else if(j+dc[dir]<=leftBound){
               downBound--;
               dir = (dir+1)%4;
           }
           else if(i+dr[dir]<=upBound){
               leftBound++;
               dir = (dir+1)%4;
           }
           i = i+dr[dir];
           j = j+dc[dir];
           count++;
        }
        return answers;
    }
};
