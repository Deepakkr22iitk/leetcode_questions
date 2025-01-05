class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=shifts.size();
		// sum is the used to calculate suffix sum
		long long int sum=0;
		for(int i=n-1;i>=0;i--)
		{
			sum+=shifts[i];
			s[i]='a'+(s[i]-'a'+sum)%26;
		}
		return s;
    }
};