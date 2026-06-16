class TimeMap {
public:
    using pt = pair<int,string>;
    unordered_map<string,vector<pt>> mp;
    TimeMap() {
        ;
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        int n = mp[key].size();
        int l = 0;
        int r = n - 1;
        while (l <= r){
            int mid = l + (r - l)/2;
            
            if (mp[key][mid].first <= timestamp){
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        if (r == -1) return "";
        return mp[key][r].second;
    }
};
