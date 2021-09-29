#include <iostream>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    int qno=0;
    while(t--){
        int a[3],count=0;
        for(int i=0; i<3; i++)
        {
            cin>>a[i];
            if(a[i]==1)
            {
                count++;
            }
        }
        if(count>=2)
        {
            qno++;
        }
    }
    cout<<qno<<endl;
    return 0;
}