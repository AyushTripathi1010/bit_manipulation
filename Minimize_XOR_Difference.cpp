// Problem Link: https://www.codechef.com/problems/XORDIF?tab=statement

// INTUITION: Always keep the larger value in a and smaller in b.
//  keep the values as close together to minimize the difference.

// After this step , one thing to notice is that if a-ith bit is equal to b-ith bit
// then, whether you keep the value of x-th bit, 0 or 1 , they will cancel each other
// and hence not contribute in the answer.

// We need to find the first unset bit in 'b' and corresponding set bit in 'a' number from left, that is the 
// first most significant unset bit.

// But why to check that.
// Although the first msb unset bit will not contribute to our answer, but 
//  from this bit -1 index till 0 , find all indexes where 
// a-ith != b-ith bit, and also a-ith bit must be 1, and b-ith bit must be 0.
// Whenver the above case is encountered, we will unset the a-th bit in order
// to decrease the value of 'a', and set the b-ith bit to 1 inorder to increase the value
// so that numbers come closer to each other.

// if a-ith bit != b-ith bit and a-ith bit = 0, and b-ith bit = 1, then
// we will not do any operation and just continue, because changing the bits
// in this case will increase the value of a and decrease the value of b, and
// hence maximizing their difference.(which we don't want).

// Eg: a = 109 , b = 99
 
//     64 32 16 8  4  2  1
// ----------------------------
// a = 1  1  0  1  1  0  1
// b = 1  1  0  0  0  1  1 

// while traversing from left to right for the first 3 bits, i.e till 16 value in both a and b are
// equal for the 4th bit from left where value is 8, this is the first position, where
// a-ith bit != b-ith bit and a-ith bit = 1 , b-ith bit = 0.
// but we will not be taking 8 in our answer, because, even if we unset a[i], and set
// b[i], still it will not make any sense and rather decrease the valuse of a
// and increase the value of b, i.e a < b. but our aim is always to keep value
// of a > b. This positions only means that from this position-1 till 0, if you get
// any condition like this above which we are getting for value 4.It  will contribute
// to our answer, because here we will unset a[i] and set b[i], and still my value of a will
// be greater than b , and both will come closer to each other.


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--)
	{
	    int a,b;
	    cin>>a>>b;
	   // int x = 0;
	    int most_significant_bit_index = -1;
	    if(a == b) {cout<<"0\n"; continue;}
	    
	    if(a < b) swap(a,b);
	    for(int i = 29 ; i>=0 ; i--)
	    {
	        int x = (1<<i);
	        
	        if((a&x) != (b&x))
	        {
	            most_significant_bit_index = i;
	            break;
	        }
	    }
	    int ans = 0;
	    for(int i = most_significant_bit_index-1 ; i>=0 ; i--)
	    {
	        int x = (1 << i);
	        
	        if((a&x) > 0 && (b&x) == 0)
	        {
	            ans+=x;
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
