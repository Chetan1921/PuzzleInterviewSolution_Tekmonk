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

long long rectanglesExcludingSquares(int n)
{
    return totalRectangles(n) - totalSquares(n);
}

int main()
{
    int n;
    cin >> n;

    cout << "Squares: " << totalSquares(n) << endl;
    cout << "Total Rectangles (including squares): "
         << totalRectangles(n) << endl;
    cout << "Rectangles (excluding squares): "
         << rectanglesExcludingSquares(n) << endl;

    return 0;
}
