class Solution {
public:
    // The first element of 'original' can be either '0' or '1'. so, we can check if any of them satisfies it.
    bool doesValidArrayExist(vector<int>& derived) {
        vector<int> original={0};   // original potential array would be from index '1' till 'n'
        int n=derived.size();
        for (int i=0;i<n;++i) original.push_back((derived[i]^original[i]));

        bool checkForZero=(original[0]==original[n]);

        original={1};
        for (int i=0;i<n;++i) original.push_back((derived[i]^original[i])); // Using the inversion Property, original[i+1]=derived[i]XORoriginal[i]
    
        bool checkForOne=(original[0]==original[n]);

        return (checkForZero | checkForOne);  // If any of them possible
    }
};