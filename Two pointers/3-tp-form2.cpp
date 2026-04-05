#include<iostream>
#include<vector>
using namespace std;

#define int long long

// Container with most water
// maximize = min(arr[l], arr[r]) * (r-l)
// learn this expr: min * diff

// 1. Contribution technique
signed main() {
    int n;
    cin >> n;

    vector<pair<int,int>> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    //
    sort(begin(arr), end(arr));

    int maxIdx = -1;
    int minIdx = n;

    int ans = 0;
    for(int i=n-1; i>=0; i--) {
        maxIdx = max(maxIdx, arr[i].second);
        minIdx = min(minIdx, arr[i].second);

        ans = max({ans, arr[i].first * (abs(arr[i].second - maxIdx)), arr[i].first * (abs(arr[i].second - minIdx))});
    }

    cout << ans << "\n";

    return 0;
}

// 2. using 2 ptr
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();

        int i = 0;
        int j = n-1;

        int ans = 0;
        while(i < j) {
            ans = max(ans, min(height[i], height[j]) * (j-i));

            if(height[i] > height[j]) {
                j--;
            } else {
                i++;
            }
        }

        return ans;
    }
};


// 2sum and 3sum problem --> form 2 pe h