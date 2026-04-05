
# Day 15

## 1. Valid Parenthesis
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

### Screenshot of accepted solution
<img width="1918" height="839" alt="image" src="https://github.com/user-attachments/assets/56de1bc9-baab-4973-8361-bcca13b4b38e" />





### Code
```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else if (st.empty())
                return false;
            else {
                char ch = st.top();
                st.pop();
                if ((s[i] == ')' && ch != '(') || (s[i] == '}' && ch != '{') ||
                    (s[i] == ']' && ch != '[')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
```
---
