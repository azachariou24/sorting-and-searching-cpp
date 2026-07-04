#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/*
Playlist

You are given a playlist of a radio station since its establishment. The
playlist has a total of n songs.

What is the longest sequence of successive songs where each song is unique?

Input
The first input line contains an integer n: the number of songs.

The next line has n integers k_1, k_2, ..., k_n: the id number of each song.

Output
Print the length of the longest sequence of unique songs.

Constraints:
1 <= n <= 2 * 10^5
1 <= k_i <= 10^9
*/
int main() {

    int n;
    cin >> n;

    vector<int> songs(n);

    for (int i = 0; i < n; i++) {

        cin >> songs[i];

    }

    map<int, int> lastPosition;

    int left = 0;
    int longestSequence = 0;

    for (int right = 0; right < n; right++) {

        int currentSong = songs[right];

        // If the current song already appeared inside the current window,
        // move the left boundary after its previous occurrence.
        if (lastPosition.count(currentSong)) {

            left = max(left, lastPosition[currentSong] + 1);

        }

        lastPosition[currentSong] = right;

        longestSequence = max(longestSequence, right - left + 1);

    }

    cout << longestSequence << '\n';

    return 0;

}