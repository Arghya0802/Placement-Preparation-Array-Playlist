// Link: https://leetcode.com/problems/3sum-closest/

// This question is pretty similar to 3-Sum problem. So we must solve that one before moving to this problem

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int ans  = INT_MAX ; // Ans will store our 3-Sum
        int diff = INT_MAX ; // As we want the 3Sum as close to the target, so we need to keep a track of the abs(arr[i] + arr[j] + arr[k] - Target)
        int n = nums.size() ;

        sort(nums.begin() , nums.end() ) ; // Similar to 3-Sum, we will sort the array and then we will use 2-Pointers

        for(int i = 0 ; i < n ; i++)
        {
            int k = target - nums[i] ; // K is our new target which we will try to find in nums[] 

            int low  = i + 1 ;
            int high = n - 1 ;

            while(low < high)
            {
                int currSum = nums[low] + nums[high] ;

                int currDiff = abs(k - currSum) ;

                if(currDiff < diff) // If our CurrDiff is less than our prev Diff, it means our new 3-Sum is closer to our target than ever-before
                {
                    ans = currSum + nums[i] ;
                    diff = currDiff ;
                }    
                
                // Other than this, we apply the standard 2-Pointer Technique
                if(currSum <= k)
                    low += 1 ;

                else
                    high -= 1 ;
            }    
            
            // We can further optimise it by skipping all the duplicate elements
            while(i + 1 < n && nums[i] == nums[i + 1])
                i++ ;
        }

        return ans ;
    }
};

// Time Complexity:  O(N ^ 2) 
// Space Complexity: O(1)
