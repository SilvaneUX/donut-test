#include <bits/stdc++.h>
using namespace std;

int knapsackOptimized(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<int> dp(W+1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = W; w >= wt[i]; w--) {
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }
    return dp[W];
}

int main() {
    int n, W;
    cin >> n;
    vector<int> wt(n), val(n);
    for(int i = 0; i < n; i++) cin >> wt[i];
    for(int i = 0; i < n; i++) cin >> val[i];
    cin >> W;

    cout << knapsackOptimized(W, wt, val, n) << endl;
    return 0;
}
