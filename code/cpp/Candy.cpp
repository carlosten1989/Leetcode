class Solution {
public:
    int candy(vector<int> &ratings) {
        int size = ratings.size();
        if(size <= 1) {
            return size;
        }
        int i;
        int down = 0;
        int up = 1;
        int max_up = 1;
        int sum = 1;
        for(i = 1;i < size;i ++) {
            if(ratings[i] < ratings[i-1]) {
                down ++;
                if(down == max_up) {
                    down ++;
                }
                sum += down;
                up = 1;
            } else if(ratings[i] == ratings[i-1]) {
                sum += 1;
                down = 0;
                up = 1;
                max_up = 1;
            } else {
                up ++;
                max_up = up;
                sum += up;
                down = 0;
            }
        }
        return sum;
    }
};