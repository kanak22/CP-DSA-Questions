/**
 * link to Question (https://www.hackerrank.com/challenges/variable-sized-arrays/problem)
**/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n ,queries , k, element ;
    
    cin>> n ; // taking number of inputs 
    cin>>queries; 
    
    vector <int> arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>k;
        for ( int j = 0 ; j <k; j++)
        {
            cin>>element;
            arr[i].push_back(element);
        }
    }
    
    int p ,q ;
    
  for ( int i = 0 ; i < queries ; i++)
  {
      cin>>p>>q;
      cout<<arr[p][q]<<endl;
      
  }
  
    return 0 ;
}
