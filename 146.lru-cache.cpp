class LRUCache {
public:
    int n;
    map<int,pair<int,list<int>::iterator>> mp;
    list<int> dq;
    LRUCache(int capacity) {
        n = capacity;
        dq.clear();
        mp.clear();
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            int val = mp[key].first;
            auto it = mp[key].second;
            dq.erase(it);
            dq.push_front(key);
            mp[key]={val,dq.begin()};
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) == mp.end()){
            if(dq.size() == n){
                int last = dq.back();
                dq.pop_back();
                mp.erase(last);
            }
        }
        else{
            auto it = mp[key].second;
            dq.erase(it);
        }
        dq.push_front(key);
        mp[key]={value,dq.begin()};
    }
};