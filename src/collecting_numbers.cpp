#include <iostream>
#include <vector>

using namespace std;

/*
Collecting Numbers

You are given an array that contains each number between 1 ... n exactly once.
Your task is to collect the numbers from 1 to n in increasing order.

On each round, you go through the array from left to right and collect as many
numbers as possible.

What will be the total number of rounds?

Input
The first line has an integer n: the array size.

The next line has n integers x_1, x_2, ..., x_n: the numbers in the array.

Output
Print one integer: the number of rounds.

Constraints:
1 <= n <= 2 * 10^5
*/
int main() {

    int n;
    cin >> n;

    vector<int> position(n + 1);

    for (int i = 1; i <= n; i++) {

        int value;
        cin >> value;

        // Store the original position of each value.
        position[value] = i;

    }

    int rounds = 1;

    // A new round is needed whenever the next required number appears
    // before the previous required number in the array.
    for (int value = 2; value <= n; value++) {

        if (position[value] < position[value - 1]) {

            rounds++;

        }

    }

    cout << rounds << '\n';

    return 0;

}