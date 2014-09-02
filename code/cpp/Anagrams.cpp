class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        int size = strs.size();
        vector<string> ret;
        if(size <= 1) {
            return ret;
        }
        unordered_map<string,int> umsi;
        unordered_map<int,bool> umib;
        int i;
        for(i = 0;i < size;i ++) {
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            if(umsi.find(tmp) != umsi.end()) {
                if(umbi[umsi[tmp]] == false) {
                    ret.push_back(strs[umsi[tmp]]);
                    umbi[umsi[tmp]] = true;
                }
                ret.push_back(strs[i]);
            } else {
                umsi[tmp] = i;
                umib[i] = false;
            }
        }
        return ret;
    }
};