#include <iostream>
#include <set>

using namespace std;

/*
Traffic Lights

There is a street of length x whose positions are numbered 0, 1, ..., x.
Initially there are no traffic lights, but n sets of traffic lights are added
to the street one after another.

Your task is to calculate the length of the longest passage without traffic
lights after each addition.

Input
The first input line contains two integers x and n: the length of the street
and the number of sets of traffic lights.

Then, the next line contains n integers p_1, p_2, ..., p_n: the position of each
set of traffic lights. Each position is distinct.

Output
Print the length of the longest passage without traffic lights after each
addition.

Constraints:
1 <= x <= 10^9
1 <= n <= 2 * 10^5
0 < p_i < x
*/
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n;
    cin >> x >> n;

    set<int> trafficLights;
    multiset<int> passages;

    trafficLights.insert(0);
    trafficLights.insert(x);

    passages.insert(x);

    for (int i = 0; i < n; i++) {

        int position;
        cin >> position;

        // Find the first existing traffic light to the right of the new one.
        auto rightLight = trafficLights.upper_bound(position);

        // The previous traffic light is the one directly to the left.
        auto leftLight = prev(rightLight);

        int leftPosition = *leftLight;
        int rightPosition = *rightLight;

        // The old passage between leftPosition and rightPosition is split.
        passages.erase(passages.find(rightPosition - leftPosition));

        passages.insert(position - leftPosition);
        passages.insert(rightPosition - position);

        trafficLights.insert(position);

        // The largest current passage is the last element of the multiset.
        cout << *passages.rbegin() << ' ';

    }

    cout << '\n';

    return 0;

}