#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
Room Allocation

There is a large hotel, and n customers will arrive soon. Each customer wants
to have a single room.

You know each customer's arrival and departure day. Two customers can stay in
the same room if the departure day of the first customer is earlier than the
arrival day of the second customer.

What is the minimum number of rooms that are needed to accommodate all
customers? And how can the rooms be allocated?

Input
The first input line contains an integer n: the number of customers.

Then there are n lines, each of which describes one customer. Each line has two
integers a and b: the arrival and departure day.

Output
Print first an integer k: the minimum number of rooms required.

After that, print a line that contains the room number of each customer in the
same order as in the input.

Constraints:
1 <= n <= 2 * 10^5
1 <= a <= b <= 10^9
*/

struct Customer {

    int arrival;
    int departure;
    int index;

};

bool compareCustomers(const Customer& first, const Customer& second) {

    return first.arrival < second.arrival;

}

int main() {

    int n;
    cin >> n;

    vector<Customer> customers(n);
    vector<int> assignedRoom(n);

    for (int i = 0; i < n; i++) {

        cin >> customers[i].arrival >> customers[i].departure;
        customers[i].index = i;

    }

    // Process customers in increasing order of arrival day.
    sort(customers.begin(), customers.end(), compareCustomers);

    // The priority queue stores currently occupied rooms.
    // The room with the earliest departure day is always on top.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedRooms;

    int totalRooms = 0;

    for (const Customer& customer : customers) {

        int roomNumber;

        // A room can be reused only if its previous customer leaves
        // strictly before the current customer arrives.
        if (!occupiedRooms.empty() && occupiedRooms.top().first < customer.arrival) {

            roomNumber = occupiedRooms.top().second;
            occupiedRooms.pop();

        } else {

            totalRooms++;
            roomNumber = totalRooms;

        }

        assignedRoom[customer.index] = roomNumber;

        // The room is now occupied until this customer's departure day.
        occupiedRooms.push({customer.departure, roomNumber});

    }

    cout << totalRooms << '\n';

    for (int i = 0; i < n; i++) {

        cout << assignedRoom[i] << ' ';

    }

    cout << '\n';

    return 0;

}