#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <climits>
#include <cstring>
using namespace std;

//Title:String to Integer(atoi)
class Solution {
public:   
    int atoi(const char *str) {
        string num="";
        int len=strlen(str);
        if(len<=0)
            return 0;
        int start=-1;
        for(int i=0;i<len;i++){
            if(str[i]==' '){
                continue;
            }
            else if(!isdigit(str[i]) && str[i]!='+' && str[i]!='-'){
                return 0;
            }
            else {
                start=i;break;
            }
        }
        if(start<0)
            return 0;
        if(str[start]=='+'||str[start]=='-'){
            num = num + str[start];
            bool valid=false;
            for(int j=start+1;j<len;j++){
                if(!valid && !isdigit(str[j])){
                    return 0;
                }
                else if(valid && !isdigit(str[j])){
                    break;
                }
                else{
                    num = num + str[j];
                    if(!valid)
                        valid=true;
                }
            }
        }
        else if(isdigit(str[start])){
            num = num + str[start];
            for(int j=start+1;j<len;j++){
                if(!isdigit(str[j])){
                    break;
                }
                else{
                    num = num + str[j];
                }
            }
        }
        long long result;
        stringstream ss;
        ss << num;
        ss >> result;
        ss.clear();
        if(result>INT_MAX)
            return INT_MAX;
        if(result<INT_MIN)
            return INT_MIN;
        return result;
    }
};

int main(){
    Solution s;
    char* x="+1";
    cout << s.atoi(x) << endl;
    return 0;
}
