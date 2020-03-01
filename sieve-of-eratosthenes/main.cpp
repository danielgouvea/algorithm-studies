#include <iostream>
#include <set>
#include <vector>

using std::cout;
using std::set;
using std::vector;

set<unsigned> sieveOfEratosthenes(unsigned limit) {
    set<unsigned> primes;

    if (limit < 2) {
        return primes;
    }

    vector<bool> isPrime(limit, true);
    primes.insert(2);

    for (unsigned value = 2; value <= limit; value++) {
        if (!isPrime[value - 1]) {
            continue;
        }

        primes.insert(value);

        unsigned multiple = value + value;
        while (multiple <= limit) {
            isPrime[multiple - 1] = false;
            multiple += value;
        }
    }

    return primes;
}

set<unsigned> modifiedSieveOfEratosthenes(unsigned limit) {
    set<unsigned> primes;

    if (limit < 2) {
        return primes;
    }

    primes.insert(2);

    for (unsigned value = 3; value <= limit; value++) {
        bool isPrime = true;

        for (unsigned prime : primes) {
            if (value % prime == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            primes.insert(value);
        }
    }

    return primes;
}

void print(const set<unsigned> &primes) {
    for (unsigned prime : primes) {
        cout << prime << ' ';
    }
    cout << '\n';
}

int main() {
    print(sieveOfEratosthenes(120));
    print(modifiedSieveOfEratosthenes(120));

    return 0;
}
