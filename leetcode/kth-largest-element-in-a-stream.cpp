class KthLargest {
    // MinHeap: stores ascending
    priority_queue<int, vector<int>, greater<int>> pq;
    // We will restrict size to k elements
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int& num: nums)
        {
            this->pq.push(num);
        }
    }
    
    int add(int val) {
        pq.push(val);
        while (pq.size() > k) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */