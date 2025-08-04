class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int count=0;
        int i=0,ans=0,first=0,second=0;
        set<int> now;      
        while(i<n)
        {
            if(now.size()==0)
            {
                first=i;
                count++;
                now.insert(fruits[i]);
            }
            else if(now.size()==1)
            {
                if(now.find(fruits[i])==now.end())
                {
                    second=i;
                    now.insert(fruits[i]);
                    // count++;
                }
                count++;
            }
            else
            {
                if(now.find(fruits[i])==now.end())
                {
                    ans=max(ans,count);
                    if(first>second)
                    {
                        now.erase(fruits[second]);
                        count=(i-first);
                        second=i;
                    }
                    else
                    {
                        now.erase(fruits[first]);
                        count=(i-second);
                        first=second;
                        second=i;
                    }
                    now.insert(fruits[i]);
                    count++;
                }
                else 
                {
                    if(fruits[i]==fruits[first] && fruits[i-1]==fruits[second])
                    {
                        first=i;
                    }
                    else if(fruits[i]==fruits[second]&& fruits[i-1]==fruits[first])
                    {
                        second=i;
                    }

                    count++;
                }
            }
            i++;
        }
        ans=max(ans,count);
        for(auto &it:now)
        {
            cout<<it<<" ";
        }
        cout<<first<<" "<<second<<" ";
        return ans;
    }
};