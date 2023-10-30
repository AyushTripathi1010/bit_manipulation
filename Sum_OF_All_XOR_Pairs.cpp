// Problem Link: https://practice.geeksforgeeks.org/problems/sum-of-xor-of-all-pairs0723/1

// INTUITION:  We have to xor all the possible pairs and take their sum. The naive approach is easy, we can just
// use 2 for loops and generate all pairs xor them and add them, but this O(N^2) approach, which will gie TLE>
// So the O(32*N) approach comes into play from the fact that we add numbers in binary format we observe that only those 
// numbers which have 1 as set bit at a particular position will only contribute to sum. So instead of xoring all the possible 
// pairs we can for kth position in binary format for all numbers we can check count of set and unset bits, and count the number of
// pairs possible by taking 1 set and 1 unset bit, because (1^0) = 1, which will contribute to the sum, and then multiply it by 2^k to
// get the number. and after traversing all the bits the total sum will be our result.

// Consider eg: [7,3,5], just solve this example by your own.
// Possible XOR combinations are: (7^3) + (7^5) + (3^5) = 4 + 2+ 6 = 12.
// 4 = 0 1 0 0
// 2 = 0 0 1 0
// 5 = 0 1 1 0

// so at 0th position there are 0 pairs of (1,0) or(0,1), because all numbers have 0th bits as 0.
// AT 1st position, there are 2 set bits, and 1 unset bits, so total pairs will be 2.
// Similalry for other bits also.

// So the only catch to solve this problem is that after xoring 2 numbers whaterver is the resultant number it has a set bit at kth position,
// then it will only contribute to the sum if there exists some pair, whose resultant number has unset bit at same kth position,Then only it will 
// contribute to the sum.
// Because we have initial numbers of array only with us, we are not actually xoring, but we still want to know after xoring results.
// SO to arrive that we should know the catch.

class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {   
        long long res =0 ;
    	for(int i =0 ; i < 32 ; i++)
    	{    long long cnt_0=0, cnt_1=0;
    	    for(int j =0 ; j < n ; j++)
    	    {
    	         if((1<<i)&arr[j])
    	         {
    	             cnt_1++;
    	         }
    	         else cnt_0++;
    	        
    	        
    	    }
    	    
    	    long long ans = cnt_0*cnt_1;
    	    res+=ans*(1<<i);
    	}
    	
    	return res;
    }
};
