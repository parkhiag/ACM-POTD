
# Day 7

## 1. Rotate Array 
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

### Screenshot of accepted solution
<img width="1919" height="857" alt="image" src="https://github.com/user-attachments/assets/b5a4bc4e-4373-4678-9303-986fe5e7c6a8" />


### Code
```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /* this can be solved using 2 methods. 
            we can simply make a new array and in that we store the elements such that 
            ans[(i+k)%n]=nums[i]
            this will take extra space.
            optimized solution would be to do it in place. 
            so we reverse the whole array and then first reverse the first k terms 
            and then we reverse the remaining terms
        */
        int n=nums.size();
        k=k%n;

        reverse(nums.begin(),nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};
```
---
## 2. Increasing Triplet Subsequence
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

### Screenshot of accepted solution
<img width="1916" height="847" alt="image" src="https://github.com/user-attachments/assets/f5c698ce-eb00-468d-aca8-00f8bde09382" />



### Code
```cpp
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first=INT_MAX;
        int second = INT_MAX;

        for (int i=0; i<nums.size(); i++) {
            if (nums[i]<=first) {
                first=nums[i];
            }
            else if (nums[i]<=second) {
                second=nums[i];
            }
            else return true;
        }
        return false;
    }
};
```
