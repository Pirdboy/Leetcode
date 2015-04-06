//Title:Plus One
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        reverse(digits.begin(),digits.end());
        vector<int> ans;
        int c=1;
        for(int i=0;i<digits.size();i++){
            int temp=digits[i];
            digits[i]=(digits[i]+c)%10;
            if(temp+c>=10)
                c=1;
            else
                c=0;
            ans.push_back(digits[i]);
        }
        if(c==1)
            ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
