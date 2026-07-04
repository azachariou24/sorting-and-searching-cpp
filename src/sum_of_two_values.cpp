#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Sum of Two Values

You are given an array of n integers, and your task is to find two values
at distinct positions whose sum is x.

Input
The first input line has two integers n and x: the array size and the target sum.

The second line has n integers a_1, a_2, ..., a_n: the array values.

Output
Print two integers: the positions of the values. If there are several solutions,
you may print any of them. If there are no solutions, print IMPOSSIBLE.

Constraints:
1 <= n <= 2 * 10^5
1 <= x, a_i <= 10^9
*/
int main() {

    int n;
    long long x;
    cin >> n >> x;

    vector<pair<long long, int>> values(n);

    for (int i = 0; i < n; i++) {

        long long value;
        cin >> value;

        // Store each value together with its original 1-based position.
        values[i] = {value, i + 1};

    }

    // Sort values so that the two-pointer technique can be applied.
    sort(values.begin(), values.end());

    int left = 0;
    int right = n - 1;

    while (left < right) {

        long long currentSum = values[left].first + values[right].first;

        if (currentSum == x) {

            cout << values[left].second << ' ' << values[right].second << '\n';
            return 0;

        } else if (currentSum < x) {

            left++;

        } else {

            right--;

        }

    }

    cout << "IMPOSSIBLE\n";

    return 0;

}