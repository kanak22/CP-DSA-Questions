#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,M,d,c=0;
        scanf("%d",&N); M=N;
        while(N)
        {
            d=N%10;
            N=N/10;
            if(d && M%d==0) c++;
        }
        printf("%d\n",c);
    }
    return 0;
}
