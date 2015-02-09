#include <iostream>
#include <sstream>
#include <climits>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

//Title:Reverse Integer
class Solution {
public:
    int reverse(int x) {
        if(x==0)
            return x;
        bool negative=false;
        if(x<0){
            negative=true;
            x=-x;
        }
		//重点注意C++的int与string转换,stringstream
		//每次转换完成需要clear()
        stringstream ss;
        string numstr;
        ss << x;
        ss >> numstr;
        int end=numstr.length();
        for(;end>0;end--){
            if(numstr[end-1]>='1' && numstr[end-1]<='9')
                break;
        }
        string numstr2=numstr.substr(0,end);
        std::reverse(numstr2.begin(),numstr2.end());
        long long x2;
        ss.clear();
        ss << numstr2;
        ss >> x2;
        if((negative && x2>INT_MAX-1)||(!negative && x2>INT_MAX)){
            return 0;
        }
        else{
            if(negative)
                x2 = -x2;
            return static_cast<int>(x2);
        }
    }
};

int main(){
    Solution s;
    int x=-1000000090;
    cout << s.reverse(x) << endl;
    return 0;
}
