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
