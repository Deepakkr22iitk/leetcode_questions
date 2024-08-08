class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int p, int q, int rStart, int cStart) {
        
    vector<vector<int>>ans;
    int r1=rStart-1,r2=rStart+1;
    int c1=cStart-1,c2=cStart+1;
  
    int cnt=0;
    int curr=2;
    while(cnt<(p*q))
    {
        if(curr==1)
        {
            while(rStart<=r2 && cnt<(p*q))
            {
                if(rStart>=0 && rStart<p && cStart>=0 && cStart<q) cnt++;
                if(rStart>=0 && rStart<p && cStart>=0 && cStart<q && cnt<=(p*q))
                {
                    vector<int>temp={rStart,cStart};
                    ans.push_back(temp);
                } 
                rStart++;
            }
            r2++;
            cStart--;
            rStart--;
            curr=4;
        }
    else if(curr==2)
    {
      while(cStart<=c2 && cnt<(p*q))
      {
        if(rStart>=0 && rStart<p && cStart>=0 && cStart<q) cnt++;
        
        if(rStart>=0 && rStart<p && cStart>=0 && cStart<q && cnt<=(p*q))
        {
          vector<int>temp={rStart,cStart};
          ans.push_back(temp);
        } 
        cStart++;
      }
      c2++;
      cStart--;
      rStart++;
      curr=1;
    }
    else if(curr==3)
    {
      while(rStart>=r1 && cnt<(p*q))
      {
        
        if(rStart>=0 && rStart<p && cStart>=0 && cStart<q) cnt++;
        if(rStart>=0 && rStart<p && cStart>=0 && cStart<q && cnt<=(p*q))
        {
          vector<int>temp={rStart,cStart};
          ans.push_back(temp);
        }
        rStart--;
      }
      r1--;
      rStart++;
      cStart++;
      curr=2;
    }
    else 
    {
      while(cStart>=c1 && cnt<(p*q))
      {
        
        if(rStart>=0 && rStart<p && cStart>=0 && cStart<q) cnt++;
        if(rStart>=0 && rStart<p && cStart>=0 && cStart<q && cnt<=(p*q))
        {
          vector<int>temp={rStart,cStart};
          ans.push_back(temp);
        } 
        cStart--;
      }
      c1--;
      cStart++;
      rStart--;
      curr=3;
    }
    }
    return ans;
    }
};