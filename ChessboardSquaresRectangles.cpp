#include <iostream>

using namespace std;

long long totalSquares(int n)
{
    return 1LL * n * (n + 1) * (2 * n + 1) / 6;
}

long long totalRectangles(int n)
{
    long long x = 1LL * n * (n + 1) / 2;
    return x * x;
}

int main()
{
    int n;

    cout << "Enter board size: ";
    cin >> n;

    cout << "Total Squares   : "
         << totalSquares(n) << endl;

    cout << "Total Rectangles: "
         << totalRectangles(n) << endl;

    return 0;
}