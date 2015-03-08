//Title:Letter Combinations of a Phone Number
// Backtracking...
class Solution {
private:
    string letters[10];
public:
    Solution(){
        letters[0]="";
        letters[1]="";letters[2]="abc";letters[3]="def";
        letters[4]="ghi";letters[5]="jkl";letters[6]="mno";
        letters[7]="pqrs";letters[8]="tuv";letters[9]="wxyz";
    }

    void search(int cur,string ans,const string& digits,vector<string>& answers){
        if(cur==digits.length()){
            answers.push_back(ans);
        }
        else{
            int digit=digits[cur]-'0';
            for(int i=0;i<letters[digit].length();i++){
                search(cur+1,ans+letters[digit].at(i),digits,answers);
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> answers;
        string ans="";
        search(0,ans,digits,answers);
        return answers;
    }
};
