Diffie-Hellman Key Exchange
 
Description
The Diffie-Hellman Key Exchange is a public-key cryptographic protocol that allows two parties to exchange a shared secret key securely over an insecure communication channel. This C++ program demonstrates the Diffie-Hellman key exchange algorithm using manual input or generating random values for `p`, `g`, `xA`, and `xB`.

Usage
1. Compile the program using a C++ compiler such as `g++`:

   g++ main.cpp -o diffie-hellman

2. Run the program:

   ./diffie-hellman

3. Follow the on-screen prompts to either enter values manually or generate random values.

Options
Manual Input: Allows you to manually enter values for `p`, `g`, `xA`, and `xB`. Ensure that `p` is a prime number, `g` is a primitive root of `p`, and `xA` and `xB` are private keys for parties A and B.

Generate Random Values**: Generates random values for `p`, `g`, `xA`, and `xB` following the Diffie-Hellman key exchange algorithm. The program ensures that `p` is a prime number, `g` is a primitive root of `p`, and `xA` and `xB` are private keys for parties A and B.

Input
For manual input, you need to provide `p`, `g`, `xA`, and `xB` values as per the program's prompts.

For generating random values, no user input is required.

Output
The program will display the generated public keys `yA` and `yB` for parties A and B, respectively.

It will calculate and display the shared secret key for parties A and B, as well as the common key `k`.

Important Notes
The program uses the Square and Multiply Algorithm to perform modular exponentiation.

It checks for the primality of `p` and whether `g` is a primitive root of `p`.

Random values generated for `p`, `g`, `xA`, and `xB` are within specific ranges to ensure algorithm validity.

Authors

Shreya Wagley

License
This program is provided under an open-source license. You are free to use and modify it as needed.

