class Solution
{
public:
    int pivot(vector<int> &nums)
    {
        int n = nums.size();
        int s = 0, e = nums.size() - 1, m;

        while (s < e)
        {
            m = s + (e - s) / 2;

            if (m + 1 <= n and nums[m] > nums[m + 1])
                return m;

            else if (m - 1 >= 0 and nums[m] < nums[m - 1])
                return m - 1;

            else if (nums[m] > nums[s])
                s = m + 1;

            else
                e = m - 1;
        }

        return s;
    }

    int bs(vector<int> &nums, int s, int e, int target)
    {
        int n = nums.size();
        int m;

        while (s <= e)
        {
            m = s + (e - s) / 2;
            cout << m << " ";
            if (nums[m] == target)
                return m;
            else if (nums[m] < target)
                s = m + 1;
            else
                e = m - 1;
        }

        return -1;
    }

    int search(vector<int> &nums, int target)
    {

        int p = pivot(nums);
        cout << "pivot: " << p << endl;

        int ans = bs(nums, 0, p, target);
        cout << "---- ";
        if (ans == -1)
            ans = bs(nums, p + 1, nums.size() - 1, target);

        return ans;
    }
};