# prime-search

This repo currently consists of two different methods to search for primes; both can be found in the `src` folder.

The upper limit for searching is selected by the user in both cases. 

### sieve.cpp:

Very simple algorithm to search for prime numbers by dividing a candidate by all primes smaller than the square root of the candidate itself.

### simple.cpp:

Classic sieve of Eratosthenes algorithm that essentially eliminates multiples of a prime number bigger than the candidate itself while stepping through every non-eliminated number.

