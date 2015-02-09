#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

//Title:Longest Palindromic Substring
class Solution {
public:
    string longestPalindrome(string s) {
		//O(n^2)的算法a,枚举中点,从中间向两边展开,注意偶数与奇数的不同
        int max_length=-1;
        int start=0;
        int end=0;
        int i,j;
        for(i=0;i<(int)s.length();i++){
            for(j=0;i-j>=0 && i+j+1<(int)s.length();j++){
                if(s[i-j]!=s[i+j+1])
                    break;
            }
            j--;
            int left=i-j,right=i+j+1;
            if(right-left+1>max_length){
                start=left;
                end=right;
                max_length=right-left+1;
            }
            for(j=0;i-j>=0 && i+j<(int)s.length();j++){
                if(s[i-j]!=s[i+j])
                    break;
            }
            j--;
            left=i-j,right=i+j;
            if(right-left+1>max_length){
                start=left;
                end=right;
                max_length=right-left+1;
            }
        }
        string result=s.substr(start,end-start+1);
        return result;
    }
};

int main(){
    Solution s;
    string str="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    string str2="aaabaavv";
    cout << s.longestPalindrome(str2) << endl;
    //cout << str2.substr(1,3) << endl;
    return 0;
}
