#include <bits/stdc++.h>
using namespace std;
int N, M;

bool isValidIndex(int i, int j)
{
    if (i >= N || i < 0 || j >= M || j < 0)
        return false;
    return true;
}

void dfs(int si, int sj, vector<vector<char>> &mat, vector<vector<bool>> &visited)
{
    vector<pair<int, int>> ops = {{-1,0}, {1,0}, {0, 1}, {0, -1}};
    visited[si][sj] = true;
    for(auto op: ops){
        int i = si + op.first;
        int j = sj + op.second;
        if(isValidIndex(i, j) && !visited[i][j] && mat[i][j] != '#'){
            dfs(i, j, mat, visited);
        }
    }

}

int main()
{
    cin >> N >> M;
    vector<vector<char>> mat(N, vector<char>(M));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> mat[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(!visited[i][j] && mat[i][j] != '#' ){
                count++;
                dfs(i, j, mat, visited);
            }
        }
    }

    cout << count << endl;

    return 0;
}