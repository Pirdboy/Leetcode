#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

//Title:Palindrome Number
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        else if(x==0)
            return true;
        stringstream ss;
        string num;
        ss << x;
        ss >> num;
        int len=num.length();
        bool ok=true;
        for(int i=0;i<(int)num.length()/2;i++){
            if(num[i]!=num[len-1-i]){
                ok=false;break;
            }
        }
        return ok;
    }
};

int main(){
    Solution s;
    int x=123454321;
    cout << s.isPalindrome(x) << endl;
    return 0;
}
