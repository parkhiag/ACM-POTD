# Day 5

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






















