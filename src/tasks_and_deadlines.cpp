#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Tasks and Deadlines

You have to process n tasks. Each task has a duration and a deadline, and you
will process the tasks in some order one after another.

Your reward for a task is d - f, where d is its deadline and f is your finishing
time.

The starting time is 0, and you have to process all tasks even if a task would
yield negative reward.

What is your maximum reward if you act optimally?

Input
The first input line has an integer n: the number of tasks.

After this, there are n lines that describe the tasks. Each line has two
integers a and d: the duration and deadline of the task.

Output
Print one integer: the maximum reward.

Constraints:
1 <= n <= 2 * 10^5
1 <= a, d <= 10^6
*/
int main() {

    int n;
    cin >> n;

    vector<pair<long long, long long>> tasks(n);

    for (int i = 0; i < n; i++) {

        long long duration;
        long long deadline;

        cin >> duration >> deadline;

        tasks[i] = {duration, deadline};

    }

    // To maximize the total reward, we minimize the sum of finishing times.
    // This is achieved by processing shorter tasks first.
    sort(tasks.begin(), tasks.end());

    long long currentTime = 0;
    long long maximumReward = 0;

    for (int i = 0; i < n; i++) {

        long long duration = tasks[i].first;
        long long deadline = tasks[i].second;

        currentTime += duration;

        maximumReward += deadline - currentTime;

    }

    cout << maximumReward << '\n';

    return 0;

}