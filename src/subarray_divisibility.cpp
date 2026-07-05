#include <iostream>
#include <vector>

using namespace std;

/*
Subarray Divisibility

Given an array of n integers, your task is to count the number of subarrays
where the sum of values is divisible by n.

Input
The first input line has an integer n: the size of the array.

The next line has n integers a_1, a_2, ..., a_n: the contents of the array.

Output
Print one integer: the required number of subarrays.

Constraints:
1 <= n <= 2 * 10^5
-10^9 <= a_i <= 10^9
*/
int main() {

    int n;
    cin >> n;

    vector<long long> remainderFrequency(n, 0);

    long long currentPrefix = 0;
    long long subarrayCount = 0;

    // Empty prefix sum has remainder 0.
    remainderFrequency[0] = 1;

    for (int i = 0; i < n; i++) {

        long long value;
        cin >> value;

        currentPrefix += value;

        // Normalize the remainder because C++ can produce negative remainders.
        int remainder = ((currentPrefix % n) + n) % n;

        // Every previous prefix with the same remainder forms a valid subarray.
        subarrayCount += remainderFrequency[remainder];

        remainderFrequency[remainder]++;

    }

    cout << subarrayCount << '\n';

    return 0;

}