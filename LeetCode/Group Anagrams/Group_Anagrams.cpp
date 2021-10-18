#include<bits/stdc++.h>

using namespace std;

// Function to group the anagrams from the a given string
vector<vector<string>> groupAnagrams(vector<string> strs) {
    // map which stores the groups of anagrams in which the sorted string
    // is the key
    unordered_map<string, vector<string>> mp;
    for(string str : strs) {
        string sorted_str = str;
        sort(sorted_str.begin(), sorted_str.end());
        mp[sorted_str].push_back(str);
    }

    vector<vector<string>> anagrams;
    for(auto s : mp) {
        anagrams.push_back(s.second);
    }

    return anagrams;
}

// Driver Code
int main() {

    // Input string
    vector<string> strs{"eat","tea","tan","ate","nat","bat"};
    // Groups of Anagrams are stored in a 2D vector
    vector<vector<string>> anagrams = groupAnagrams(strs);

    for(vector<string> anagram : anagrams) {
        cout << "Anagram : ";
        for(string str : anagram) {
            cout << str << " ";
        }
        cout << "\n";
    }

    return 0;
}