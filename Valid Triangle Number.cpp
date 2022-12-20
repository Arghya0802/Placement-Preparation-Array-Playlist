// LeetCode https://leetcode.com/problems/valid-triangle-number/description/
// GFG: 

// To solve this question, we need to be familiar with problems like- 3Sum , 3Sum Closest & 4Sum
// Next we know the property which any triangle has to satisfy, 
// Length of any 2-Sides > Third Side

int triangleNumber(vector<int>& nums) 
    {
        int n = nums.size() ;
        int ans = 0 ;

        sort(nums.begin() , nums.end() ) ; // We sort the array to make our calculation faster

        for(int i = n - 1 ; i >= 0 ; i--) // We start from the end and every time, we choose the nums[i] as the Largest / First Side of the Triangle
        {
            int first = nums[i] ;

            int low  = 0 ; // Low will start from 0-th Index
            int high = i - 1 ; // High will start from (i - 1) th Index

            while(low < high) 
            {
                int currSum = nums[low] + nums[high] ; // We calculate the Current Sum

                if(currSum > first) // If Current Sum > firstSide, then our Property is satisfied
                {
                    // This is possible because our array is sorted, so if any arr[low] + arr[high] > arr[i], every element in between low and high will also satisfy the condition
                    ans += (high - low) ; // Number of possible triangles is equal to (high - low)

                    high -= 1 ; // We check for a lower possible value
                }

                else // Otherwise, we look for a bigger value
                    low += 1 ;
            } 
            
        }
        
        return ans ; 
    }
};

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(1)
