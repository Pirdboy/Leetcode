//Title:Jump Game
//same as Jump Game II
bool canJump(int A[], int n) {
    if(n==1)
        return true;
    bool ok=false;
    int i=0,maxPos,max,newPos,j;
    while(i<n){
        maxPos=i+A[i];
        if(maxPos>=n-1){
            ok = true;
            break;
        }
        max=0;
        newPos=0;
        for(j=0;maxPos-j>i;j++){
            if(A[maxPos-j]-j>max){
                max=A[maxPos-j]-j;
                newPos=maxPos-j;
            }
        }
        i=newPos;
        if(max==0){
            ok=false;
            break;
        }
    }
    return ok;
}