#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    // Write your code here
    unordered_map<int, int> mp;
    int preSum = 0;
    int n = nums.size();
    int rs = 0;

    for (int i = 0; i < n; i++){
        preSum += nums[i];

        if (preSum == k){
            rs = i+1;
        }
        if(mp.find(preSum)== mp.end()){
            mp.insert({preSum, i});
        }
        if (mp.find(preSum - k) != mp.end()){
            rs = max(rs, i-mp[preSum-k]);
        }
    }
    return rs;
}
