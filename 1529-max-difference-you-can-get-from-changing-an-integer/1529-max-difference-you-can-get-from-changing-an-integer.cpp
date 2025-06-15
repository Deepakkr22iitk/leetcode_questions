class Solution {
public:
    int maxDiff(int num) {
        string str=to_string(num);
        string mx=str;
        int len=mx.size();
        int i=0;
        while(i<len && mx[i]=='9') i++;
        
        char val='9';
        if(i<len) val=mx[i];

        for(int i=0;i<len;++i) 
        {
            if(mx[i]==val) mx[i]='9';
        }

        string mn=str;

        int l=0;
        while(l<len && mn[l]<='1') l++;

        val='*';
        if(l<len) val=mn[l];

        for(int i=0;i<len;++i)
        {
            if(mn[i]==val)
            {
                if(l==0) mn[i]='1';
                else mn[i]='0';
            }
        }

        int val1=stoi(mx);
        int val2=stoi(mn);
        return (val1-val2);
    }
};