#include <iostream>
#include <cstring>
using namespace std;

//Title:Longest Substring Without Repeating Characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		//这是O(n^2)的算法
//	    bool exist[300]={false};
//		int max_length=0;
//	    for(int i=0;i<s.length();i++){
//		    int j;
//			for(j=i;j<s.length();j++){
//				if(exist[s[j]]){
//					break;
//				}
//				else{
//					exist[s[j]]=true;
//				}
//			}
//			if(j-i>max_length){
//				max_length=j-i;
//			}
//			memset(exist,false,sizeof(exist));
//		}
		//这是O(n)的算法
		int last_pos[300];
        memset(last_pos,-1,sizeof(last_pos));
        int max_length=0;
        int i=-1;
        for(int j=0;j<s.length();j++){
            if(last_pos[s[j]]>i)
                i=last_pos[s[j]];
            if(j-i>max_length)
                max_length=j-i;
            last_pos[s[j]]=j;
        }
		return max_length;
    }
};


int main(){
    Solution s;
    string str="abcabcbb";
    cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
}
