#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/*
Movie Festival II

In a movie festival, n movies will be shown. Syrjälä's movie club consists of
k members, who will be all attending the festival.

You know the starting and ending time of each movie.

What is the maximum total number of movies the club members can watch entirely
if they act optimally?

Input
The first input line has two integers n and k: the number of movies and club
members.

After this, there are n lines that describe the movies. Each line has two
integers a and b: the starting and ending time of a movie.

Output
Print one integer: the maximum total number of movies.

Constraints:
1 <= k <= n <= 2 * 10^5
1 <= a < b <= 10^9
*/
int main() {

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> movies(n);

    for (int i = 0; i < n; i++) {

        int startTime;
        int endTime;

        cin >> startTime >> endTime;

        // Store movies by ending time first for greedy sorting.
        movies[i] = {endTime, startTime};

    }

    // Process movies in increasing order of ending time.
    sort(movies.begin(), movies.end());

    multiset<int> memberEndTimes;

    // Initially, every member is available at time 0.
    for (int i = 0; i < k; i++) {

        memberEndTimes.insert(0);

    }

    int watchedMovies = 0;

    for (auto movie : movies) {

        int endTime = movie.first;
        int startTime = movie.second;

        // Find the first member whose ending time is greater than startTime.
        auto member = memberEndTimes.upper_bound(startTime);

        if (member == memberEndTimes.begin()) {

            // No member is available before this movie starts.
            continue;

        }

        // Move one step back to get the available member who finished latest.
        member--;

        memberEndTimes.erase(member);
        memberEndTimes.insert(endTime);

        watchedMovies++;

    }

    cout << watchedMovies << '\n';

    return 0;

}