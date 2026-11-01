#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    sort(arr.begin(), arr.end());
    
    int maxCows = 0;
    for (int i = 0; i < n; i++){
        int rNum = arr[i], lNum = arr[i];
        int rIdx = i, lIdx = i;
        
        
        int distance = 1;
        bool isEndR = false, isEndL = false;
        while(!isEndR || !isEndL){
            if (!isEndR){
                int idx = lower_bound(arr.begin(), arr.end(), rNum + distance) - arr.begin();
                if (arr[idx] == rNum + distance) rNum = arr[idx];
                else {
                    if (arr[idx - 1] == rNum) isEndR = true;
                    else {
                        rNum = arr[--idx];
                        rIdx = idx;
                    }
                }
            }
            
            if (!isEndL){
                int idx = lower_bound(arr.begin(), arr.end(), lNum - distance) - arr.begin();
                if (arr[idx] == lNum - distance) lNum = arr[idx];
                else {
                    if (arr[idx] == lNum) isEndL = true;
                    else {
                        lNum = arr[idx];
                        lIdx = idx;
                    }
                }
            }
            
            distance++;
        }
        
        if (maxCows < rIdx - lIdx) maxCows = rIdx - lIdx;
    }
    cout << maxCows + 1 << endl;
}