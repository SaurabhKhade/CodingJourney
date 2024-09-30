class CustomStack {
    vector<int> stack;
    int i = 0, n;
public:
    CustomStack(int maxSize) {
        stack.resize(maxSize);
        n = maxSize;
    }
    
    void push(int x) {
        if (i < n) {
            stack[i++] = x;
        }
    }
    
    int pop() {
        if (i != 0 ) {
            return stack[--i];
        }

        return -1;
    }
    
    void increment(int k, int val) {
        for (int j=0; j<i && j<k; j++) {
            stack[j] += val;
        }
    }
};
