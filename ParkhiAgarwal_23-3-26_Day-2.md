# Day 2

## Two Sum 
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

### Screenshot of accepted solution
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/3c5c166d-e410-416d-822a-51ba283bd6b2" />

### Code
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        vector<int> ans;

        for (int i=0; i<nums.size(); i++) {
            int need = target - nums[i];
            
            // if 'need' is found in the hashmap then we will put need and nums[i] in ans and end.
            if (mpp.find(need)!= mpp.end()) {
                ans.push_back(mpp[need]);
                ans.push_back(i);
                break;
            }

            mpp[nums[i]]=i;
        }
        return ans;
    }
};
