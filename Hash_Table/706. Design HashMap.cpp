// Url - https://leetcode.com/problems/design-hashmap/

class MyHashMap {
public:
    vector<int> mapS;
    MyHashMap() : mapS(1e6 + 1, -1){}
    
    void put(int key, int value) {
        mapS[key] = value;
    }
    
    int get(int key) {
        if(mapS[key] != -1)
            return mapS[key];
        return -1;
    }
    
    void remove(int key) {
        mapS[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */