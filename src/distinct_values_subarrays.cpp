#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
Distinct Values Subarrays

Given an array of n integers, count the number of subarrays where each element
is distinct.

Input
The first line has an integer n: the array size.

The second line has n integers x_1, x_2, ..., x_n: the array contents.

Output
Print the number of subarrays with distinct elements.

Constraints:
1 <= n <= 2 * 10^5
1 <= x_i <= 10^9
*/
int main() {

    int n;
    cin >> n;

    vector<int> values(n);

    for (int i = 0; i < n; i++) {

        cin >> values[i];

    }

    map<int, int> lastPosition;

    int left = 0;
    long long distinctSubarrays = 0;

    for (int right = 0; right < n; right++) {

        int currentValue = values[right];

        // If the current value already appeared inside the current window,
        // move the left boundary after its previous occurrence.
        if (lastPosition.count(currentValue)) {

            left = max(left, lastPosition[currentValue] + 1);

        }

        lastPosition[currentValue] = right;

        // All subarrays ending at right and starting between left and right
        // have distinct values.
        distinctSubarrays += right - left + 1;

    }

    cout << distinctSubarrays << '\n';

    return 0;

}