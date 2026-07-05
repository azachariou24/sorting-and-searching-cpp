#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
Sum of Four Values

You are given an array of n integers, and your task is to find four values
at distinct positions whose sum is x.

Input
The first input line has two integers n and x: the array size and the target sum.

The second line has n integers a_1, a_2, ..., a_n: the array values.

Output
Print four integers: the positions of the values. If there are several
solutions, you may print any of them. If there are no solutions, print
IMPOSSIBLE.

Constraints:
1 <= n <= 1000
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

    map<long long, pair<int, int>> previousPairs;

    for (int secondPairStart = 0; secondPairStart < n; secondPairStart++) {

        // Try to use secondPairStart and secondPairEnd as the second pair.
        for (int secondPairEnd = secondPairStart + 1; secondPairEnd < n; secondPairEnd++) {

            long long neededSum = x - values[secondPairStart] - values[secondPairEnd];

            if (previousPairs.count(neededSum)) {

                pair<int, int> firstPair = previousPairs[neededSum];

                cout << firstPair.first + 1 << ' '
                     << firstPair.second + 1 << ' '
                     << secondPairStart + 1 << ' '
                     << secondPairEnd + 1 << '\n';

                return 0;

            }

        }

        // Store pairs that end before future second pairs begin.
        // This guarantees that all four indices are distinct.
        for (int firstPairStart = 0; firstPairStart < secondPairStart; firstPairStart++) {

            long long pairSum = values[firstPairStart] + values[secondPairStart];
            previousPairs[pairSum] = {firstPairStart, secondPairStart};

        }

    }

    cout << "IMPOSSIBLE\n";

    return 0;

}