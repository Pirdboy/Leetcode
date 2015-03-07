//Title:Rotate Image
//用C语言提交
//矩阵顺时针旋转90度
//http://blog.csdn.net/pickless/article/details/9838093
class Solution {
public:
    void rotate(int **matrix, int n) {
        int s=n-1;
        int i,j;
        for(i=0;i<=s;i++){
            for(j=i;j<s-i;j++){
                int x=i,y=j,t;
                int k,prev=matrix[x][y],next;
                for(k=0;k<4;k++){
                    next=matrix[y][s-x];
                    matrix[y][s-x]=prev;
                    prev=next;
                    
                    t=s-x;
                    x=y;
                    y=t;
                }
            }
        }
    }
};
