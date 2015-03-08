//Title:Multiply Strings
//大整数乘法,其中会用到大整数加法
class Solution {
private:
    string add(string n1re,string n2re){
        if(n1re.length()==0)
            return n2re;
        if(n2re.length()==0)
            return n1re;
        int i=0;
        int c=0;
        string ans="";
        while(i<n1re.length() || i<n2re.length()){
            int a=0;
            int b=0;
            if(i<n1re.length())
                a=n1re[i]-'0';
            if(i<n2re.length())
                b=n2re[i]-'0';
            int re=a+b+c;
            int tail=re%10;
            c=re/10;
            ans += (char)(tail+'0');
            i++;
        }
        if(c>0)
            ans += (char)(c+'0');
        return ans;
    }
    string delZero(string str){
        int i;
        for(i=0;i<str.length();i++)
            if(str[i]!='0')
                break;
        if(i==str.length())
            return "0";
        return str.substr(i,str.length()-i);
    }
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string ans="0";
        for(int i=0;i<(int)num2.length();i++){
            string re="";
            for(int ii=0;ii<i;ii++)
                re += "0";
            int c=0;
            int a=num2[i]-'0';
            for(int j=0;j<(int)num1.length();j++){
                int b=num1[j]-'0';
                int m=a*b+c;
                int tail=m%10;
                c=m/10;
                re += (char)(tail+'0');
            }
            if(c>0)
                re += (char)(c+'0');
            ans = add(ans,re);
        }
        reverse(ans.begin(),ans.end());
        ans=delZero(ans);
        return ans;
    }
};
