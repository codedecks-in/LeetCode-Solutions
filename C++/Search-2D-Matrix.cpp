class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int m = matrix.size();
        int n = matrix[0].size();

        int s = 0, e = m * n - 1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            int midEle = matrix[mid / n][mid % n];
            if (midEle == target)
                return true;

            if (midEle < target)
                s = mid + 1;
            else
                e = mid - 1;
        }

        return false;
    }
};