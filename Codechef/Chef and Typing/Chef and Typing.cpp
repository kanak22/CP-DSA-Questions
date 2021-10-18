// Link to the question -> https://www.codechef.com/SDPCB21/problems/TYPING

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {    // Test cases
        int n;
        cin >> n;
        unordered_map<string, pair<int, int>> words;    // pair of input string and pair of its count and time taken
        unordered_map<char, bool> hands = {{'d', 0}, {'f', 0}, {'j', 1}, {'k', 1}};   // Made to check if the hands are same or changed
        while(n--) {
            string word;
            cin >> word;
            words[word] = {words[word].first + 1, 0};
        }
        for(auto &it: words) {
            string word = it.first;
            int time = 0;
            for(int i = 0; i < word.size(); ++i) {
                if(i == 0) time += 2;
                else {
                    if(hands[word[i]] == hands[word[i-1]]) time += 4;
                    else time += 2;
                }
            }
            it.second.second = time;
        }
        int totalTime = 0;
        for(auto &it: words) {
            totalTime += it.second.second;
            if(it.second.first > 1) {
                totalTime += ((it.second.second / 2) * (it.second.first - 1));
            }
        }
        cout << totalTime << endl;
    }
}
