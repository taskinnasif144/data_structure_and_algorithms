#include <bits/stdc++.h>
using namespace std;
int N, M;

bool isValidIndex(int i, int j)
{
    if (i >= N || i < 0 || j >= M || j < 0)
        return false;
    return true;
}

int bfs(int si, int sj, vector<vector<char>> mat, vector<vector<bool>> &visited)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    vector<pair<int, int>> ops = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int count = 0;
    while (!q.empty())
    {
        pair<int, int> src = q.front();
        q.pop();

        count++;

        for (pair<int, int> x : ops)
        {
            int newI = src.first + x.first;
            int newJ = src.second + x.second;
            if (isValidIndex(newI, newJ) && !visited[newI][newJ] && mat[newI][newJ] != '#')
            {
                visited[newI][newJ] = true;
                q.push({newI, newJ});
            }
        }
    }

    return count;
}

int main()
{
    cin >> N >> M;
    vector<vector<char>> mat(N, vector<char>(M));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<int> rooms;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!visited[i][j] && mat[i][j] != '#')
            {
                int room = bfs(i, j, mat, visited);
                rooms.push_back(room);
            }
        }
    }

    sort(rooms.begin(), rooms.end());
    
    if (rooms.empty())
    {
        cout << 0 << endl;
        return 0;
    }

    for (auto room : rooms)
    {
        cout << room << ' ';
    }

    return 0;
}