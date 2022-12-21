// Link: https://leetcode.com/problems/merge-sorted-array/description/

// We are asked to merge both A[] and B[] array together inside A[] and the merging should be In-Place
class Solution {
public:
    void merge(vector<int>& A , int m , vector<int>& B , int n) 
    {
        int k = A.size() - 1 ; // K will help us to fill the A[] in sorted order from end to start

        int i = m - 1 ; // To iterate over the sorted part of A[]
        int j = n - 1 ; // To iterate over B[]
        
        // We iterate until i or j becomes negative
        while(i >= 0 && j >= 0) 
        {
            if(A[i] > B[j]) // If A[i] > B[j], we need to place A[i] at A[k]
            {
                A[k] = A[i] ;

                k-- ; 
                i-- ;
            }

            else // Else we need to place B[j] at A[k]
            {
                A[k] = B[j] ;

                k-- ;
                j-- ;
            }

        }
        
        // At the end, which ever array is left to traverse we traverse it completely using for loops
        for(; i >= 0 ; i--)
        {
            A[k] = A[i] ;
            k-- ;
        }

        for(; j >= 0 ; j--)
        {
            A[k] = B[j] ;
            k-- ;
        }

        return ;
    }
};

// Time Complexity:  O(M + N)
// Space Complexity: O(1)
