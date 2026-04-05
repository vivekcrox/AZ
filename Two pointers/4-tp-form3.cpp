#include<iostream>
using namespace std;

#define int long long

// 1. 392. Is Subsequence
// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

bool isSubsequence(string s, string t) {
    
    int n = s.length();
    int m = t.length();

    int i=0, j=0;
    while(i < n && j < m) {
        if(s[i] == t[j]) {
            i++;
            j++;
        }
        else{
            j++;
        }
    }

    if(i == n) {
        return true;
    }
    return false;
}

signed main() {
    string s, t;
    cin >> s >> t;

    //
    cout << isSubsequence(s, t) << endl;
    

    return 0;
}

// 2. find the document number in which the given word coming
// d1: "how are you vivek singh"
// d2: "given two sheets, to me"
// d3: "you can do whatever you want"
// 
// needle: "you"
// ans: 1, 3

/* 
create a map<string, vector<int>> 
for each word/token --> document numbers
then find the intersection using ptr
*/