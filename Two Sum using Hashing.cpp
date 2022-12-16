// LeetCode: https://leetcode.com/problems/two-sum/

// We can do this using Hash-Map or Unordered-Maps in C++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int n = nums.size() ;
        
        unordered_map<int , int> map ; // Declare an Hash-Map
        
        // Every time, we will look if (Target - nums[i]) is present inside our HashMap or not
        // If true, we will return the indices of (i , map[nums[i]) 
        // Else, we will continue iterating over the array
        // At the end, if we don't find any indices we will return {-1 , -1}
      
        for(int i = 0 ; i < n ; i++)
        {
            int val = nums[i] ;
            int key = target - val ;
            
            if(map.find(key) != map.end() )
            {
                int first  = map[key] ;
                int second = i ;
                
                return {first , second} ;
            }
            
            else
                map[val] = i ;
        }
        
        return {-1 , -1} ;
        
    }
};
