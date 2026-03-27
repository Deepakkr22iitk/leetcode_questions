class Solution {
public:
    void rotate(vector<int> &arr, int k, string dir){
        int n = arr.size();
        for(int t = 0; t < k; t++){
            if(dir == "left"){
                int temp = arr[0];
                for(int i = 1; i < n; i++){
                    arr[i-1] = arr[i];
                }
                arr[n-1] = temp;
            }
            if(dir == "right"){
                int temp = arr[n-1];
                for(int i = n-1; i>0; i--){
                    arr[i] = arr[i-1];
                }
                arr[0] = temp;
            }
        }
        
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        int k1 = k % n;
        cout<<k<<" ";
        bool ans = true;
        vector<int> temp(n);
        for(int i = 0; i<m; i++){
            vector<int> temp(n);
            for(int j = 0; j<n; j++){
                temp[j] = mat[i][j];
            }
            if(i % 2 == 0) rotate(temp, k1, "left");
            else rotate(temp, k1, "right");
            for(int j = 0; j<n; j++){
                if(temp[j] != mat[i][j]) return false;
            }
        }
        return true;
    }
};