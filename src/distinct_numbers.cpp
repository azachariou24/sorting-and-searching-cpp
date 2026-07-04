#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Distinct Numbers

You are given a list of n integers, and your task is to calculate the number
of distinct values in the list.

Input
The first input line has an integer n: the number of values.
The second line has n integers x_1, x_2, ..., x_n.

Output
Print one integer: the number of distinct values.

Constraints:
1 <= n <= 2 * 10^5
1 <= x_i <= 10^9
*/
int main() {

    int n;
    cin >> n;

    vector<int> numbers(n);

    for (int i = 0; i < n; i++) {

        cin >> numbers[i];

    }

    // Sort the values so that equal numbers become adjacent.
    sort(numbers.begin(), numbers.end());

    int distinctValues = 1;

    // Count a new distinct value whenever the current value differs
    // from the previous one.
    for (int i = 1; i < n; i++) {

        if (numbers[i] != numbers[i - 1]) {

            distinctValues++;

        }

    }

    cout << distinctValues << '\n';

    return 0;

}