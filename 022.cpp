//Title:Generate Parentheses
//使用回溯（递归枚举）出所有情况，然后用20题的代码判断是否括号匹配
//效率不是很高。
class Solution {
public:
    void search(string par,int cur,int leftN,int rightN,int n,vector<string>& answers){
        if(cur==2*n){
            //check
            if(leftN==n && rightN==n){
                if(isValid(par)){
                    answers.push_back(par);
                }
            }
            else{
                return;
            }
        }
        else if(leftN>n || rightN>n){
            return;
        }
        else{
            search(par+'(',cur+1,leftN+1,rightN,n,answers);
            search(par+')',cur+1,leftN,rightN+1,n,answers);
        }
    }
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                if(st.size()<=0)
                    return false;
                else{
                    char pa=st.top();
                    st.pop();
                    if(pa=='('&&s[i]==')'){
                        
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        if(st.size()>0)
            return false;
        return true;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> answers;
        string pa="(";
        search(pa,1,1,0,n,answers);
        return answers;
    }
};
