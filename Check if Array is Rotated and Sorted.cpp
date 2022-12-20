// Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

// We can solve this question by counting Peaks in the Array

// However, I have solved it by finding the rotatedIndex 'K' and by left-Rotating the array by K places and then check if the Array is sorted or not
class Solution {
private:

// ReverseArray() is used to sort the given array from low till high indices[both included]
void reverseArray(int low , int high , vector<int> &arr)
{
    while(low <= high)
    {
        swap(arr[low] , arr[high]) ;

        low  += 1 ;
        high -= 1 ;
    }

    return ;
}

public:
    bool check(vector<int>& nums) 
    {
        int n = nums.size() ;
        
        // Initally, we assume that the rotatedIndex 'K' is -1
        int k = -1 ;

        for(int i = 0 ; i < n - 1 ; i++)
        {
            // If the array is already sorted, we simply move forward
            if(nums[i] <= nums[i + 1])
                continue ;
            
            // If we find any rotatedIndex, we update K as (i + 1)
            if(k == -1)
                k = i + 1 ;
            
            // If K is already updated, then it means that array is neither sorted nor Rotated-Sorted
            else 
                return false ; // So we directly return false

        }
        
        // If K is still -1, it means the array is already sorted
        if(k == -1) 
            return true ; // So we directly return true
        
        // We apply the Reversal Algorithm to get the actual array
        reverseArray(0 , k - 1 , nums) ;
        
        reverseArray(k , n - 1 , nums) ;

        reverseArray(0 , n - 1 , nums) ;
           
        // We then check if the Original Array is sorted or not
        for(int i = 0 ; i < n - 1 ; i++)
        {
            if(nums[i] > nums[i + 1])
                return false ;
        }

        return true ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
