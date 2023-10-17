// Problem Link: https://www.codechef.com/problems/UNIQUEK

// INTUITION: Here for a given binary string of 0's and 1's if we have to either convert the string into fully 0's 
// or string of fully 1's.
// So which ever conversion takes minimum operations we have to print it.
// The condition for conversrion are:
// 1.)Select two indices i and j (i != j) such that i%k = j%k
// 2.) Set both Si and Sj as (Si xor Sj)

// SO the observation that can be made is that we can always convert string to 0's
// formula to make 0 is simple. Consider eg: s = 10110, so every pair of 1 can be made 0 in 1 operation by 1^1=0 property.
// and if one 1 is remaining, then we can eg: s = 10, then we can convert 0 to 1 by 0^1= 1, and ow since both have become 1
// now i will do xor again, because 1^1 =0.

// For converting the string to all 1's is possible only when for every remainder i.e i%k, we have a 1.
// suppose for a string, value of k = 2, then we will always be picking up indexes pair like (2,4) , (2,6), (2,8)
// so at least one of these indexes should contain 1 so that we can make the whole string 1.
// so for every different remainder there should be atleast one 1 present.


#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        
        unordered_map<int,pair<int,int>> m; // remainder, {cnt0, cnt1}
        
        for(int i =0 ; i < n ; i++)
        {
            int rem = i%k;
            
            s[i] == '0' ? m[rem].first++ : m[rem].second++;
        }
        
        // operations to make 0   --> it is always possible to make 0
        int ans0 =0 ;
        for(auto &it: m)
        {
           int cnt0 = it.second.first;
           int cnt1 = it.second.second;
           
           
           ans0 = ans0 + (cnt1/2 + (2*(cnt1%2)));
        }
        
        // operations to make 1 --> it is not always possible to make 1.
        
        int ans1 = 0;
        for(auto &it: m)
        {
           int cnt0 = it.second.first;
           int cnt1 = it.second.second;
           
           if(cnt1 == 0) {ans1 = INT_MAX; break;}
           
           ans1+= cnt0; // to convert 0 to one just count the number of ones.
           
           
        }
        
        int ans = min(ans0, ans1);
        cout<<ans<<endl;
        
    }
	return 0;
}
