// LeetCode: https://leetcode.com/problems/rotate-array/description/

// In this question, we are Right Rotating the array that's why we are left rotation on (N - K) elements
// If we were asked to Left Rotate the array, we would have done using the given K only

class Solution {

private:

// Function to swap the array elements from (low till high) index
  
void reverseArray(int low , int high , vector<int> &arr)
{
    while(low <= high)
    {
        swap(arr[low] , arr[high]) ;

        low += 1  ;
        high -= 1 ;
    }

    return ;
}

public:
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size() ;

        k = k % n ; // If k becomes greater than n, we need to check to do take the remainder of N % K

        int leftRotate = n - k ; // We will use the same logic when we do Left-Rotate of an array, that's why we are doing N - K
        
        // Reversal Algorithm Steps
      
        reverseArray(0 , leftRotate - 1 , nums) ;

        reverseArray(leftRotate , n - 1 , nums) ;

        reverseArray(0 , n - 1 , nums) ;

        return ;    
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
