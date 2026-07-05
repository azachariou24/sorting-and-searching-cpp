#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
Subarray Distinct Values

Given an array of n integers, your task is to calculate the number of subarrays
that have at most k distinct values.

Input
The first input line has two integers n and k.

The next line has n integers x_1, x_2, ..., x_n: the contents of the array.

Output
Print one integer: the number of subarrays.

Constraints:
1 <= k <= n <= 2 * 10^5
1 <= x_i <= 10^9
*/
int main() {

    int n, k;
    cin >> n >> k;

    vector<int> values(n);

    for (int i = 0; i < n; i++) {

        cin >> values[i];

    }

    map<int, int> frequency;

    int left = 0;
    int distinctValues = 0;
    long long subarrayCount = 0;

    for (int right = 0; right < n; right++) {

        // Add the current value to the window.
        if (frequency[values[right]] == 0) {

            distinctValues++;

        }

        frequency[values[right]]++;

        // Shrink the window until it contains at most k distinct values.
        while (distinctValues > k) {

            frequency[values[left]]--;

            if (frequency[values[left]] == 0) {

                distinctValues--;

            }

            left++;

        }

        // All subarrays ending at right and starting between left and right
        // contain at most k distinct values.
        subarrayCount += right - left + 1;

    }

    cout << subarrayCount << '\n';

    return 0;

}