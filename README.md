RSA Encryption and Decryption Program
Overview
This project implements RSA encryption and decryption using C++. It allows users to generate RSA keys, encrypt plaintext messages, and decrypt cyphertext. The program includes both the encryption and decryption processes, as well as logging the steps into a log.txt file for reference.

Files in the Repository
rsa_ak.cbp: The Code::Blocks project file.
rsa_ak.depend: The dependency file for the project.
log.txt: The output log file containing details of the RSA encryption process such as the generated keys and message transformations.
How the Program Works
Key Generation:

The user is prompted to input two prime numbers, p and q.
The program calculates n as the product of p and q, and phi as (p-1)*(q-1).
A public exponent e is chosen such that 1 < e < phi and e is coprime with phi.
The private key d is calculated using the formula d = (phi * k + 1) / e where k is incremented until a valid d is found.
Encryption:

Converts each character in the plaintext to its ASCII representation.
Encrypts each character using the formula encrypted = (char^e) % n.
The result is stored as the cyphertext in both ASCII and character formats.
Decryption:

Decrypts each character using the formula decrypted = (cypher^d) % n.
Converts the decrypted ASCII values back into characters to retrieve the original message.
Logging:

All key details (public and private keys) and transformations are logged into log.txt for easy reference and debugging.
Usage
Compile and run the C++ code in a compatible environment (e.g., Code::Blocks).
Follow the prompts to input prime numbers and generate the RSA keys.
Input a message for encryption.
The program will display the encrypted and decrypted message.
Check log.txt for detailed logs of the process.
Example
The following is an example of the program's output in log.txt:

css
Copy code
[Rsa: log]
    P = 13  Q = 11
    N = P*Q = 143  Phi = (P-1) (Q-1) = 120
    E = 7
    K = 6  D = (Phi*K+1)/E = 103
    La cle publique (e,n) = (7,143)
    La cle prive (d,n) = (103,143)

    PlainText: Khadrani
    PlainText(ASCII): 75 104 97 100 114 97 110 105
    CypherText(ASCII): r [ ; d 1 ; ! v
    CypherText: r[;d1;!v
Prerequisites
A C++ compiler (e.g., Code::Blocks, GCC).
A Windows environment for proper execution of system commands like system("Color 40").
Notes
Ensure that p and q are large prime numbers for stronger encryption.
The generated keys should not be used for production-level applications as this implementation is for educational purposes.
License
This project is licensed under the MIT License.
