# Day 5

## 1. Move zeros
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.
### Screenshot of accepted solution
<img width="1916" height="850" alt="image" src="https://github.com/user-attachments/assets/a87cc818-1140-498a-bd7b-22d01f9af233" />




### Code
```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // we use i to track all the zeros. when we get a non zero number after i, we replace it
        int i=0;

        for (int j=0; j<nums.size(); j++) {
            if (nums[j]!=0) {
                swap(nums[i],nums[j]);
                i++;
            }
        }
    }
};
```
---
## 2. Product of array except self
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.
### Screenshot of accepted solution 
<img width="1919" height="844" alt="image" src="https://github.com/user-attachments/assets/627a9af7-1e3c-4506-8340-1860f2c2e866" />

### Code
```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /* 
            we make 2 arrays - left and right
            left array has first element as 1 bcz nothing on left side. 
            and next elements are left*nums[i]
            now right array has right most element as 1
            and next elements are right*nums[i]
            we multiply both arrays which gives final ans
        */
        vector<int> ans(nums.size(),1);
        int n=nums.size();
        int left=1;
        for (int i=0; i<n; i++) {
            ans[i]=left;
            left*=nums[i];
        }
        int right=1;
        for (int i=n-1; i>=0; i--) {
            ans[i]*=right;
            right*=nums[i];
        }
        
        return ans;
    }
};
```
---




















