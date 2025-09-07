#include <bits/stdc++.h>
using namespace std;

//1-D prefix sums

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


//sparse table (for minm)

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

int main(){

    return 0;
}
