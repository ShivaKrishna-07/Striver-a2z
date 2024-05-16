// Count all subsequence of sum = k


int countSubset(int idx, int sum, int k, vector<int>nums){
    if(idx == nums.size()){
        if(sum == k) return 1;
        return 0;
    }

    sum += nums[idx];
    int l = countSubset(idx+1, sum, k, nums);
    
    sum -= nums[idx];
    int r = countSubset(idx+1, sum, k, nums);
}

vector<vector<int>> subsets(vector<int> &nums, int k){
    cout << countSubset(0, 0, k, nums);
}