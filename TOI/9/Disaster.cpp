#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool vis[26][26], found;
vector<int> graph[26];
vector<int> ans;
int n;

void dfs(int start)
{       
    if (found) return;
    if (ans.size() == n + 1)
    {
        for (auto i : ans)
        {
            cout << char(i + 'A') << " ";
        }
        found = true;
        return;
    }
    
    for (auto next: graph[start])
    {
        if (vis[start][next] || vis[next][start]) continue;
        vis[start][next] = vis[next][start] = true;
        ans.emplace_back(next);
        // for (auto i : ans)
        // {
        //     cout << char(i + 'A') << " ";
        // }
        // int cnt = ans.size();
        // cout << '\n' << cnt << "\n";
        // cout << "\n----------------------------------\n\n";
        dfs(next);
        if (found) return;
        ans.pop_back();
        vis[start][next] = vis[next][start] = false;
        // for (auto i : ans)
        // {
        //     cout << char(i + 'A') << " ";
        // }
        // cout << '\n' << cnt << "\n";
        // cout << "\n----------------------------------\n\n";
        
    }
}

int main()
{   
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        char a, b; cin >> a >> b;
        graph[int(a-'A')].emplace_back(int(b-'A'));
        graph[int(b-'A')].emplace_back(int(a-'A'));
    }
    
    int start = -1;
    for (int i = 0; i < 26; ++i)
    {
        // cout << char(i+'A') << " : " << graph[i].size() << '\n';
        if (graph[i].size() % 2 == 1)
        {
            start = i;
            break;
        }
        if (start == -1 && !graph[i].empty())
            start = i;
    }
    // cout << start;
    ans.emplace_back(start);
    dfs(start);

    return 0;
}