class RandomizedSet {
public:
    unordered_map<int,bool>m;
   
    /** Initialize your data structure here. */
    RandomizedSet() {
      
        m={};
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val)==m.end())
        {
             m[val]=true;
        } 
        else
            return false;
        return true;
        
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val)==m.end())
            return false;
        else
        {
            m.erase(val);
        } 
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {       
        int r= rand()%(m.size());
        auto itr=m.begin();
        advance(itr,r);
        return itr->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
