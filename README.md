# Vigenère Cipher CLI Utility

A modular C++ implementation of the classical polyalphabetic Vigenère cipher for encrypting and decrypting arbitrary text using modular arithmetic and character casing preservation.

## Overview

The Vigenère cipher is a method of encrypting alphabetic text by using a series of interwoven Caesar ciphers based on the letters of a keyword. This utility maps ASCII characters to zero-indexed alphabet coordinates ($0 \to 25$), aligns the keystream over variable-length input text, and applies algebraic transformations for both encryption and decryption.

## Mathematical Formulation

The core cryptographic transformations are defined as follows:

* **Encryption:**  
  $$C_i = (P_i + K_i) \pmod{26}$$

* **Decryption:**  
  $$P_i = (C_i - K_i + 26) \pmod{26}$$

Where:
* $P_i$ is the integer index of the plaintext letter ($A = 0, B = 1, \dots, Z = 25$).
* $K_i$ is the integer index of the corresponding key letter.
* $C_i$ is the resulting ciphertext letter index.
* The $+26$ offset in decryption ensures non-negative intermediate values before the modulo reduction in C++.

## Key Technical Concepts Demonstrated

* **Memory Efficiency via Pass-by-Reference:** Passes input text strings by constant reference (`const string&`) to eliminate unnecessary memory copying and dynamic reallocations in RAM.
* **Modular Arithmetic & Cyclical Mapping:** Utilizes the modulo operator (`%`) to construct repeating keystreams and wrap alphabet boundaries.
* **ASCII Normalization:** Calculates alphabetic shifts relative to baseline ASCII offsets (`'A'` = 65, `'a'` = 97) while preserving whitespace and punctuation.
* **Defensive Console Input Handling:** Validates numeric menu inputs using `cin` stream checks and clears newline artifacts with `cin.ignore()`.
* **Standard Modern Iteration:** Implements range-based loops (`for (char c : text)`) for readable sequence traversal.

## Prerequisites

* A C++ compiler supporting C++11 or higher (such as `g++` or `clang++`).

## Compilation and Execution

1. Clone the repository:
   ```bash
   git clone [https://github.com/YourUsername/vigenere-cipher-cpp.git](https://github.com/YourUsername/vigenere-cipher-cpp.git)
   cd vigenere-cipher-cpp
