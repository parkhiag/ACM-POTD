# Day 4

## 1. Missing Number
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
### Screenshot of accepted solution
<img width="1919" height="845" alt="image" src="https://github.com/user-attachments/assets/cc9c27f8-9e3a-4ab6-8112-619c028ed1c2" />



### Code
```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int total = (n*(n+1))/2;
        int sum=0;
        for (int num : nums) {
            sum = sum+num;
        }
        return total - sum;
    }
};
```
---

