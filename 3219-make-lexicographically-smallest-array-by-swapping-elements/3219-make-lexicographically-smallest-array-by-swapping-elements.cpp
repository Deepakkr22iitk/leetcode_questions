class Solution {
public:
//     The key insight is that:
// Sorting the array by values ensures we have the lexicographical order.
// By grouping elements based on the maxDifference constraint, we can limit swaps to valid elements.
// Extracting elements in the order of their indices while respecting group priorities guarantees the smallest lexicographical result.

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>>num_ind;
        for(int i=0;i<n;++i) num_ind.push_back({nums[i],i});

        sort(num_ind.begin(),num_ind.end());

        vector<vector<pair<int,int>>>group_pairs;
        group_pairs.push_back({num_ind[0]});

        for(int i=1;i<n;++i)
        {
            if((num_ind[i].first-num_ind[i-1].first)<=limit) group_pairs.back().push_back(num_ind[i]);  // Since, we've already sorted
            // num_ind based on value. so, a particular 'i' can only be part of previous 'i' i.e., (i-1) or else can try to make new group.

            else group_pairs.push_back({num_ind[i]});     // Making new group
        }

        for(auto &x:group_pairs)
        {
            vector<int>indices;
            for(auto &[value,ind]:x) indices.push_back(ind);

            sort(indices.begin(),indices.end());

            for(int i=0;i<indices.size();++i) nums[indices[i]]=x[i].first;  // Here each 'x' is already sorted based on 'first' value. Thus just rearranging the values.
        }
        return nums;
    }
};