/*
 * Very simple algorithm to search for prime numbers by
 * dividing a candidate by all smaller prime numbers.
 *
 * Written by Phoenix1747, 2018-11-24.
 */

#include <vector>
#include <iostream>
#include <fstream>

bool isPrime(std::vector<unsigned int>& p, unsigned int n)
{
	for(unsigned int i = 0; i < p.size(); i++) //check if n can be divided remainder-free with any smaller prime
	{
		if(n % p.at(i) == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	unsigned int n = 1; //index var
	std::vector<unsigned int> primes = {2}; //array that will hold all the prime numbers

	std::ofstream file;
	file.open("primes.txt"); //save all primes to this file

	while(true)
	{
		n++; //increment candidate number

		if(isPrime(primes, n)) //if number n is found to be a prime do this
		{
			primes.push_back(n); //add number n to prime number vector
			file << n << ","; //write number n to file
			//std::cout << n << "\n";
			std::cout << "Primes found: " << primes.size() << "\n"; //print out the number of found primes
		}
	}
	file.close();
	return 0;
}
