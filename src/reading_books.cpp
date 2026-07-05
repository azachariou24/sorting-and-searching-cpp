#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Reading Books

There are n books, and Kotivalo and Justiina are going to read them all.

For each book, you know the time it takes to read it.

They both read each book from beginning to end, and they cannot read a book
at the same time.

Find the minimum total time required.

Input
The first input line has an integer n: the number of books.

The second line has n integers t_1, t_2, ..., t_n: the reading times.

Output
Print one integer: the minimum total time.

Constraints:
1 <= n <= 2 * 10^5
1 <= t_i <= 10^9
*/
int main() {

    int n;
    cin >> n;

    long long totalTime = 0;
    long long longestBook = 0;

    for (int i = 0; i < n; i++) {

        long long readingTime;
        cin >> readingTime;

        totalTime += readingTime;
        longestBook = max(longestBook, readingTime);

    }

    // The answer is determined by the stronger of the two lower bounds:
    // - The total amount of reading.
    // - Reading the longest book twice (once by each person).
    cout << max(totalTime, 2 * longestBook) << '\n';

    return 0;

}