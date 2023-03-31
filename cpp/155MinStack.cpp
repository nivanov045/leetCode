class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        _data.push_back(x);
        if (x < minEl)
            minEl = x;
    }
    
    void pop() {
        bool isNeedUpd = false;
        if (_data.back() == minEl) {
            if (_data.size() != 1)
                minEl = *min_element(_data.begin(), _data.end() - 1);
            else
                minEl = DEFAULT_MIN;
        }
        _data.pop_back();
    }
    
    int top() {
        return _data.back();
    }
    
    int getMin() {
        return minEl;   
    }
    
    const int DEFAULT_MIN = numeric_limits<int>::max();
    
    vector<int> _data;
    int minEl = DEFAULT_MIN;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */