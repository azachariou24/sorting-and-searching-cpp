#include <iostream>
#include <list>

using namespace std;

/*
Josephus Problem I

Consider a game where there are n children (numbered 1, 2, ..., n) in a circle.

During the game, every other child is removed from the circle until there are
no children left.

Print the order in which the children are removed.

Input
The only input line has an integer n.

Output
Print n integers: the removal order.

Constraints:
1 <= n <= 2 * 10^5
*/
int main() {

    int n;
    cin >> n;

    list<int> children;

    for (int i = 1; i <= n; i++) {

        children.push_back(i);

    }

    auto current = children.begin();

    while (!children.empty()) {

        // Move to the child that will be removed.
        current++;

        if (current == children.end()) {

            current = children.begin();

        }

        cout << *current << ' ';

        // Store the iterator to the next child before removing the current one.
        auto nextChild = children.erase(current);

        if (children.empty()) {

            break;

        }

        if (nextChild == children.end()) {

            current = children.begin();

        } else {

            current = nextChild;

        }

    }

    cout << '\n';

    return 0;

}