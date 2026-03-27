# Day 5

## 1. Check if N and its Duplicates exist
Given an array arr of integers, check if there exist two indices i and j such that :
i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]
### Screenshot of accepted solution
<img width="1919" height="852" alt="image" src="https://github.com/user-attachments/assets/fc693c7b-a9bd-4818-baf2-b05854a242a1" />

### Code
```cpp
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;

        for (int i=0; i<arr.size(); i++) {
            if (s.count(2*arr[i]) || (((arr[i]%2)==0) && s.count(arr[i]/2))) {
                return true;
            }
            s.insert(arr[i]);
        } 
        return false;
    }
};
```
## 2. Continous Subarray Sum
Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.
A good subarray is a subarray where:
its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
Note that:
A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
### Screenshot of accepted solution
<img width="1919" height="860" alt="image" src="https://github.com/user-attachments/assets/64fe8884-2f1c-4f64-9de5-15f3fd3cfd73" />


### Code
```cpp
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        /* subarray sum % k should be 0.
           subarray sum can be written as - 
           for 0 to i = prefix[i]
           for i to j = prefix[j]-prefix[i-1]
           (prefix[j]-prefix[i-1]) % k = 0 
           on rearranging we get prefix[j] % k = prefix[i-1] % k
           so if 2 prefix have same remainder, it is a good array.
           we use hashmap to store the remainder at that particular index.
        */
        unordered_map<int,int> mp;
        mp[0]=-1; 
        int sum=0;
        for (int i=0; i<nums.size(); i++) {
            sum+=nums[i];
            int rem = sum%k;
            // if we find this same remainder in the hashmap, we further check for size
            if (mp.count(rem)) {
                if (i-mp[rem]>=2) return true;
            }
            else mp[rem]=i;
        }
        return false;
    }
};
```
