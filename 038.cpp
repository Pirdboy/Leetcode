//Title:Count and Say
class Solution {
private:
    string getNext(string str){
        string temp="";
        for(int i=0;i<(int)str.length();i++){
            char c=str[i];
            int j;
            int count=0;
            for(j=i;j<(int)str.length() && str[j]==c;j++){
                count++;
            }
            stringstream ss;
            ss << count;
            string countStr;
            ss >> countStr;
            ss.clear();
            temp.append(countStr);
            temp += c;
            i=j-1;
        }
        return temp;
    }

public:
    string countAndSay(int n) {
        string se="1";
        int count=1;
        while(count<n){
            se=getNext(se);
            count++;
        }
        return se;
    }
};
