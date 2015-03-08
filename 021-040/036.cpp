//Valid Sudoku
//用map,然后每行每列每个大格测试
//效率不是很高
class Solution {
private:
    bool rowsOK(vector<vector<char> > &board){
        for(int i=0;i<board.size();i++){
            map<int,int> mymap;
            for(int j=0;j<board.at(i).size();j++){
                int temp=board.at(i).at(j);
                if(temp-'0'<1 || temp-'0'>9)
                    continue;
                if(mymap.find(temp)!=mymap.end()){
                    return false;
                }
                else{
                    mymap[temp]=j;
                }
            }
        }
        return true;
    }
    bool colsOK(vector<vector<char> > &board){
        for(int i=0;i<board.at(0).size();i++){
            map<int,int> mymap;
            for(int j=0;j<board.size();j++){
                int temp=board.at(j).at(i);
                if(temp-'0'<1 || temp-'0'>9)
                    continue;
                if(mymap.find(temp)!=mymap.end()){
                    return false;
                }
                else{
                    mymap[temp]=j;
                }
            }
        }
        return true;
    }
    bool gridOK(vector<vector<char> > &board){
        for(int a=0;a<3;a++){
            for(int b=0;b<3;b++){
                map<int,int> mymap;
                for(int i=a*3;i<a*3+3;i++){
                    for(int j=b*3;j<b*3+3;j++){
                        int temp=board.at(i).at(j);
                        if(temp-'0'<1 || temp-'0'>9)
                            continue;
                        int pos=(i-a*3)*3+(j-b*3);
                        if(mymap.find(temp)!=mymap.end()){
                            return false;
                        }
                        else{
                            mymap[temp]=pos;
                        }
                    }
                }
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool ok1=rowsOK(board);
        bool ok2=colsOK(board);
        bool ok3=gridOK(board);
        return ok1&&ok2&&ok3;
    }
};
