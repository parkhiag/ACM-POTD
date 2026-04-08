

# Day 18

## 1. Remove All Adjacent Duplicates in String
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
We repeatedly make duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

### Screenshot of accepted solution
<img width="1919" height="849" alt="image" src="https://github.com/user-attachments/assets/629483ef-5ad2-46a4-8c29-06e0a2e3e64e" />





### Code
```cpp
class Solution {
public:
    string removeDuplicates(string s) {
        string st = "";
        for (char c : s) {
            if (!st.empty() && st.back() == c) {
                st.pop_back();
            } else {
                st.push_back(c);
            }
        }
        return st;
    }
};
