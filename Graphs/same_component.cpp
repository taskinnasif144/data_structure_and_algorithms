#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
bool seen[1005][1005];

bool isValidIndex(int i, int j, vector<vector<char>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();
    if (i < 0 || j < 0 || i == r || j == c)
        return false;
    return true;
}

void dfs(int si, int sj, vector<vector<char>> &grid)
{
    if (!isValidIndex(si, sj, grid) || seen[si][sj] || grid[si][sj] == '-')
        return;
    seen[si][sj] = true;
    for (pair<int, int> dir : directions)
    {
        int di = si + dir.first;
        int dj = sj + dir.second;
        dfs(di, dj, grid);
    }
}

int main()
{
    memset(seen, false, sizeof(seen));
    int N, M;
    cin >> N >> M;
    vector<vector<char>> grid(N, vector<char>(M, 'e'));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> grid[i][j];

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;

    dfs(si, sj, grid);

    if (seen[di][dj])
        cout << "YES";
    else
        cout << "NO";
    return 0;
}