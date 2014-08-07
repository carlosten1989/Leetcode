class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        const int TWO = 2;
        int size = numbers.size();
        if(size < TWO) {
            return ret;
        }
        unordered_map<int, int> um;
        int i;
        for(i = 0;i < size;i ++) {
            if(um.find(numbers[i]) != um.end()) {
                ret.push_back(um[numbers[i]] + 1);
                ret.push_back(i + 1);
                break;
            } else {
                um[target - numbers[i]] = i;
            }
        }
        return ret;
    }
};
