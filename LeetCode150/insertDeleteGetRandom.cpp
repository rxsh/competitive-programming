#include <bits/stdc++.h>

using namespace std;

class RandomizedSet {
    vector<int> v;
    unordered_map<int,int> mp;
public:
    RandomizedSet() {
    }

    bool search(int val){
        if(mp.find(val) != mp.end())
            return true;
        return false;
    }
    
    bool insert(int val) {
        
        if(search(val)){
            return false;
        }
    
        v.push_back(val);
        mp[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
    
        if(!search(val)){
            return false;
        }

        auto it = mp.find(val);
        v[it->second] = v.back();
        v.pop_back();
        mp[v[it->second]] = it->second;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        
        return v[rand()%v.size()];
    }
};


int main() {
    RandomizedSet rs;
    vector<string> operations = {"RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"};
    vector<vector<int>> args = {{}, {1}, {2}, {2}, {}, {1}, {2}, {}};

    for (size_t i = 0; i < operations.size(); ++i) {
        if (operations[i] == "RandomizedSet") {
            cout << "RandomizedSet created.\n";
        } else if (operations[i] == "insert") {
            int val = args[i][0];
            bool result = rs.insert(val);
            cout << "insert(" << val << ") -> " << (result ? "true" : "false") << "\n";
        } else if (operations[i] == "remove") {
            int val = args[i][0];
            bool result = rs.remove(val);
            cout << "remove(" << val << ") -> " << (result ? "true" : "false") << "\n";
        } else if (operations[i] == "getRandom") {
            int result = rs.getRandom();
            cout << "getRandom() -> " << result << "\n";
        }
    }

    return 0;
}