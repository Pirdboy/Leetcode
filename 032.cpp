//Title:Longest Valid Parentheses
//算法来自网上:采用辅助数组length，length[i]表示以i结尾最长的合法字符串的长度。
//思想：动态规划
//那么对于一对括号( )，假设(在第j位，)在第k位，如果它们能匹配，则length[k] = length[j - 1] + (k - j + 1)。
//用一个堆栈来模拟括号匹配。
//其实连stack<char> st;都根本不用的。
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> st;
        stack<int> index;
        int maxLen=0;
        vector<int> length(s.length());
        for(int i=0;i<(int)s.length();i++){
            if(s[i]=='('){
                st.push(s[i]);
                index.push(i);
            }
            else {
                if(st.size()>0){
                    int j=index.top();
                    index.pop();
                    st.pop();
                    int k=i;
                    length[k]=length[j-1]+k-j+1;
                    if(maxLen<length[k])
                        maxLen=length[k];
                }
            }
        }
        return maxLen;
    }
};
