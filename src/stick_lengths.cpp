#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

/*
Stick Lengths

There are n sticks with some lengths. Your task is to modify the sticks so
that each stick has the same length.

You can either lengthen or shorten each stick. Both operations cost x where x
is the difference between the new and original length.

What is the minimum total cost?

Input
The first input line contains an integer n: the number of sticks.

Then there are n integers p_1, p_2, ..., p_n: the lengths of the sticks.

Output
Print one integer: the minimum total cost.

Constraints:
1 <= n <= 2 * 10^5
1 <= p_i <= 10^9
*/
int main() {

    int n;
    cin >> n;

    vector<long long> sticks(n);

    for (int i = 0; i < n; i++) {

        cin >> sticks[i];

    }

    // Sort the stick lengths so that the median can be selected directly.
    sort(sticks.begin(), sticks.end());

    long long targetLength = sticks[n / 2];
    long long totalCost = 0;

    // The median minimizes the sum of absolute differences.
    for (int i = 0; i < n; i++) {

        totalCost += llabs(sticks[i] - targetLength);

    }

    cout << totalCost << '\n';

    return 0;

}