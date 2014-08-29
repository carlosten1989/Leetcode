class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        int i;
        int num = 1<<n;
        for(i = 0;i < num;i ++)
        {
            ret.push_back(i ^ (i>>1));
        }
        return ret;
    }
};