//Title:Largest Number
//可以换一下思路，要想比较两个数在最终结果中的先后位置，何不直接比较一下不同组合的结果大小？
//举个例子：要比较3和34的先后位置，可以比较334和343的大小，而343比334大，所以34应当在前。
//这样，有了比较两个数的方法，就可以对整个数组进行排序。然后再把排好序的数拼接在一起就好了。
class Solution {
private:
    static int cmp(const string& a,const string& b){
        string ab=a+b;
        string ba=b+a;
        long long numAB,numBA;
        stringstream ss;
        ss << ab;
        ss >> numAB;
        ss.clear();
        ss << ba;
        ss >> numBA;
        ss.clear();
        if(numAB>numBA)
            return 1;
        else
            return 0;
    }

public:
    string largestNumber(vector<int> &num) {
        if(num.size()==0)
            return string("0");
        vector<string> strs;
        for(int i=0;i<num.size();i++){
            string s;
            stringstream ss;
            ss << num[i];
            ss >> s;
            strs.push_back(s);
            ss.clear();
        }
        sort(strs.begin(),strs.end(),cmp);
        string ans;
        for(int i=0;i<strs.size();i++)
            ans += strs[i];
        if(ans[0]=='0')
            return string("0");
        return ans;
    }
};
