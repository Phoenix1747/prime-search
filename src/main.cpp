/*
 * Very simple algorithm to search for prime numbers by
 * dividing a candidate by all smaller prime numbers.
 *
 * Written by Phoenix1747, 2018-11-24.
 */

#include <vector>
#include <iostream>
#include <fstream>

int main()
{
	unsigned int n = 1; //index var
	std::vector<unsigned int> primes = {2}; //array that will hold all the prime numbers
	bool isPrime = true; //prime indicator bool

	std::ofstream file;
	file.open("primes.txt"); //save all primes to this file

	while(true)
	{
		n++;

		for(unsigned int i = 0; i < primes.size(); i++) //check if n can be divided remainder-free with any smaller prime
		{
			if(n % primes.at(i) == 0)
			{
				isPrime = false;
				break;
			}
		}

		if(isPrime) //if number n is found to be a prime do this
		{
			primes.push_back(n);
			file << n << ",";
			//std::cout << n << "\n";
			std::cout << "Primes found: " << primes.size() << "\n";
		}

		isPrime = true;
	}
	file.close();
	return 0;
}
