#include <iostream>
#include <map>

using namespace std;

/*
Subarray Sums II

Given an array of n integers, your task is to count the number of subarrays
having sum x.

Input
The first input line has two integers n and x: the size of the array and the
target sum x.

The next line has n integers a_1, a_2, ..., a_n: the contents of the array.

Output
Print one integer: the required number of subarrays.

Constraints:
1 <= n <= 2 * 10^5
-10^9 <= x, a_i <= 10^9
*/
int main() {

    int n;
    long long x;
    cin >> n >> x;

    map<long long, long long> prefixFrequency;

    long long currentPrefix = 0;
    long long subarrayCount = 0;

    // Empty prefix sum before reading any element.
    prefixFrequency[0] = 1;

    for (int i = 0; i < n; i++) {

        long long value;
        cin >> value;

        currentPrefix += value;

        // We need a previous prefix sum equal to currentPrefix - x.
        // Each occurrence creates one valid subarray ending at the current position.
        subarrayCount += prefixFrequency[currentPrefix - x];

        // Store the current prefix sum for future subarrays.
        prefixFrequency[currentPrefix]++;

    }

    cout << subarrayCount << '\n';

    return 0;

}