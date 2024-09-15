/* medium difficulty */

class Solution{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        int mpp[1001] = {0};

        for (int i = 0; i < n; i++)
        {
            if (citations[i] > 1000)
            {
                mpp[1000]++;
            }
            else
            {
                mpp[citations[i]]++;
            }
        }

        for (int i = 999; i >= 0; i--)
        {
            mpp[i] += mpp[i + 1];
        }

        for (int i = 1000; i >= 0; i--)
        {
            if (mpp[i] >= i)
            {
                return i;
            }
        }

        return 0;
    }
};