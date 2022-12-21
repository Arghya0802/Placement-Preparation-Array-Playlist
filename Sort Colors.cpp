// Link: https://leetcode.com/problems/sort-colors/description/

class Solution {
public:
     
    // This is a classic question of Dutch National Flag Algorithm
    void sortColors(vector<int>& nums) 
    {
        int n = nums.size() ;
        
        // We need 3-pointers for Dutch National Flag Algorithm
      
        int low = 0 ; // Keeps track of 0 and places them at the beginning

        int mid = 0 ; // Keeps track of 1 and places them at the middle

        int high = n - 1 ; // Keeps track of 2 and places them at the end 
        
        // We iterate until Mid pointer becomes greater than High pointer
        while(mid <= high)
        {
            if(nums[mid] == 0) // If we encounter 0, then it should go at the front
            {
                // That's why we swap nums[mid] and nums[low]
                swap(nums[mid] , nums[low]) ;
                
                // And we increment both low and mid by 1
                low += 1 ;
                
                mid += 1 ;
            }

            else if(nums[mid] == 2) // If we encounter 2, then it should go at the end
            {
                // That's why we swap nums[mid] and nums[high]
                swap(nums[mid] , nums[high]) ;
                
                // But we only decrement high by 1 
                // This is because there lies a probability that nums[high] was carrying 0, so in that place we need the 0 to be placed at the beginning and that's the reason we don't encounter mid and wait for one more iteration
                high -= 1 ;  
            }

            else // Otherwise we encounter 1, for which we only increment mid by 1
                mid += 1 ;
        }

        return ;    
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
