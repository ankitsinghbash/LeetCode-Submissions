class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    unordered_set<int> s;
    SmallestInfiniteSet() {
        for(int i=1;i<1001;i++){
            pq.push(i);
            s.insert(i);
        }
    }
    
    int popSmallest() {
        int element = pq.top();
        pq.pop();
        s.erase(element);
        return element;
    }
    
    void addBack(int num) {
        if(s.find(num)!=s.end()){
            return;
        }
        else{
            pq.push(num);
            s.insert(num);

        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
