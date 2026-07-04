#include <iostream>
#include <set>

using namespace std;

/*
Concert Tickets

There are n concert tickets available, each with a certain price. Then, m
customers arrive, one after another.

Each customer announces the maximum price they are willing to pay for a ticket,
and after this, they will get a ticket with the nearest possible price such that
it does not exceed the maximum price.

Input
The first input line contains integers n and m: the number of tickets and the
number of customers.

The next line contains n integers h_1, h_2, ..., h_n: the price of each ticket.

The last line contains m integers t_1, t_2, ..., t_m: the maximum price for each
customer in the order they arrive.

Output
Print, for each customer, the price that they will pay for their ticket. After
this, the ticket cannot be purchased again.

If a customer cannot get any ticket, print -1.

Constraints:
1 <= n, m <= 2 * 10^5
1 <= h_i, t_i <= 10^9
*/
int main() {

    int n, m;
    cin >> n >> m;

    multiset<int> tickets;

    for (int i = 0; i < n; i++) {

        int price;
        cin >> price;
        tickets.insert(price);

    }

    for (int i = 0; i < m; i++) {

        int maximumPrice;
        cin >> maximumPrice;

        // Find the first ticket with price greater than the customer's limit.
        auto ticket = tickets.upper_bound(maximumPrice);

        // If this iterator points to the beginning, then all available tickets
        // are too expensive for this customer.
        if (ticket == tickets.begin()) {

            cout << -1 << '\n';

        } else {

            // Move one step back to get the most expensive ticket that does
            // not exceed the customer's maximum price.
            ticket--;

            cout << *ticket << '\n';

            // Remove the sold ticket so it cannot be used again.
            tickets.erase(ticket);

        }

    }

    return 0;

}