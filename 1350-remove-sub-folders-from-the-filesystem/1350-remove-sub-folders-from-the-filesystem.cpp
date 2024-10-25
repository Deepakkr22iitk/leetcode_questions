class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n=folder.size();
        sort(folder.begin(), folder.end());

        vector<string>result;
        result.push_back(folder[0]);

        for (int i=1;i<n;++i) 
        {
            string lastFolder=result.back();
            lastFolder+='/';

            // Check if the current folder starts with the last added folder path
            if (folder[i].compare(0, lastFolder.size(), lastFolder) != 0) result.push_back(folder[i]);
        }
        return result;
    }
};