/*
 * Very simple algorithm to search for prime numbers by
 * dividing a candidate by all primes smaller than
 * the square root of the candidate itself.
 *
 * Written by Phoenix1747, 2018-11-25.
 */

#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

bool isPrime(std::vector<unsigned int>& p, unsigned int n)
{
	float root = std::sqrt(n); //check factors up to the size of the sqrt of the number

	for(unsigned int i = 0; i < p.size(); i++) //check if n can be divided remainder-free with any smaller prime
	{
		unsigned int j = p.at(i); //lookup testing prime factor once

		if(j > root)
		{
			break;
		}
		if(n % j == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	unsigned int n = 1; //index var
	unsigned int upperLimit = 1000000000; //check all numbers smaller than this
	std::vector<unsigned int> primes = {2}; //array that will hold all the prime numbers

	std::ofstream file;
	file.open("primes.csv"); //save all primes to this file

	while(n < upperLimit)
	{
		n += 2; //increment candidate number by 2 to only check odd numbers

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
