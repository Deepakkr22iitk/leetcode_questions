// class Solution {
// public:
//     int maximumEnergy(vector<int>& energy, int k) {
//         int n=energy.size();
//         int ans=INT_MIN;
//         // for(int i=0;i<k && i+k>=n;++i)
//         // {
//         //     ans=max(ans,energy[i]);
//         // }
//         for(int i=k;i<n;++i)
//         {
//             energy[i]=max(energy[i],(energy[i]+energy[i-k]));
//         }
//         for(int i=n;i<n;++i)
//         {
//             ans=max(ans,energy[i]);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k){
        int n = energy.size(), ans = INT_MIN;
        // Merge energy of every kth magician with its predecessor,
        // starting from the end of the line and moving backwards.
        for(int j = n - k - 1; j >= 0; j--){
            energy[j] += energy[j + k];
        }
        // Find the maximum energy accumulated after merging energies
        // and traversing through the line of magicians.
        for(int i = 0; i < n; i++){
            ans = max(ans, energy[i]);
        }
        return ans;
    }
};