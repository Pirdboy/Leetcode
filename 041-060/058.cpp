//Title:Length of Last Word
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len=strlen(s);
        int count=0;
        for(int i=len-1;i>=0;i--){
            if(s[i]!=' '){
                int j;
                for(j=i;j>=0 && s[j]!=' ';j--){
                    count++;
                }
                break;
            }
        }
        return count;
    }
};
