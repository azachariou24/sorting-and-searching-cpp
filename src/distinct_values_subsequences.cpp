#include <iostream>
#include <map>

using namespace std;

/*
Distinct Values Subsequences

Given an array of n integers, count the number of subsequences where each
element is distinct.

A subsequence is a sequence of array elements from left to right that may have
gaps.

Input
The first line has an integer n: the array size.

The second line has n integers x_1, x_2, ..., x_n: the array contents.

Output
Print the number of subsequences with distinct elements. The answer can be
large, so print it modulo 10^9+7.

Constraints:
1 <= n <= 2 * 10^5
1 <= x_i <= 10^9
*/
int main() {

    const long long MOD = 1000000007;

    int n;
    cin >> n;

    map<int, long long> frequency;

    for (int i = 0; i < n; i++) {

        int value;
        cin >> value;

        frequency[value]++;

    }

    long long subsequences = 1;

    // For each distinct value with frequency f, we may either choose none
    // of its occurrences or choose exactly one of its f occurrences.
    for (auto entry : frequency) {

        long long count = entry.second;
        subsequences = (subsequences * (count + 1)) % MOD;

    }

    // Remove the empty subsequence.
    subsequences = (subsequences - 1 + MOD) % MOD;

    cout << subsequences << '\n';

    return 0;

}