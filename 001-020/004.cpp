//Title:Median of Two Sorted Arrays
//比较有难度的一道题
//找出第k大元素的通用思想：
//如果A[k/2-1]<B[k/2-1],那么我们可以确定A[0]~A[k/2-1]一定在前k大的元素序列当中
//从而可以排除掉这一部分,再将A的剩余元素拿来和B继续进行这样的比较
//如果A[k/2-1]==B[k/2-1],那么A[k/2-1]就是第k大的元素
//边界处理：
//一、考虑到k可能为奇数，具体实现应该如下:
//int countA=k/2,countB=k-countA;
//然后比较A[countA-1]和B[countB-1]即可
//二、由于countA可能大于数组本身长度m，所以countA=Min(countA,m)
//三、我们始终保持m<n，可以避免对countB的讨论的麻烦
//四、其中A[]为空，则直接返回B[k-1]
//五、当k==1,则只需返回A[0]和B[0]的最小值
class Solution {
private:
    int Min(int a,int b){
        return a>b?b:a;
    }

    int findKthElement(int A[],int m,int B[],int n,int k){
        if(m>n)
            return findKthElement(B,n,A,m,k);
        if(m==0){
            return B[k-1];
        }
        if(k==1)
            return Min(A[0],B[0]);
        int countA=Min(k/2,m);
        int countB=k-countA;
        if(A[countA-1]<B[countB-1])
            return findKthElement(A+countA,m-countA,B,n,k-countA);
        else if(A[countA-1]==B[countB-1])
            return A[countA-1];
        else
            return findKthElement(A,m,B+countB,n-countB,k-countB);
    }

public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if((m+n)%2==1)
            return (double)findKthElement(A,m,B,n,(m+n)/2+1);
        else{
            int a=findKthElement(A,m,B,n,(m+n)/2);
            int b=findKthElement(A,m,B,n,(m+n)/2+1);
            return ((double)a+(double)b)/2.0;
        }
            
    }
};

