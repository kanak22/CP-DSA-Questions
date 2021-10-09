#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int main(){
    long long x,y,n;
    scanf("%lld%lld%lld",&x,&y,&n);
    int ans;
    
    //F1 = x , f2 = y , f3 = f2-f1 = y-x , f4 = f3-f2 = -x , f5 = f4-f3 = -y , f6 = f5-f4 = x-y , f7 = f6-f5 = x , f8 = f7-f6 = y
    // so one can see this is a repeting cycle ,which repetes after every 6 nos 
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
