//Title:Spiral Matrix
class Solution {
private:
    int dr[4];//={0,1,0,-1};  //非静态成员的直接初始化从C++11开始是可以的了。
    int dc[4];//={1,0,-1,0};
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        dr[0]=0;dr[1]=1;dr[2]=0;dr[3]=-1;
        dc[0]=1;dc[1]=0;dc[2]=-1;dc[3]=0;
        vector<int> ans;
        if(matrix.size()==0)
            return ans;
        int rowCount=matrix.size();
        int colCount=matrix[0].size();
        int count=0;
        int i=0,j=0;
        int dir=0,upBound=-1,downBound=rowCount,leftBound=-1,rightBound=colCount;
        while(count<rowCount*colCount){
            ans.push_back(matrix[i][j]);
            if(j+dc[dir]>=rightBound){
                upBound++;
                dir=(dir+1)%4;
            }
            else if(i+dr[dir]>=downBound){
                rightBound--;
                dir=(dir+1)%4;
            }
            else if(j+dc[dir]<=leftBound){
                downBound--;
                dir=(dir+1)%4;
            }
            else if(i+dr[dir]<=upBound){
                leftBound++;
                dir=(dir+1)%4;
            }
            i = i+dr[dir];
            j = j+dc[dir];
            count++;
        }
        return ans;
    }
};
