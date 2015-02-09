//Title:Implement strStr()
//字符串匹配有很多著名的算法，比如KMP算法
//但是在面试时，暴力法是最直接也是最容易实现的
//O(nm)的时间,O(1)的空间
//另外面试时特殊情况尽量不要单独处理
class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int len1=strlen(haystack);
        int len2=strlen(needle);
        if(len2>len1)
            return -1;
        bool ok=true;
        int i;
        for(i=0;i<len1-len2+1 && i<len1;i++){
            ok=true;
            int j;
            for(j=0;j<len2;j++){
               if(haystack[i+j]!=needle[j]){
               		ok=false;
               }
            }
            if(ok){
                break;
            }
        }
        if(ok)
            return i;
        else
            return -1;
    }
};
