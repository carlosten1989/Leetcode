class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int size = gas.size();
        int sum = 0;
        int index = 0;
        int i;
        int sumg = 0;
        int sumc = 0;
        for(i = 0;i < size;i ++) {
            sumg += gas[i];
            sumc += cost[i];
            sum += gas[i] - cost[i];
            if(sum < 0) {
                index = i+1;
                sum = 0;
            }
        }
        if(sumg < sumc) {
            return -1;
        }
        return index % size;
    }
};