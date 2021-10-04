/*Question link:
https://www.hackerrank.com/challenges/inherited-code/problem*/
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

/*In this below section we are asked to create an exception
when the username is too short when the user name is too short we create an exception 
and print Too Short and size of the string*/

class BadLengthException{
    private:
      int n;
    public:  
      BadLengthException(int error)
      {
          n=error;
      }
      int what()
      {
          return n;
      }
    
};


bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}


/*Sample Input:
3
Peter
Me
Arxwwz
Sample output:
Valid
Too short: 2
Invalid*/
