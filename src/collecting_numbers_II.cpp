#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
Collecting Numbers II

You are given an array that contains each number between 1 ... n exactly once.
Your task is to collect the numbers from 1 to n in increasing order.

On each round, you go through the array from left to right and collect as many
numbers as possible.

Given m operations that swap two numbers in the array, your task is to report
the number of rounds after each operation.

Input
The first line has two integers n and m: the array size and the number of
operations.

The next line has n integers x_1, x_2, ..., x_n: the numbers in the array.

Finally, there are m lines that describe the operations. Each line has two
integers a and b: the numbers at positions a and b are swapped.

Output
Print m integers: the number of rounds after each swap.

Constraints:
1 <= n, m <= 2 * 10^5
1 <= a, b <= n
*/
int main() {

    int n, m;
    cin >> n >> m;

    vector<int> values(n + 1);
    vector<int> position(n + 1);

    for (int i = 1; i <= n; i++) {

        cin >> values[i];
        position[values[i]] = i;

    }

    int rounds = 1;

    // A new round is needed whenever value i + 1 appears before value i.
    for (int value = 1; value < n; value++) {

        if (position[value] > position[value + 1]) {

            rounds++;

        }

    }

    while (m--) {

        int a, b;
        cin >> a >> b;

        int firstValue = values[a];
        int secondValue = values[b];

        set<pair<int, int>> affectedPairs;

        // Only neighboring value pairs around the swapped values can change.
        if (firstValue > 1) {
            affectedPairs.insert({firstValue - 1, firstValue});
        }

        if (firstValue < n) {
            affectedPairs.insert({firstValue, firstValue + 1});
        }

        if (secondValue > 1) {
            affectedPairs.insert({secondValue - 1, secondValue});
        }

        if (secondValue < n) {
            affectedPairs.insert({secondValue, secondValue + 1});
        }

        // Remove the old contribution of affected pairs.
        for (auto pairValues : affectedPairs) {

            if (position[pairValues.first] > position[pairValues.second]) {

                rounds--;

            }

        }

        // Swap the values in the array.
        swap(values[a], values[b]);

        // Update their positions.
        position[firstValue] = b;
        position[secondValue] = a;

        // Add the new contribution of affected pairs.
        for (auto pairValues : affectedPairs) {

            if (position[pairValues.first] > position[pairValues.second]) {

                rounds++;

            }

        }

        cout << rounds << '\n';

    }

    return 0;

}