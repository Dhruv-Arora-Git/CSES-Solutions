#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long sum = (n * (n + 1ll)) / 2;
    long long sum_input = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int a;
        cin >> a;
        sum_input += a;
    }
    cout << (sum - sum_input) << '\n';
    return 0;
}