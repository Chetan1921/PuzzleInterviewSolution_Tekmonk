#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int minimumEnergy(int startFloor, const vector<int> &requests)
{
    int energy = 0;
    int currentFloor = startFloor;

    for (int floor : requests)
    {
        energy += 5;                         // Lift start cost
        energy += abs(currentFloor - floor); // Travel cost

        currentFloor = floor;
    }

    return energy;
}

int main()
{
    int n;

    cout << "Enter number of requests: ";
    cin >> n;

    vector<int> requests(n);

    cout << "Enter requested floors:\n";

    for (int i = 0; i < n; i++)
        cin >> requests[i];

    int startFloor;

    cout << "Enter initial lift floor: ";
    cin >> startFloor;

    cout << "Minimum Energy Required: "
         << minimumEnergy(startFloor, requests)
         << endl;

    return 0;
}