#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Apartments

There are n applicants and m free apartments. Your task is to distribute the
apartments so that as many applicants as possible will get an apartment.

Each applicant has a desired apartment size, and they will accept any apartment
whose size is close enough to the desired size.

Input
The first input line has three integers n, m, and k: the number of applicants,
the number of apartments, and the maximum allowed difference.

The next line contains n integers a_1, a_2, ..., a_n: the desired apartment size
of each applicant. If the desired size of an applicant is x, they will accept
any apartment whose size is between x-k and x+k.

The last line contains m integers b_1, b_2, ..., b_m: the size of each apartment.

Output
Print one integer: the number of applicants who will get an apartment.

Constraints:
1 <= n, m <= 2 * 10^5
0 <= k <= 10^9
1 <= a_i, b_i <= 10^9
*/
int main() {

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> applicants(n);
    vector<long long> apartments(m);

    for (int i = 0; i < n; i++) {

        cin >> applicants[i];

    }

    for (int i = 0; i < m; i++) {

        cin >> apartments[i];

    }

    // Sort both lists so that we can greedily match the smallest
    // remaining applicant with the smallest possible valid apartment.
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int applicantIndex = 0;
    int apartmentIndex = 0;
    int assignedApartments = 0;

    // Use two pointers to scan both sorted lists.
    while (applicantIndex < n && apartmentIndex < m) {

        long long desiredSize = applicants[applicantIndex];
        long long apartmentSize = apartments[apartmentIndex];

        // The apartment is too small for the current applicant,
        // so it cannot be useful for any later applicant either.
        if (apartmentSize < desiredSize - k) {

            apartmentIndex++;

        // The apartment is too large for the current applicant,
        // so we try the next applicant.
        } else if (apartmentSize > desiredSize + k) {

            applicantIndex++;

        // The apartment is acceptable for the current applicant.
        // Assign it and move to the next applicant and apartment.
        } else {

            assignedApartments++;
            applicantIndex++;
            apartmentIndex++;

        }

    }

    cout << assignedApartments << '\n';

    return 0;

}