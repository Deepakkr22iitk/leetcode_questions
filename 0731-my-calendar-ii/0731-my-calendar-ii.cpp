class MyCalendarTwo {
public:
    map<int,int>rk;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        rk[start]++;
        rk[end]--;

        int booked=0;
        for(auto it=rk.begin();it!=rk.end();it++)
        {
            booked+=(it->second);
            if(booked==3)
            {
                rk[start]--;
                rk[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */