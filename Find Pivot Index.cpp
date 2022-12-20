// Link: https://leetcode.com/problems/find-pivot-index/description/

// This question is asks us to find the Index whose Sum of LeftSide is equal to Sum of RightSide

// Instead of using 2-For Loops, we can use totalSum to reduce our Time Complexity to Linear
class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int n = nums.size() ;

        int totalSum = 0 ;
        
        // We calculate the totalSum before
        for(int val : nums)
            totalSum += val ;

        int leftSum = 0 ; // LeftSum initally starts from 0

        for(int i = 0 ; i < n ; i++)
        {
            int rightSum = totalSum - nums[i] ; // RightSum shouldn't include the Current-Element

            if(leftSum == rightSum) // If they are equal, we return i
                return i ;

            totalSum -= nums[i] ; // Otherwise, we decrement the totalSum by nums[i]
            leftSum += nums[i] ;  // And increment leftSum by nums[i] such that sum of all the elements in nums[] remains preserved
        }

        return -1 ; // If we don't find any Pivot Index, we return -1 at the end
            
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
