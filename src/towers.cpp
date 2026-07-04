#include <iostream>
#include <set>

using namespace std;

/*
Towers

You are given n cubes in a certain order, and your task is to build towers
using them. Whenever two cubes are one on top of the other, the upper cube must
be smaller than the lower cube.

You must process the cubes in the given order. You can always either place the
cube on top of an existing tower, or begin a new tower.

What is the minimum possible number of towers?

Input
The first input line contains an integer n: the number of cubes.

The next line contains n integers k_1, k_2, ..., k_n: the sizes of the cubes.

Output
Print one integer: the minimum number of towers.

Constraints:
1 <= n <= 2 * 10^5
1 <= k_i <= 10^9
*/
int main() {

    int n;
    cin >> n;

    multiset<int> towerTops;

    for (int i = 0; i < n; i++) {

        int cubeSize;
        cin >> cubeSize;

        // Find the tower with the smallest top cube that is still
        // strictly larger than the current cube.
        auto tower = towerTops.upper_bound(cubeSize);

        if (tower == towerTops.end()) {

            // No valid tower exists, so we start a new tower.
            towerTops.insert(cubeSize);

        } else {

            // Place the current cube on this tower.
            // The old top is replaced by the current cube.
            towerTops.erase(tower);
            towerTops.insert(cubeSize);

        }

    }

    cout << towerTops.size() << '\n';

    return 0;

}