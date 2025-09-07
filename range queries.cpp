#include <bits/stdc++.h>

// 1-D prefix sums

struct PrefixSum
{
    std::vector<long long> ps;
    PrefixSum(const std::vector<int> &v)
    {
        int n = v.size();
        ps.resize(n + 1, 0LL);
        for (int i = 0; i < n; i++)
        {
            ps[i + 1] = ps[i] + v[i];
        }
    }
    long long sum(int l, int r)
    {
        return ps[r + 1] - ps[l];
    }
};

// sparse table (for minm)

struct SparseTable
{
    int n, LOG;
    std::vector<std::vector<int>> table;
    SparseTable(const std::vector<int> &v)
    {
        n = v.size();
        LOG = 32 - __builtin_clz(n);
        table.assign(n, std::vector<int>(LOG));
        for (int i = 0; i < n; i++)
        {
            table[i][0] = v[i];
        }
        for (int j = 1; j < LOG; j++)
        {
            for (int i = 0; i + (1 << j) <= n; i++)
            {
                table[i][j] = std::min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int query(int L, int R)
    {
        int j = 31 - __builtin_clz(R - L + 1);
        return std::min(table[L][j], table[R - (1 << j) + 1][j]);
    }
};

// segment tree

struct SegmentTree
{
    std::vector<long long> Tree;
    int N;
    SegmentTree(std::vector<int> &v)
    {
        int n = v.size();
        N = 1 << (int)ceil(log2(n));
        for (int i = n; i < N; i++)
            v.emplace_back(0);
        Tree.resize(2 * N, 0);
        for (int i = 0; i < N; i++)
        {
            Tree[N + i] = v[i];
        }
        for (int i = N - 1; i >= 1; i--)
        {
            Tree[i] = Tree[2 * i] + Tree[2 * i + 1];
        }
    }
    long long sum(int query_lo, int query_hi)
    {
        return query(1, 0, N - 1, query_lo, query_hi);
    }
    long long query(int node, int node_lo, int node_hi, int query_lo, int query_hi)
    {
        if (query_lo <= node_lo && node_hi <= query_hi)
            return Tree[node];
        if (node_hi < query_lo || query_hi < node_lo)
            return 0LL;
        int last_in_left = (node_lo + node_hi) / 2;
        return query(2 * node, node_lo, last_in_left, query_lo, query_hi) + query(2 * node + 1, last_in_left + 1, node_hi, query_lo, query_hi);
    }

    void update(int pos, int val)
    {
        Tree[N + pos] = val;
        for (int j = (N + pos) / 2; j >= 1; j /= 2)
        {
            Tree[j] = Tree[2 * j] + Tree[2 * j + 1];
        }
    }
};

int main()
{

    return 0;
}
