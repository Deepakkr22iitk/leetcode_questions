class CustomStack {
public:
    vector<int>stack,inc;
    int n;
    CustomStack(int maxSize) {
        n=maxSize;
    }
    
    void push(int x) {
        if(stack.size()==n) return;
        stack.push_back(x);
        inc.push_back(0);
    }
    
    int pop() {
        int i=stack.size() -1;
        if(i<0) return -1;
        if(i>0) inc[i-1]+=inc[i];   // This is lazy updation part as before popping it out, we are incrementing (i-1) with (i) 
        int res=stack[i]+inc[i];    // since we are supposed to increase all the elements from '0' to 'i'.
        stack.pop_back();
        inc.pop_back();
        return res;
    }
    
    void increment(int k, int val) {
        int i=min(k,(int)stack.size()) -1;
        if(i>=0) inc[i]+=val;       // Only the i'th element is incremented and In pop fn we'll update it lazily.
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */