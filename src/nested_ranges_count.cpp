#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Nested Ranges Count

Given n ranges, your task is to count for each range how many other ranges it
contains and how many other ranges contain it.

Range [a,b] contains range [c,d] if a <= c and d <= b.

Input
The first input line has an integer n: the number of ranges.

After this, there are n lines that describe the ranges. Each line has two
integers x and y: the range is [x,y].

You may assume that no range appears more than once in the input.

Output
First print a line that describes for each range in the input order how many
other ranges it contains.

Then print a line that describes for each range in the input order how many
other ranges contain it.

Constraints:
1 <= n <= 2 * 10^5
1 <= x < y <= 10^9
*/

struct Range {

    int left;
    int right;
    int index;

};

class FenwickTree {

private:

    int size;
    vector<int> tree;

public:

    FenwickTree(int n) {

        size = n;
        tree.assign(n + 1, 0);

    }

    void add(int index, int value) {

        while (index <= size) {

            tree[index] += value;
            index += index & -index;

        }

    }

    int sum(int index) {

        int result = 0;

        while (index > 0) {

            result += tree[index];
            index -= index & -index;

        }

        return result;

    }

};

bool compareRanges(const Range& first, const Range& second) {

    if (first.left == second.left) {

        return first.right > second.right;

    }

    return first.left < second.left;

}

int main() {

    int n;
    cin >> n;

    vector<Range> ranges(n);
    vector<int> rightEndpoints;

    for (int i = 0; i < n; i++) {

        cin >> ranges[i].left >> ranges[i].right;
        ranges[i].index = i;

        rightEndpoints.push_back(ranges[i].right);

    }

    // Coordinate compression for right endpoints.
    sort(rightEndpoints.begin(), rightEndpoints.end());
    rightEndpoints.erase(unique(rightEndpoints.begin(), rightEndpoints.end()), rightEndpoints.end());

    sort(ranges.begin(), ranges.end(), compareRanges);

    vector<int> containsOther(n, 0);
    vector<int> containedByOther(n, 0);

    FenwickTree containsTree(rightEndpoints.size());

    // Count how many later ranges have right endpoint <= current right endpoint.
    // These are the ranges contained by the current range.
    for (int i = n - 1; i >= 0; i--) {

        int compressedRight = lower_bound(rightEndpoints.begin(), rightEndpoints.end(), ranges[i].right)
                              - rightEndpoints.begin() + 1;

        containsOther[ranges[i].index] = containsTree.sum(compressedRight);

        containsTree.add(compressedRight, 1);

    }

    FenwickTree containedTree(rightEndpoints.size());

    // Count how many previous ranges have right endpoint >= current right endpoint.
    // These are the ranges that contain the current range.
    for (int i = 0; i < n; i++) {

        int compressedRight = lower_bound(rightEndpoints.begin(), rightEndpoints.end(), ranges[i].right)
                              - rightEndpoints.begin() + 1;

        int previousRanges = i;
        int previousWithSmallerRight = containedTree.sum(compressedRight - 1);

        containedByOther[ranges[i].index] = previousRanges - previousWithSmallerRight;

        containedTree.add(compressedRight, 1);

    }

    for (int i = 0; i < n; i++) {

        cout << containsOther[i] << ' ';

    }

    cout << '\n';

    for (int i = 0; i < n; i++) {

        cout << containedByOther[i] << ' ';

    }

    cout << '\n';

    return 0;

}