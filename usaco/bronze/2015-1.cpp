#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b < c || d < a){
        cout << b - a + d - c << endl;
    } else {
        vector<int> arr{a, b, c, d};
        sort(arr.begin(), arr.end());
        cout << arr[3] - arr[0] << endl;    
    }
}