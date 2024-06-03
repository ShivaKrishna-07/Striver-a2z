// GFG - Rat in a maze

vector<string> result;
bool isSafe(int i, int j, int n)
{
    return i < n && i >= 0 && j < n && j >= 0;
}

void solve(int i, int j, vector<vector<int>> &m, int n, string &path)
{
    if (!isSafe(i, j, n) || m[i][j] == 0)
    {
        return;
    }
    if (i == n - 1 && j == n - 1)
    {
        result.push_back(path);
        return;
    }

    m[i][j] = 0;

    path.push_back('D');
    solve(i + 1, j, m, n, path);
    path.pop_back();

    path.push_back('L');
    solve(i, j - 1, m, n, path);
    path.pop_back();

    path.push_back('U');
    solve(i - 1, j, m, n, path);
    path.pop_back();

    path.push_back('R');
    solve(i, j + 1, m, n, path);
    path.pop_back();

    m[i][j] = 1;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Your code goes here
    string path = "";

    solve(0, 0, m, n, path);

    return result;
}