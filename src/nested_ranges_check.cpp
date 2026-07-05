#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Nested Ranges Check

Given n ranges, your task is to determine for each range if it contains some
other range and if some other range contains it.

Range [a,b] contains range [c,d] if a <= c and d <= b.

Input
The first input line has an integer n: the number of ranges.

After this, there are n lines that describe the ranges. Each line has two
integers x and y: the range is [x,y].

You may assume that no range appears more than once in the input.

Output
First print a line that describes for each range in the input order if it
contains some other range.

Then print a line that describes for each range in the input order if some
other range contains it.

Constraints:
1 <= n <= 2 * 10^5
1 <= x < y <= 10^9
*/

struct Range {

    int left;
    int right;
    int index;

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

    for (int i = 0; i < n; i++) {

        cin >> ranges[i].left >> ranges[i].right;
        ranges[i].index = i;

    }

    sort(ranges.begin(), ranges.end(), compareRanges);

    vector<int> containsOther(n, 0);
    vector<int> containedByOther(n, 0);

    int maximumRight = 0;

    // If a previous range has right endpoint at least as large as this one,
    // then this range is contained by that previous range.
    for (int i = 0; i < n; i++) {

        if (ranges[i].right <= maximumRight) {

            containedByOther[ranges[i].index] = 1;

        }

        maximumRight = max(maximumRight, ranges[i].right);

    }

    int minimumRight = 1000000001;

    // If a later range has right endpoint at most as large as this one,
    // then this range contains that later range.
    for (int i = n - 1; i >= 0; i--) {

        if (ranges[i].right >= minimumRight) {

            containsOther[ranges[i].index] = 1;

        }

        minimumRight = min(minimumRight, ranges[i].right);

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