#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

/*
Maximum Subarray Sum II

Given an array of n integers, your task is to find the maximum sum of values
in a contiguous subarray with length between a and b.

Input
The first input line has three integers n, a and b: the size of the array and
the minimum and maximum subarray length.

The second line has n integers x_1, x_2, ..., x_n: the array values.

Output
Print one integer: the maximum subarray sum.

Constraints:
1 <= n <= 2 * 10^5
1 <= a <= b <= n
-10^9 <= x_i <= 10^9
*/
int main() {

    int n, a, b;
    cin >> n >> a >> b;

    vector<long long> prefix(n + 1, 0);

    for (int i = 1; i <= n; i++) {

        long long value;
        cin >> value;

        prefix[i] = prefix[i - 1] + value;

    }

    multiset<long long> candidatePrefixes;

    long long maximumSum = LLONG_MIN;

    for (int right = a; right <= n; right++) {

        // Add prefix[right - a], which corresponds to the shortest valid length.
        candidatePrefixes.insert(prefix[right - a]);

        // Remove prefix[right - b - 1], because it would make the length too large.
        if (right - b - 1 >= 0) {

            candidatePrefixes.erase(candidatePrefixes.find(prefix[right - b - 1]));

        }

        // The best subarray ending at right uses the smallest valid prefix.
        maximumSum = max(maximumSum, prefix[right] - *candidatePrefixes.begin());

    }

    cout << maximumSum << '\n';

    return 0;

}