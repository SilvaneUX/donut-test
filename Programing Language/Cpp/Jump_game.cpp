#include<bits/stdc++.h>
using namespace std;
bool canJump(vector<int>& nums) {
        int maxind = 0;
        for(int i = 0 ; i<nums.size(); i++){
            if(i>maxind) return false;
            maxind = max(maxind,i+nums[i]);
        }
        return true;
    }
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    if(canJump(nums)){
        cout << "TRUE" <<endl;
    }
    else{
        cout << "FALSE" << endl;
    }
}


/*
Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

*/