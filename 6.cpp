#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

//Title:ZigZag Conversion
class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows==1)
            return s;
        string* strs = new string[nRows];
        int p=0;
        int dir=1;
        for(int i=0;i<(int)s.length();i++)
        {
            if(p==0 && dir==-1)
                dir=1;
            else if(p==nRows-1 && dir==1)
                dir=-1;
            strs[p] = strs[p]+s[i];
            p+=dir;
        }
        string re="";
        for(int j=0;j<nRows;j++)
            re+=strs[j];
        delete []strs;
        return re;
    }
};

int main(){
    Solution s;
    string str="AB";
    int rows=1;
    cout << s.convert(str,rows) << endl;
    return 0;
}
