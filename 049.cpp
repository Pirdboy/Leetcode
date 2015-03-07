//Title:Anagrams
//哈希表,map
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string,int> myMap;
        vector<string> ans;
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            if(myMap.find(s)==myMap.end()){
                myMap[s]=i;
            }
            else{
                if(myMap[s]>=0){
                    ans.push_back(strs[myMap[s]]);
                }
                myMap[s]=-1;
                ans.push_back(strs[i]);
            }
        }
        return ans;
    }
};
