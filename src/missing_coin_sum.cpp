#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Missing Coin Sum

You have n coins with positive integer values. What is the smallest sum you
cannot create using a subset of the coins?

Input
The first line has an integer n: the number of coins.

The second line has n integers x_1, x_2, ..., x_n: the value of each coin.

Output
Print one integer: the smallest coin sum.

Constraints:
1 <= n <= 2 * 10^5
1 <= x_i <= 10^9
*/
int main() {

    int n;
    cin >> n;

    vector<long long> coins(n);

    for (int i = 0; i < n; i++) {

        cin >> coins[i];

    }

    // Sort the coins so that we process them from smallest to largest.
    sort(coins.begin(), coins.end());

    long long smallestMissingSum = 1;

    for (int i = 0; i < n; i++) {

        // We can currently create all sums from 1 to smallestMissingSum - 1.
        // If the next coin is larger than smallestMissingSum, then this sum
        // cannot be created.
        if (coins[i] > smallestMissingSum) {

            break;

        }

        // Since coins[i] <= smallestMissingSum, this coin extends the reachable
        // range up to smallestMissingSum + coins[i] - 1.
        smallestMissingSum += coins[i];

    }

    cout << smallestMissingSum << '\n';

    return 0;

}