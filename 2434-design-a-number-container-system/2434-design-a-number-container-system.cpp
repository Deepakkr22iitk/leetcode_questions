class NumberContainers {
public:
    unordered_map<int,priority_queue<int,vector<int>,greater<int>>>mp;
    unordered_map<int,int>ind;
    NumberContainers() {
    
    }
    
    void change(int index, int number) {
        ind[index]=number;
        mp[number].push(index);
    }
    
    int find(int number) {
        while(mp[number].size()>0)
        {
            auto temp=mp[number].top();
            if(ind[temp]==number) return temp;

            mp[number].pop();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */