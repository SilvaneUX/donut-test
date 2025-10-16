#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;

    unordered_set<int> s(nums.begin(), nums.end());
    int longest = 0;

    for (int num : s) {
        // Check if this number is the start of a sequence
        if (!s.count(num - 1)) {
            int currentNum = num;
            int streak = 1;

            // Count consecutive numbers
            while (s.count(currentNum + 1)) {
                currentNum++;
                streak++;
            }

            longest = max(longest, streak);
        }
    }

    return longest;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Length of longest consecutive sequence: " << longestConsecutive(nums) << endl;
    return 0;
}
