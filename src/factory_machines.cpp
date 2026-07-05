#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Factory Machines

A factory has n machines which can be used to make products. Your goal is to
make a total of t products.

For each machine, you know the number of seconds it needs to make a single
product. The machines can work simultaneously, and you can freely decide their
schedule.

What is the shortest time needed to make t products?

Input
The first input line has two integers n and t: the number of machines and
products.

The next line has n integers k_1, k_2, ..., k_n: the time needed to make a
product using each machine.

Output
Print one integer: the minimum time needed to make t products.

Constraints:
1 <= n <= 2 * 10^5
1 <= t <= 10^9
1 <= k_i <= 10^9
*/
int main() {

    int n;
    long long t;
    cin >> n >> t;

    vector<long long> machines(n);

    for (int i = 0; i < n; i++) {

        cin >> machines[i];

    }

    long long left = 1;
    long long right = *min_element(machines.begin(), machines.end()) * t;
    long long answer = right;

    while (left <= right) {

        long long middle = left + (right - left) / 2;
        long long products = 0;

        // Count how many products can be produced within middle seconds.
        for (int i = 0; i < n; i++) {

            products += middle / machines[i];

            // Stop early to avoid unnecessary work and possible overflow.
            if (products >= t) {

                break;

            }

        }

        if (products >= t) {

            answer = middle;
            right = middle - 1;

        } else {

            left = middle + 1;

        }

    }

    cout << answer << '\n';

    return 0;

}