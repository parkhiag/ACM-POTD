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
