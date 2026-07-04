#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Movie Festival

In a movie festival n movies will be shown. You know the starting and ending
time of each movie.

What is the maximum number of movies you can watch entirely?

Input
The first input line has an integer n: the number of movies.

After this, there are n lines that describe the movies. Each line has two
integers a and b: the starting and ending times of a movie.

Output
Print one integer: the maximum number of movies.

Constraints:
1 <= n <= 2 * 10^5
1 <= a < b <= 10^9
*/
int main() {

    int n;
    cin >> n;

    vector<pair<int, int>> movies;

    for (int i = 0; i < n; i++) {

        int startTime;
        int endTime;

        cin >> startTime >> endTime;

        movies.push_back({endTime, startTime});

    }

    // Sort movies by their ending time.
    sort(movies.begin(), movies.end());

    int watchedMovies = 0;
    int currentEndingTime = 0;

    // Always choose the next movie that finishes earliest
    // among all remaining compatible movies.
    for (auto movie : movies) {

        int endTime = movie.first;
        int startTime = movie.second;

        if (startTime >= currentEndingTime) {

            watchedMovies++;
            currentEndingTime = endTime;

        }

    }

    cout << watchedMovies << '\n';

    return 0;

}