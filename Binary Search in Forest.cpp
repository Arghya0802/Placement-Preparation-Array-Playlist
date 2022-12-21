// Link: https://practice.geeksforgeeks.org/problems/ffd66b6a0bf7cefb9987fa455974b6ea5695709e/1

// This is a very good warmup question before the classic Binary Search questions begin
// Our Search Space is between [0..... Largest Height Of Tree given to us]
// If we can click this, then rest of the question is just standard implementation

// Cut Tree functions returns the number of trees we can cut considering any given Height 
int cutTrees(int height , int n , int k , int A[])
{
        int woods = 0 ;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(A[i] <= height)
                continue ;
                
            woods += A[i] - height ;
        }
        
        return woods ;
}

int find_height(int tree[], int n, int k)
{
        // We mus remember that our ans Height might or might not present in our tree[] array
        // We need to chhose our Search Space accordingly -- [0..... Largest Element in tree[] ]
  
        sort(tree , tree + n) ; // We may or may not sort tree[] array, totally our choice
        
        int low = 0 ; // Lowest Height possible is 0
        
        int high = tree[n - 1] ; // Highest Height possible is equal to Largest Element of tree[] which is present at (n - 1)th Index
        
        while(low <= high)
        {
            int mid = low + (high - low) / 2 ; // Mid represents the Height at which we want the trees in Tree[] array
            
            int countTrees = cutTrees(mid , n , k , tree) ;
            
            if(countTrees == k) // If our countTrees is exactly equal to K, we directly return Mid as our answer
                return mid ;
                
            if(countTrees > k) // However if our countTrees is more than K, it means we definetly we need a bigger height
                low = mid + 1 ; // That's why we search in Right Half by updating Low as Mid + 1
                
            else // Else If our Count Trees is smaller than K, we need a smaller Height as our Mid Value
                high = mid - 1 ; // Thus, we search on the Left Half by updating High as Mid - 1
        }
        
        return -1 ; // If we cannot get exactly K woods, we return -1
}

// Time Complexity: O(N Log H-Max)
// Space Compleity: O(1)
