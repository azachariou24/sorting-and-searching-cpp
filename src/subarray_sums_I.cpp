#include <iostream>
#include <vector>

using namespace std;

/*
Subarray Sums I

Given an array of n positive integers, your task is to count the number of
subarrays having sum x.

Input
The first input line has two integers n and x: the size of the array and the
target sum x.

The next line has n integers a_1, a_2, ..., a_n: the contents of the array.

Output
Print one integer: the required number of subarrays.

Constraints:
1 <= n <= 2 * 10^5
1 <= x, a_i <= 10^9
*/
int main() {

    int n;
    long long x;
    cin >> n >> x;

    vector<long long> values(n);

    for (int i = 0; i < n; i++) {

        cin >> values[i];

    }

    int left = 0;
    long long currentSum = 0;
    long long subarrayCount = 0;

    for (int right = 0; right < n; right++) {

        currentSum += values[right];

        // Since all values are positive, increasing left decreases the sum.
        while (currentSum > x && left <= right) {

            currentSum -= values[left];
            left++;

        }

        if (currentSum == x) {

            subarrayCount++;

        }

    }

    cout << subarrayCount << '\n';

    return 0;

}