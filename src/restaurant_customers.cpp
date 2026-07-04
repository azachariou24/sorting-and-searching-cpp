#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Restaurant Customers

You are given the arrival and leaving times of n customers in a restaurant.

What was the maximum number of customers in the restaurant at any time?

Input
The first input line has an integer n: the number of customers.

After this, there are n lines that describe the customers. Each line has two
integers a and b: the arrival and leaving times of a customer.

You may assume that all arrival and leaving times are distinct.

Output
Print one integer: the maximum number of customers.

Constraints:
1 <= n <= 2 * 10^5
1 <= a < b <= 10^9
*/
int main() {

    int n;
    cin >> n;

    vector<pair<int, int>> events;

    for (int i = 0; i < n; i++) {

        int arrivalTime;
        int leavingTime;

        cin >> arrivalTime >> leavingTime;

        // Arrival increases the number of customers inside the restaurant.
        events.push_back({arrivalTime, 1});

        // Leaving decreases the number of customers inside the restaurant.
        events.push_back({leavingTime, -1});

    }

    // Sort events by time so that we can process the restaurant timeline
    // from earliest to latest.
    sort(events.begin(), events.end());

    int currentCustomers = 0;
    int maximumCustomers = 0;

    for (auto event : events) {

        currentCustomers += event.second;
        maximumCustomers = max(maximumCustomers, currentCustomers);

    }

    cout << maximumCustomers << '\n';

    return 0;

}