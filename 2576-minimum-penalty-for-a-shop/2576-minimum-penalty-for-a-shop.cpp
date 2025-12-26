class Solution {
public:
    int bestClosingTime(string customers) {
        int y = 0 ;
        for(int i = 0 ; i < customers.size() ; i++) {
            if(customers[i] == 'Y') y++;
        }
        vector<int> v;
        int n = 0 ;
        for(int i = 0; i < customers.size() ; i++) {
            if(customers[i] == 'Y') {
                v.push_back(y + n);
                y--;
            }
            else {
                v.push_back(y + n);
                n++;
            }
        }
        v.push_back(n);
        int ans = 0, mini = 1e6 ;
        for(int i = 0 ; i <= customers.size() ; i++) {
            if(v[i] < mini) {
                mini = v[i];
                ans = i;
            }
        }
        return ans;
    }
};