//Title:Longest Common Prefix
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size()<=0)
            return "";
        else if(strs.size()==1)
            return strs[0];
        int minLen=strs[0].length();
        for(int i=1;i<(int)strs.size();i++){
            if(minLen>(int)strs[i].length()){
                minLen=strs[i].length();
            }
        }
        for(int i=minLen;i>0;i--){
            string temp=strs[0].substr(0,i);
            bool ok=true;
            for(int ii=1;ii<(int)strs.size();ii++){
                string temp2=strs[ii].substr(0,i);
                if(temp!=temp2){
                    ok=false;
                    break;
                }
            }
            if(ok){
                return temp;
            }
        }
        return "";
    }
};
