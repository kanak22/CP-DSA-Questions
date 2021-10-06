#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int main(){
    long long x,y,n;
    scanf("%lld%lld%lld",&x,&y,&n);
    int ans;
    if(n%6==1){
        ans=x;
    }
    else if(n%6==2){
        ans=y;
    }
    else if(n%6==3){
        ans=y-x;
    }
    else if(n%6==4){
        ans=-x;
    }
    else if(n%6==5){
        ans=-y;
    }
    else if(n%6==0){
        ans=x-y;
    }
    if((ans%1000000007)<0){
        printf("%d",(1000000007+(ans%1000000007)));
    }
    else{
        printf("%d",(ans%1000000007));
    }
    return 0;
}
