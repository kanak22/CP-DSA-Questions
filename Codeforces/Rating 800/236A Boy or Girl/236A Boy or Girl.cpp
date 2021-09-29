#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
   string s;
   cin>>s;
   
   set<int,greater <int>> s1;
   for(int i=0; i<s.length(); i++)
   {
      s1.insert(s[i]);
   }
   int count = s1.size();
   if(count%2==0)
   {
       cout<<"CHAT WITH HER!"<<endl;
   }
   else{
       cout<<"IGNORE HIM!"<<endl;
   }
   
    return 0;
}


// ============OR=============

// #include <bits/stdc++.h>
 
// using namespace std;
 
// int main()
// {
//    string s;
//    cin>>s;
//    int count=0;
//    sort(s.begin(),s.end());
//    for(int i=0; i<s.length(); i++)
//    {
//         if(s[i]!=s[i+1])
//            {
//                count++;
//            }
//    }
   
//    if(count%2==0)
//    {
//        cout<<"CHAT WITH HER!"<<endl;
//    }
//    else{
//        cout<<"IGNORE HIM!"<<endl;
//    }
   
//     return 0;
// }