class Solution {
public:
    int singleNumber(int A[], int n) {
        int result = 0;
        if (n == 0)
        {
            return result;
        }
        int i;
        int j;
        for(i = 0;i < 32;i ++)
        {
            int sum = 0;
            for(j = 0;j < n;j ++)
            {
                if((A[j] >> i) & 1 == 1)
                {
                    sum ++;
                }
            }
            if(sum %3 == 1)
            {
                result |= (1 << i);
            }
        }
        return result;
    }
};