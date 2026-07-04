#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Maximum Subarray Sum

Given an array of n integers, your task is to find the maximum sum of values
in a contiguous, nonempty subarray.

Input
The first input line has an integer n: the size of the array.

The second line has n integers x_1, x_2, ..., x_n: the array values.

Output
Print one integer: the maximum subarray sum.

Constraints:
1 <= n <= 2 * 10^5
-10^9 <= x_i <= 10^9
*/
int main() {

    int n;
    cin >> n;

    vector<long long> values(n);

    for (int i = 0; i < n; i++) {

        cin >> values[i];

    }

    long long currentSum = values[0];
    long long bestSum = values[0];

    // At each position, decide whether to extend the previous subarray
    // or start a new subarray from the current value.
    for (int i = 1; i < n; i++) {

        currentSum = max(values[i], currentSum + values[i]);
        bestSum = max(bestSum, currentSum);

    }

    cout << bestSum << '\n';

    return 0;

}