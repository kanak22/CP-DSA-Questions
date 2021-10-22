/*
Question Link: https://www.codechef.com/FEB20B/problems/LONGCOOK

For each test case, print a single line containing one integer: the number
of months between (m1,y1) and (m2,y2) when the Long Contest and the Cook-Off intersect.

Approach: Brute force approach will be to iterate all the months from (m1,y1) to (m2,y2) to find the result.
However, as year can be as large as 10^9, this will lead to TLE

Optimum Solution: We observe that there is a repetition of a pattern which occurs for every 400 years.
Hence we use prefix sum to calculate the result for years from 0 to 400 and then use simple maths to get
the desired output.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
//Code by Shrey Rai
#define mod 1000000007

ll time1[]={0,3,2,5,0,3,5,1,4,6,2,4};


ll fun(ll y)
{
    ll d=1,m=2;
    y -= m < 3;
    ll p= (y+y/4-y/100+y/400+time1[m-1]+d)%7;
    return p;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t,m1,m2,y1,y2,i,j,c1,c2,i1,i2,p1,p2;
    cin>>t;
    ll v[1000001];


    memset(v,0,sizeof(v));
    ll a[104]={3,9,14,15,20,25,26,31,37,42,43,48,53,54,59,
    65,70,71,76,81,82,87,93,98,99,105,110,111,116,121,122,127,
    133,138,139,144,149,150,155,161,166,167,172,177,178,183,189,
    194,195,200,201,206,207,212,217,218,223,229,234,235,240,245,
    246,251,257,262,263,268,273,274,279,285,290,291,296,302,303,308,
    313,314,319,325,330,331,336,341,342,347,353,358,359,364,369,370,375,
    381,386,387,392,397,398,403,409,414};
    //These are the required months in which the Long contest and cookoff overlap
    //This pattern repeats after every 400 years

     for(i=0;i<104;i++)
    {
       for(j=0;j<=5;j++)
       v[a[i]+j*400]=1;
    }

    ll pre[100000];
    memset(pre,0,sizeof(pre));
    for(i=1;i<100000;i++)
    pre[i]=pre[i-1]+v[i];



    while(t--)
    {
        cin>>m1>>y1;
        cin>>m2>>y2;
        if(m1<=2)
            y1--;
        if(m2<2)
            y2--;
        p2=(y2)/400;
        if(p2>0){
        i2=p2*400;
        c2=p2*101;
        }
        else
        {
            i2=0;
            c2=0;
        }
        p1=(y1/400);
        if(p1>0){
        i1=p1*400;
        c1=p1*101;

        }
        else
        {
            c1=0,i1=0;
        }
        ll day;
        for(i=i2;i<=y2;i++)
        {

            if((i%4==0 && i%100!=0)||(i%400==0))
            {
                day=fun(i);
                if(day==6)
                 c2++;

            }
            else
            {
                day=fun(i);
                if(day==0 || day==6)
                    c2++;
            }
        }

        for(i=i1;i<=y1;i++)
        {

            if((i%4==0 && i%100!=0)||(i%400==0))
            {
                if(fun(i)==6)
                 c1++;

            }
            else
            {
                day=fun(i);
                if(day==0 || day==6)
                    c1++;
            }
        }
        cout<<abs(c2-c1)<<"\n";

    }

    return 0;
}

/*
Time Complexity: O(ceil(y/4000) or each test case after the initial precalculation.
Space Complexity: Constant
*/
