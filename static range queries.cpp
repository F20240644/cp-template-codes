#include <bits/stdc++.h>
using namespace std;

//1-D prefix sums

class PrefixSum
{
private:
    std::vector<long long> ps;

public:
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


int main(){

    return 0;
}