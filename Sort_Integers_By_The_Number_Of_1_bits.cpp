// Problem Link: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

// INTUITION: SO we want to sort the numbers such that numbers with less number of set bits comes first, and
// if 2 number have same count of set bits then the number which is smaller comes first.
// We have solved this question using comparator operator.
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
           int n = arr.size();

            auto lamda = [&](int &num1, int &num2)
            {
                int bits_num1 =0 , bits_num2 = 0;

                // for(int i= 0 ;i < 32; i++)
                // {
                //     if((1<<i)&num1) bits_num1++;

                //     if((1<<i)&num2) bits_num2++;
                // }

                // Other Alternative is using stl function to count
                // set bits in O(1) time.
                bits_num1 = __builtin_popcount(num1);
                bits_num2 = __builtin_popcount(num2);
                
                if(bits_num1 == bits_num2)
                 return num1 < num2;

                 return bits_num1 < bits_num2;
            };
           sort(arr.begin() , arr.end(), lamda);

           return arr;
    }
};