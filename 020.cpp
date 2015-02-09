//Title:Valid Parentheses
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }
            else if(s[i]==')'||s[i]=='}'||s[i]==']'){
                if(st.size()<=0)
                    return false;
                else{
                    char pa=st.top();
                    st.pop();
                    if((pa=='('&&s[i]==')')||(pa=='['&&s[i]==']')||(pa=='{'&&s[i]=='}')){

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
};
