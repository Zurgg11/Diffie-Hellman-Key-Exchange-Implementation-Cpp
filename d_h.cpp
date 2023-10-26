//
//  main.cpp
//
//  Created by Shreya Wagley 
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <set>
using namespace std;

// Function to calculate (base^exponent) % modulo using Square and Multiply Algorithm
long long squareAndMultiply(long long base, long long exponent, long long modulo) {
    long long result = 1;
    base = base % modulo;

    // Square and Multiply Algorithm
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            // If the current bit of the exponent is 1, multiply the result by the base
            result = (result * base) % modulo;
        }
        // Square the base and halve the exponent
        base = (base * base) % modulo;
        exponent = exponent / 2;
    }

    return result;
}

// Function to check if a number is prime
bool isPrime(long long n) {
    if (n <= 1) {
        return false;
    }
    // Check for factors up to the square root of 'n' to determine primality
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

// Function to generate a random prime number within a specified range
long long generateRandomPrime(long long min, long long max) {
    while (true) {
        // Generate a random candidate number within the specified range
        long long candidate = rand() % (max - min + 1) + min;
        if (candidate % 2 == 0) {
            // Ensure that the candidate is odd to increase the chances of it being prime
            candidate++;
        }
        // Check if the candidate is prime by calling the isPrime function
        if (isPrime(candidate)) {
            return candidate;
        }
    }
}

// Function to check if 'g' is a primitive root modulo 'p'
bool isPrimitiveRoot(long long g, long long p) {
    // Ensure g is greater than 1 and less than p
    if (g <= 1 || g >= p) {
        return false;
    }

    // Create a set to store all possible values of g^x % p
    set<long long> values;

    long long result = 1;
    for (long long x = 1; x < p - 1; x++) {
        result = (result * g) % p;

        // Check if the result has already been seen; if so, 'g' is not a primitive root
        if (values.find(result) != values.end()) {
            return false; // g is not a primitive root
        }
        values.insert(result);
    }

    return true; // g is a primitive root
}



int main() {
    srand(time(NULL));

    int choice;
    cout << "Diffie-Hellman Key Exchange" << endl;
    cout << "--------------------------" << endl;

    // Menu
    cout << "Choose an option:" << endl;
    cout << "1. Enter values manually" << endl;
    cout << "2. Generate random values" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    long long p, g, xA, xB;

    // Check if the user chose manual input
    if (choice == 1) {
    // Get prime modulus from user
        do {
            cout << "Enter p (Prime Modulus): ";
            cin >> p;
            //check if p is a prime number
            if (!isPrime(p)) {
                cout << "Error: p must be a prime number." << endl;
            }
        } while (!isPrime(p));

        // Get primitive root from user
        do {
            cout << "Enter g (Primitive Root): ";
            cin >> g;
            //check in enterd g is valid
            if (!isPrimitiveRoot(g, p)) {
                cout << "Error: g must be a primitive root of p." << endl;
            }
        } while (!isPrimitiveRoot(g, p));

        // Get private key for party A from user
        cout << "Enter xA (Private Key for A): ";
        cin >> xA;

        // Get private key for party B from user
        cout << "Enter xB (Private Key for B): ";
        cin >> xB;
        
  } else if (choice == 2) {
      // Generate random values for p, g, xA, and xB

      p = generateRandomPrime(1, 100);
      do {
          g = rand() % (p - 2) + 2; // Random primitive root
      } while (!isPrimitiveRoot(g, p)); // Ensure g is a primitive root of p
      
      xA = rand() % (p - 2) + 1; // Random private key for party A
      xB = rand() % (p - 2) + 1; // Random private key for party B
  } else {
      cout << "Invalid choice. Exiting..." << endl;
      return 1;
  }

    // Calculate public keys
    long long yA = squareAndMultiply(g, xA, p);
    long long yB = squareAndMultiply(g, xB, p);

    //display entered values
    cout << "--------------------------" << endl;
    cout << "p (Prime Modulus): " << p << endl;
    cout << "g (Primitive Root): " << g << endl;
    cout << "xA (Private Key for A): " << xA << endl;
    cout << "xB (Private Key for B): " << xB << endl;
    cout << "yA (Public Key for A): " << yA << endl;
    cout << "yB (Public Key for B): " << yB << endl;

    // Calculate the shared secret using public keys and private keys
    long long sharedSecretA = squareAndMultiply(yB, xA, p);
    long long sharedSecretB = squareAndMultiply(yA, xB, p);
    //display results
    cout << "Shared Secret for A: " << sharedSecretA << endl;
    cout << "Shared Secret for B: " << sharedSecretB << endl;
    cout << "Therefore, k : " << sharedSecretB << endl;

    return 0;
}
