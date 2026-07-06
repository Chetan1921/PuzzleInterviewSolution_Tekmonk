#include <iostream>
using namespace std;

long long minimumApples(int gates)
{
    long long apples = 1;

    // Work backwards from the last gate
    for (int i = 0; i < gates; i++)
    {
        apples = 2 * (apples + 1);
    }

    return apples;
}

int main()
{
    int gates;

    cout << "Enter number of gates: ";
    cin >> gates;

    cout << "Minimum apples required: "
         << minimumApples(gates) << endl;

    return 0;
}