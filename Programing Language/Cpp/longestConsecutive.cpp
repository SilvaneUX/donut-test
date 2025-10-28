#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& arr) {
    if (arr.empty()) return 0;

    unordered_set<int> seen(arr.begin(), arr.end());
    int best = 0;

    for (int x : seen) {
        if (!seen.count(x - 1)) {
            int y = x;
            int len = 1;

            while (seen.count(y + 1)) {
                y++;
                len++;
            }

            best = max(best, len);
        }
    }

    return best;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Longest consecutive sequence length: "
         << longestConsecutive(arr) << endl;

    return 0;
}
