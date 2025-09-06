#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjMat(void);
vector<vector<int>> adjListUnweighted(void);
vector<vector<pair<int, int>>> adjListWeighted(void);

int main()
{
    adjListUnweighted();
    return 0;
}

vector<vector<int>> adjMat(void)
{
    int n, e; // number of nodes and edges respectively
    cin >> n >> e;
    vector<vector<int>> graph(
        n, vector<int>(n, 0)); // 0 implies absence of edges also use n+1 for 1
                               // based indexing
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        // int w;
        cin >> v1 >> v2;
        v1--, v2--; // 0-based indexing
        // cin>>w;
        graph[v1][v2] = 1; // or the weight if it is a weighted graph
        graph[v2][v1] = 1; // if it is undirected
    }
    for (auto v : graph)
    {
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return graph;
}

vector<vector<int>> adjListUnweighted(void)
{ // for unweighted graphs
    int n, e;
    cin >> n >> e;
    vector<vector<int>> graph(n); // use n+1 for 1 based indexing
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        v1--, v2--; // 0-based indexing
        graph[v1].emplace_back(v2);
        graph[v2].emplace_back(v1); // if it is undirected
    }
    for (auto v : graph)
    {
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return graph;
}

vector<vector<pair<int, int>>> adjListWeighted(void)
{ // for weighted graphs
    int n, e;
    cin >> n >> e;
    vector<vector<pair<int, int>>> graph(n); // use n+1 for 1-based indexing
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        int w;
        cin >> v1 >> v2;
        cin >> w;
        v1--, v2--; // 0-based indexing
        graph[v1].emplace_back(v2, w);
        graph[v2].emplace_back(v1, w); // if it is undirected
    }
    for (auto v : graph)
    {
        for (auto x : v)
        {
            cout << x.first << " " << x.second << " ";
        }
        cout << "\n";
    }
    return graph;
}
