#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Ferris Wheel

There are n children who want to go to a Ferris wheel, and your task is to find
a gondola for each child.

Each gondola may have one or two children in it, and the total weight in a
gondola may not exceed x. You know the weight of every child.

What is the minimum number of gondolas needed for the children?

Input
The first input line contains two integers n and x: the number of children and
the maximum allowed weight.

The next line contains n integers p_1, p_2, ..., p_n: the weight of each child.

Output
Print one integer: the minimum number of gondolas.

Constraints:
1 <= n <= 2 * 10^5
1 <= x <= 10^9
1 <= p_i <= x
*/
int main() {

    int n;
    long long x;
    cin >> n >> x;

    vector<long long> weights(n);

    for (int i = 0; i < n; i++) {

        cin >> weights[i];

    }

    // Sort the weights so that the lightest and heaviest remaining
    // children can be considered together.
    sort(weights.begin(), weights.end());

    int left = 0;
    int right = n - 1;
    int gondolas = 0;

    // Each iteration assigns the heaviest remaining child to a gondola.
    while (left <= right) {

        // If the lightest and heaviest remaining children fit together,
        // place them in the same gondola.
        if (weights[left] + weights[right] <= x) {

            left++;
            right--;

        // Otherwise, the heaviest child must ride alone.
        } else {

            right--;

        }

        gondolas++;

    }

    cout << gondolas << '\n';

    return 0;

}