/*
 * Classic Sieve of Eratosthenes algorithm to search primes.
 *
 * Written by Phoenix1747, 2020-11-10.
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    unsigned long long int n;

    cout << " :: Upper limit for search: ";
    cin >> n;

    if(!cin){
        cout << "Number must be a postive integer!" << endl;
        return 1;
    }
    
    vector<unsigned long long int> found;
    vector<bool> prim(n,true);

    for(size_t num = 2; num <= n; num++){ //main algorithm
        if(!prim[num]) continue;
        
        found.push_back(num);

        for(size_t i = 1; i*num <= n; i++) prim[i*num] = false;
    }

    cout << "\nPrimes found: ";

    for(auto &prime:found) cout << prime << ",";

    cout << "\n\nSearch ended successfully. Found [" << found.size() << "] prime numbers!" << endl;
    return 0;
}

