# Day 3

## 1. Best Time to Buy or Sell Stocks 
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

### Screenshot of accepted solution
<img width="1919" height="850" alt="image" src="https://github.com/user-attachments/assets/44f737fc-9782-4dae-853c-c3b6e447473c" />


### Code
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cheapest=INT_MAX;
        int i=0; 
        int profit=0;

        while (i<prices.size()) {
            cheapest = min(cheapest,prices[i]);
            profit = max((prices[i] - cheapest),profit);
            i++;
        }
        return profit;
    }
};
```
---

## 2. Sort Colors
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

### Screenshot of accepted solution
<img width="1919" height="852" alt="image" src="https://github.com/user-attachments/assets/e028fc26-9789-4056-a465-00c7d8d0342c" />



### Code
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // dutch national flag algorithm
        // we will divide the array in three sections
        int left=0;
        int right=nums.size()-1;
        int mid=0;

        while (mid<=right) {
            if (nums[mid]==0) {
                swap(nums[left], nums[mid]);
                left++;
                mid++;
            }
            else if (nums[mid]==1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[right]); 
                right--;
            }
        }
    }
};
```
---
## 3. Largest Rectangle in Histogram
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
### Screenshot of accepted solution
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/aecf2b9a-f004-4a8d-8ddf-d26adb3f54a3" />



### Code
```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area=0;
        stack<int> st;
        if (heights.size()==0) return 0;
        

        for (int i=0; i<heights.size(); i++) {
           
            // case : when current height is smaller 
            while (!st.empty() && heights[i]<heights[st.top()]) {
                int h=heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i-st.top()-1;
                area = max(area, h*width);
                
            }
            st.push(i);
        }

        while (!st.empty()) {
            int h=heights[st.top()];
                st.pop();
                int width = st.empty() ? heights.size() : heights.size()-st.top()-1;
                area = max(area, h*width);
        }
        return area;
    }
};
