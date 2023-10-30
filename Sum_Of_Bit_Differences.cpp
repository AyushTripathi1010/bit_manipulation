// Problem Link: https://practice.geeksforgeeks.org/problems/sum-of-bit-differences2937/1

// INTUITION: Here we have to cnt sum of bit differences of all possible pairs formed in array.
// Eg: Input:
// N = 3 
// arr[] = {1, 3, 5}
// Output: 8
// Explanation: 
// All pairs in array are (1, 1), (1, 3),
// (1, 5), (3, 1), (3, 3) (3, 5),(5, 1),
// (5, 3), (5, 5)
// Sum of bit differences =  0 + 1 + 1 +
//                           1 + 0 + 2 +
//                           1 + 2 + 0 
//                        = 8

// We can ignore those pairs which are forming pairs with itself, because their difference will always be 0.
// For all numbers represented in binary, we are seeing the every kth position and counting the number of 0's and 1's
// When we multiply cnt_0*cnt_1, we realise that it gives the sum of bit difference from all possible pairs for that kth position.
// Just try to do first indivdual pair xor. The resultant xor has number of set bits equal to total bit difference for that particular pair.



class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	    // code here
	    long long ans =0;
	    for(int i = 0 ; i < 32; i++)
	    {    long long cnt_0 =0 , cnt_1=0;
	        for(int j = 0;  j < n ; j++)
	        {
	            if((1<<i)&arr[j])
	            {
	                cnt_1++;
	                
	            }
	            else
	            cnt_0++;
	        }
	        
	        ans+= (cnt_1*cnt_0);
	    }
	    ans*=2;
	    return ans;
	}
};