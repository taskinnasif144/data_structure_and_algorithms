#include <bits/stdc++.h>
using namespace std;
int N, M;

bool isValidIndex(int i, int j)
{
    if (i >= N || i < 0 || j >= M || j < 0)
        return false;
    return true;
}

string bfs(int si, int sj, vector<vector<char>> mat)
{
    int visited[N][M];
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({si, sj});
    vector<pair<int, int>> ops = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!q.empty())
    {
        pair<int, int> src = q.front();
        q.pop();
        if (mat[src.first][src.second] == 'B')
        {
            return "YES";
        }

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

    return "NO";
}



int main()
{

    cin >> N >> M;
    vector<vector<char>> mat(N, vector<char>(M));
    int si, sj;
    int di, dj;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char v;
            cin >> v;
            if (v == 'A')
            {
                si = i;
                sj = j;
            }
            else if (v == 'B')
            {
                di = i;
                dj = j;
            }
            mat[i][j] = v;
        }
    }

    string res = bfs(si, sj, mat);
    cout << res << endl;

    return 0;
}