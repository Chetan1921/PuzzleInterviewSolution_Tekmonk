#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int minimumEnergy(int startFloor, const vector<int> &requests)
{
    // 1. Manually filter out requests that match the startFloor (0 energy burned)
    vector<int> filteredRequests;
    for (int floor : requests) {
        if (floor != startFloor) {
            filteredRequests.push_back(floor);
        }
    }

    // If there were no other requests, no energy is burned at all
    if (filteredRequests.empty()) {
        return 0;
    }

    // 2. Sort the remaining requests to plan the path
    sort(filteredRequests.begin(), filteredRequests.end());

    // 3. Manually remove duplicate floors (Deduplication)
    vector<int> uniqueRequests;
    uniqueRequests.push_back(filteredRequests[0]);
    
    for (size_t i = 1; i < filteredRequests.size(); i++) {
        // Only collect the floor if it differs from the previous one
        if (filteredRequests[i] != filteredRequests[i - 1]) {
            uniqueRequests.push_back(filteredRequests[i]);
        }
    }

    // Calculate fixed stop costs (5 units per unique floor)
    int numStops = uniqueRequests.size();
    int totalStopCost = numStops * 5; 

    // Find the extreme boundary floors
    int minFloor = uniqueRequests.front();
    int maxFloor = uniqueRequests.back();

    // Scenario A: Start floor is completely outside or at the edge of the remaining requests
    if (startFloor <= minFloor) {
        return totalStopCost + (maxFloor - startFloor);
    }
    if (startFloor >= maxFloor) {
        return totalStopCost + (startFloor - minFloor);
    }

    // Scenario B: Start floor is in the middle of the requests. Evaluate both directions.
    // Path 1: Down to the lowest floor first, then turn around up to the highest floor
    int distDownFirst = (startFloor - minFloor) + (maxFloor - minFloor);

    // Path 2: Up to the highest floor first, then turn around down to the lowest floor
    int distUpFirst = (maxFloor - startFloor) + (maxFloor - minFloor);

    int minDistance = min(distDownFirst, distUpFirst);

    return totalStopCost + minDistance;
}

int main()
{
    int n;
    cout << "Enter number of requests: ";
    cin >> n;

    vector<int> requests(n);
    cout << "Enter requested floors:\n";
    for (int i = 0; i < n; i++) {
        cin >> requests[i];
    }

    int startFloor;
    cout << "Enter initial lift floor: ";
    cin >> startFloor;

    cout << "Minimum Energy Required: "
         << minimumEnergy(startFloor, requests)
         << endl;

    return 0;
}
