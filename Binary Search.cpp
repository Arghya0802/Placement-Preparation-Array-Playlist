// Link: https://leetcode.com/problems/binary-search/description/

class Solution {
public:
  
    // Binary Search is one of the most useful algorithm and has wide range of applications
    // The main reason behind this is that it finds everything in O(Log N) Time Complexity
  
    int search(vector<int>& nums, int target) 
    {
        int n = nums.size() ;

        int low = 0 ; // Low starts from 0th Index

        int high = n - 1 ; // High starts from Last Index
        
        // We move while Low becomes greater than High
        while(low <= high)
        {
            int mid = low + (high - low) / 2 ; // We calculate mid by avoiding Overflow

            if(nums[mid] == target) // If nums[mid] is equal to target, we directly return mid
                return mid ;

            else if(nums[mid] < target) // If nums[mid] is less than target, then we need to search on the Right Half
                low = mid + 1 ; // That's why increment Low as Mid + 1

            else //  Else if nums[mid] is greater than target, we need to search on the Left Half
                high = mid - 1 ; // Thus we update High as Mid - 1

        }   

        return -1 ; // If Target is not present, we return -1 at the end
    }
};

// Time Complexity:  O(Log N)
// Space Complexity: O(1)
