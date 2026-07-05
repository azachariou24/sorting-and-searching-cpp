#include <iostream>
#include <vector>

using namespace std;

/*
Nearest Smaller Values

Given an array of n integers, your task is to find for each array position the
nearest position to its left having a smaller value.

Input
The first input line has an integer n: the size of the array.

The second line has n integers x_1, x_2, ..., x_n: the array values.

Output
Print n integers: for each array position the nearest position with a smaller
value. If there is no such position, print 0.

Constraints:
1 <= n <= 2 * 10^5
1 <= x_i <= 10^9
*/
int main() {

    int n;
    cin >> n;

    vector<pair<int, int>> stackValues;

    for (int position = 1; position <= n; position++) {

        int currentValue;
        cin >> currentValue;

        // Remove all previous values that are not smaller than the current one.
        // Such values cannot be the nearest smaller value for this position.
        while (!stackValues.empty() && stackValues.back().first >= currentValue) {

            stackValues.pop_back();

        }

        // After removing larger or equal values, the top of the stack is the
        // nearest position to the left with a strictly smaller value.
        if (stackValues.empty()) {

            cout << 0 << ' ';

        } else {

            cout << stackValues.back().second << ' ';

        }

        // Add the current value as a candidate for future positions.
        stackValues.push_back({currentValue, position});

    }

    cout << '\n';

    return 0;

}