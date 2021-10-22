#include <iostream>
 
using namespace std;
 
int main(){
    long int n;
    int d;
    cin >> n >> d;
    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int counter = 0;
    
    for (int i = 0; i < n; i++){    //we need three for loops so as to keep track of three values
        for (int j = i+1; j < n; j++){  //as i < j always
            if (arr[j] - arr[i] > d){
                break;
            }
            for (int k = j+1; k < n; k++){  //as i < j < k always 
                if (arr[k] - arr[j] > d){
                    break;
                }
                if ((arr[j] - arr[i] == d) && (arr[k] - arr[j] == d)){
                    counter++;  //if the condition given is true then we increment the counter variable 
                }
            }
        }
    }

    cout << counter << endl;    //printing the result
    return 0;
}
