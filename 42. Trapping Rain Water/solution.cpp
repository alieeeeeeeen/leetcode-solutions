class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        int res = 0;
        while(left < right) {
            if(height[left] < height[right]) { // find the min(maxLeft, maxRight)
                if(height[left] >= maxLeft) maxLeft = height[left]; // if current is greater than the max, assign the current to the maxLeft
                else
                    res += maxLeft - height[left]; // subtract the current from the maxLeft
                left++; // move to the next one
            } else { // the min(maxLeft, maxRight) is maxRight
                if(height[right] >= maxRight) maxRight = height[right];  // if current is greater than the max, assign the curren to the maxRight
                else
                    res += maxRight - height[right]; // subtract the current from the maxRight
                right--; // move forward
            }
        }
        return res;
    }
};


/**
 *                   |
 *       |           |
 *    |  |           |
 * |  |  |    |  |   |
 * --------------------
 * 
 * the maxLeft is the element at the position 0, the maxRight is the element at the last position
 * 
 * choose the min(maxLeft, maxRight) is maxLeft
 * 
 * move from left to right
 *
 * update the maxLeft
 * 
 * update the res to the maxLeft - current
 * 
 * 
 */