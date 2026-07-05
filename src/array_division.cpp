#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Array Division

You are given an array containing n positive integers.

Your task is to divide the array into k subarrays so that the maximum sum in a
subarray is as small as possible.

Input
The first input line contains two integers n and k: the size of the array and
the number of subarrays in the division.

The next line contains n integers x_1, x_2, ..., x_n: the contents of the array.

Output
Print one integer: the maximum sum in a subarray in the optimal division.

Constraints:
1 <= n <= 2 * 10^5
1 <= k <= n
1 <= x_i <= 10^9
*/

bool canDivide(const vector<long long>& values, int k, long long maximumAllowedSum) {

    int subarraysUsed = 1;
    long long currentSum = 0;

    for (long long value : values) {

        // If adding the current value would exceed the allowed sum,
        // start a new subarray.
        if (currentSum + value > maximumAllowedSum) {

            subarraysUsed++;
            currentSum = value;

        } else {

            currentSum += value;

        }

    }

    return subarraysUsed <= k;

}

int main() {

    int n, k;
    cin >> n >> k;

    vector<long long> values(n);

    long long left = 0;
    long long right = 0;

    for (int i = 0; i < n; i++) {

        cin >> values[i];

        // The answer must be at least the largest single value.
        left = max(left, values[i]);

        // The answer is at most the sum of the whole array.
        right += values[i];

    }

    long long answer = right;

    while (left <= right) {

        long long middle = left + (right - left) / 2;

        if (canDivide(values, k, middle)) {

            answer = middle;
            right = middle - 1;

        } else {

            left = middle + 1;

        }

    }

    cout << answer << '\n';

    return 0;

}