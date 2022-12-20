// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// We need to remove the Duplicates from the Array in-place, that is, move them to the end, and return the length of the array which doesn't contain any duplicates
// Another info which is provided in the question, the array containing duplciates, if at all, is already sorted in itself
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
    int n = nums.size() ;
        
    int index = 1 ;
    int prev = nums[0] ; // We need to keep a track of the previous element such that we could compare if we are visiting a duplicate number or not
        
    for(int i = 1 ; i < n ; i++)
    {
        if(nums[i] != prev) // If we are visiting a Fresh Number
        {
            prev = nums[i] ; // We store the Fresh Number in prev
            nums[index] = prev ; // We put the Fresh Number in nums[index[
            index += 1 ; // We increment index by 1
        }
        
    }
        
    return index ; // At the end, Index will contain the Length of the Array which is Sorted and doesn't contain any Duplicates
    
}
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
