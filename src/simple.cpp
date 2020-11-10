/*
 * Very simple algorithm to search for prime numbers by
 * dividing a candidate by all primes smaller than
 * the square root of the candidate itself.
 *
 * Written by Phoenix1747, 2018-11-25. Edit: 2020-11-10.
 */

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(vector<unsigned long long int> &primev, unsigned long long int &n)
{
    unsigned long long int root = sqrt(n); //check factors up to the size of the sqrt of the number
    
    for(auto &val:primev){
        if(val > root) break;
        if(n % val == 0) return false;
    }

	return true;
}

int main(){
	unsigned long long int n = 3; //index var
	unsigned long long int upperLimit = 2; //check all numbers smaller than this

    cout << " :: Upper limit for search: ";
    cin >> upperLimit;

    if(!cin){
        cout << "Number must be a postive integer!" << endl;
        return 1;
    }

	vector<unsigned long long int> primes(1,2); //vector that will hold all the prime numbers

	while(n <= upperLimit)
	{
		if(isPrime(primes, n)) primes.push_back(n);//if number n is found to be a prime add it to the vector
        n += 2; //increment candidate number by 2 to only check odd numbers
	}
    
    cout << "\nPrimes found: ";

    for(auto &prime:primes) cout << prime << ",";

	cout << "\n\nSearch ended successfully. Found [" << primes.size() << "] prime numbers!" << endl;
	return 0;
}
