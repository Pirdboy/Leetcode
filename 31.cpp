//Title:Next Permutation
//这里直接用的STL中next_permutation过的
//但最好不要这样干
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        bool ok=next_permutation(num.begin(),num.end());
        if(!ok)
            sort(num.begin(),num.end());
    }
};

//下一个排列的算法:
//对当前排列从后向前扫描，找到一对为升序的相邻元素，记为i和j（i < j）。如果不存在这样一对为升序的相邻元素，则所有排列均已找到，算法结束；否则，重新对当前排列从后向前扫描，找到第一个大于i的元素k，交换i和k，然后对从j开始到结束的子序列反转，则此时得到的新排列就为下一个字典序排列。这种方式实现得到的所有排列是按字典序有序的，这也是C++ STL算法next_permutation的思想。
class Solution {
public:
    void swap(vector<int> &num,int i,int j){
        int t=num[i];
        num[i]=num[j];
        num[j]=t;
    }

    void nextPermutation(vector<int> &num) {
        int n=-1;
        for(int i=num.size()-1;i>0;i--){
            if(num[i]>num[i-1]){
                n=i;
                break;
            }
        }
        if(n!=-1){
            int k=-1;
            for(k=num.size()-1;k>=0;k--){
                if(num[k]>num[n-1]){
                    swap(num,k,n-1);
                    break;
                }
            }
            reverse(num.begin()+n,num.end());
        }
        else{
            reverse(num.begin(),num.end());
        }
    }
};
