class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
    if (mat[0].size() % 2 == 0)
    {
        for (int i = 0; i < mat[0].size(); i++)
        {
            ans += mat[i][i];
        }
        for (int i = 0; i < mat[0].size(); i++)
        {
            ans += mat[i][mat[0].size() - i - 1];
        }
    }
    else
    {
        for (int i = 0; i < mat[0].size(); i++)
        {
            ans += mat[i][i];
        }
        for (int i = 0; i < mat[0].size(); i++)
        {
            ans += mat[i][mat[0].size() - i - 1];
        }
        ans -= mat[mat[0].size() / 2][mat[0].size() / 2];
    }
    return ans;
    }
};