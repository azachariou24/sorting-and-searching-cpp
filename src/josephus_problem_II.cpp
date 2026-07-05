#include <iostream>
#include <vector>

using namespace std;

/*
Josephus Problem II

Consider a game where there are n children numbered 1, 2, ..., n in a circle.

During the game, repeatedly k children are skipped and one child is removed
from the circle.

In which order will the children be removed?

Input
The only input line has two integers n and k.

Output
Print n integers: the removal order.

Constraints:
1 <= n <= 2 * 10^5
0 <= k <= 10^9
*/

class FenwickTree {

private:

    int size;
    vector<int> tree;

public:

    FenwickTree(int n) {

        size = n;
        tree.assign(n + 1, 0);

    }

    // Add value to a specific position.
    // In this problem, +1 means a child is alive and -1 means a child is removed.
    void add(int index, int value) {

        while (index <= size) {

            tree[index] += value;
            index += index & -index;

        }

    }

    // Find the position of the child that is the given alive-order.
    // For example, order = 3 means: find the 3rd currently alive child.
    int findByOrder(int order) {

        int index = 0;
        int bit = 1;

        // Find the largest power of two not greater than size.
        while (bit * 2 <= size) {

            bit *= 2;

        }

        // Binary lifting over the Fenwick Tree.
        // We build the largest index whose prefix sum is still smaller than order.
        while (bit > 0) {

            int nextIndex = index + bit;

            if (nextIndex <= size && tree[nextIndex] < order) {

                index = nextIndex;
                order -= tree[nextIndex];

            }

            bit /= 2;

        }

        // The next position is the first one whose prefix sum reaches order.
        return index + 1;

    }

};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    FenwickTree fenwick(n);

    // Initially, every child is alive.
    for (int child = 1; child <= n; child++) {

        fenwick.add(child, 1);

    }

    int currentIndex = 0;

    for (int aliveChildren = n; aliveChildren >= 1; aliveChildren--) {

        // Skip k alive children and remove the next one.
        currentIndex = (currentIndex + k) % aliveChildren;

        // Convert the alive-order into the original child number.
        int removedChild = fenwick.findByOrder(currentIndex + 1);

        cout << removedChild << ' ';

        // Mark this child as removed.
        fenwick.add(removedChild, -1);

    }

    cout << '\n';

    return 0;

}