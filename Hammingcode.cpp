//2.Write a program for error detection and correction for 7/8 bits ASCII codes using Hamming Codes using C/C++.
#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate parity bits
int calculateParity(int arr[], int r) {
    int n = r + 8; // 8 data bits
    int parity = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1)
            parity ^= (i + 1);
    }
    return parity;
}

// Function to encode 8-bit data using Hamming Code
void hammingEncode(int data[8], int encoded[12]) {
    int j = 0, k = 0;
    for (int i = 1; i <= 12; i++) {
        if ((i & (i - 1)) == 0) { // position is power of 2
            encoded[i - 1] = 0;   // parity bit placeholder
        } else {
            encoded[i - 1] = data[j++];
        }
    }

    // calculate parity bits
    for (int i = 0; i < 4; i++) {
        int pos = pow(2, i);
        int parity = 0;
        for (int j = pos; j <= 12; j++) {
            if ((j & pos) && encoded[j - 1] == 1) {
                parity ^= 1;
            }
        }
        encoded[pos - 1] = parity;
    }
}

// Function to detect and correct error
int hammingDecode(int encoded[12]) {
    int errorPos = 0;
    for (int i = 0; i < 4; i++) {
        int pos = pow(2, i);
        int parity = 0;
        for (int j = pos; j <= 12; j++) {
            if ((j & pos) && encoded[j - 1] == 1) {
                parity ^= 1;
            }
        }
        if (parity != 0) {
            errorPos += pos;
        }
    }
    if (errorPos != 0) {
        cout << "Error detected at position: " << errorPos << endl;
        encoded[errorPos - 1] ^= 1; // correct error
        cout << "Error corrected!" << endl;
    } else {
        cout << "No error detected." << endl;
    }

    int data[8];
    int j = 0;
    for (int i = 1; i <= 12; i++) {
        if ((i & (i - 1)) != 0) {
            data[j++] = encoded[i - 1];
        }
    }

    int ascii = 0;
    for (int i = 0; i < 8; i++) {
        ascii = (ascii << 1) | data[i];
    }
    return ascii;
}

int main() {
    char ch;
    cout << "Enter a character: ";
    cin >> ch;

    int data[8];
    for (int i = 0; i < 8; i++) {
        data[7 - i] = (ch >> i) & 1;
    }

    int encoded[12];
    hammingEncode(data, encoded);

    cout << "Encoded Hamming code: ";
    for (int i = 0; i < 12; i++) {
        cout << encoded[i];
    }
    cout << endl;

    cout << "Enter received Hamming code (12 bits, space separated): ";
    for (int i = 0; i < 12; i++) {
        cin >> encoded[i];
    }

    int correctedChar = hammingDecode(encoded);
    cout << "Corrected character: " << (char)correctedChar << endl;

    return 0;
}
