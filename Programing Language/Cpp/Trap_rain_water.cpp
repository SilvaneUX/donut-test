#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    /**
     * Computes the amount of water trapped after raining using the Two-Pointer technique.
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     *
     * @param height A vector of non-negative integers representing the elevation map.
     * @return The total units of water trapped.
     */
    int trap(std::vector<int>& height) {
        if (height.empty() || height.size() < 3) {
            return 0; // Need at least 3 bars to trap water
        }

        int left = 0;
        int right = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int trappedWater = 0;

        // The water trapped at any position 'i' is determined by the minimum of 
        // the tallest bar to the left and the tallest bar to the right, minus the current height.
        // We move the pointer pointing to the lower max height, as that side is the current limiting factor.
        while (left < right) {
            if (height[left] < height[right]) {
                // The water at 'left' is limited by leftMax, because we know rightMax >= height[right] > height[left].
                // Therefore, rightMax is guaranteed to be high enough to contain the water.
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    trappedWater += leftMax - height[left];
                }
                left++;
            } else {
                // The water at 'right' is limited by rightMax, because we know leftMax >= height[left] >= height[right].
                // Therefore, leftMax is guaranteed to be high enough to contain the water.
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    trappedWater += rightMax - height[right];
                }
                right--;
            }
        }

        return trappedWater;
    }
};

/*
// Example Usage (for testing locally):
int main() {
    Solution s;
    std::vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << "Trapped Water (Example 1): " << s.trap(height1) << std::endl; // Output: 6

    std::vector<int> height2 = {4, 2, 0, 3, 2, 5};
    std::cout << "Trapped Water (Example 2): " << s.trap(height2) << std::endl; // Output: 9

    return 0;
}
*/