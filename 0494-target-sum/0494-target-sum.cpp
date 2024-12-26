class Solution {
public:
// int f_recurr(int ind, int tar, vector<int>& nums){
//     // if(tar == 0) return 1;
//     if(ind == 0) {
//         if(tar == 0 && nums[0] == 0) return 2;
//         if(tar == 0 || tar == nums[0]) return 1;
//         return 0;
//     }
    
//     int notPick = f_recurr(ind - 1, tar, nums);
//     int pick = 0;
//     if(nums[ind] <= tar) pick = f_recurr(ind - 1, tar - nums[ind], nums);

//     return pick + notPick;
// }

// int f_memo(int ind, int tar, vector<int>& nums, vector<vector<int>> &dp){
//     // if(tar == 0) return 1;
//     if(ind == 0) {
//         if(tar == 0 && nums[0] == 0) return 2;
//         if(tar == 0 || tar == nums[0]) return 1;
//         return 0;
//     }
    
//     if(dp[ind][tar] != -1) return dp[ind][tar];
//     int notPick = f_memo(ind - 1, tar, nums, dp);
//     int pick = 0;
//     if(nums[ind] <= tar) pick = f_memo(ind - 1, tar - nums[ind], nums, dp);

//     return dp[ind][tar] = (pick + notPick);
// }
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int totSum = 0;
        for(auto &it : nums) totSum += it;

        // totSum<target -> notPossible 
        // also the remaining i.e. totSum-target if it's odd then we can't divide it 
        // in 2 half such that sum=0;
        if((totSum - target) < 0 || (totSum - target) % 2 == 1) return 0;

        int tar = (totSum - target) / 2;

    // return f_recurr(n - 1, tar, nums);

    // vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    // return f_memo(n - 1, tar, nums, dp);

    //Tabulation
    // vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    // dp[0][0] = 1; if(nums[0] != 0 && nums[0] <= tar) dp[0][nums[0]] = 1;
    // if(nums[0] == 0) dp[0][0] = 2;

    // for(int ind = 1; ind < n; ind++){
    //     for(int sum = 0; sum <= tar; sum++){
    //         int notPick = dp[ind - 1][sum];

    //         int pick = 0;
    //         if (nums[ind] <= sum) pick = dp[ind-1][sum-nums[ind]];

    //         dp[ind][sum] = (pick + notPick);
    //     }
    // }

    // return dp[n - 1][tar];

    //  Space Optimisation
    vector<int> prev(tar + 1, 0), curr(tar + 1, 0);
    if(nums[0] == 0) prev[0] = 2; //if tar = 0 && nums[0] = 0 then 2 cases pick or not pick
    else    prev[0] = 1; // if tar = 0 && nums[0] != 0 then only 1 case i.e. not pick

    if(nums[0] != 0 && nums[0] <= tar) prev[nums[0]] = 1;

    for(int ind = 1; ind < n; ind++) {
        for(int sum = 0 ; sum < tar + 1; sum++){

            int not_pick = prev[sum];

            int pick = 0;
                if(nums[ind] <= sum) 
                    pick = prev[sum - nums[ind]];

            curr[sum] = (pick + not_pick);
        }
        prev = curr;
    }
    return prev[tar];
    }
};