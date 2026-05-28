//3.Write a program to perform subnetting for a given IP address and number of subnets using C/C++.
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    string ipClass;
    int subnetCount;

    cout << "Enter IP class (A / B / C): ";
    cin >> ipClass;

    cout << "Enter number of subnets required: ";
    cin >> subnetCount;

    int bits = 0;
    while (pow(2, bits) < subnetCount)
        bits++;

    int defaultMaskBits;
    if (ipClass == "A" || ipClass == "a")
        defaultMaskBits = 8;
    else if (ipClass == "B" || ipClass == "b")
        defaultMaskBits = 16;
    else if (ipClass == "C" || ipClass == "c")
        defaultMaskBits = 24;
    else {
        cout << "Invalid IP class entered." << endl;
        return 0;
    }

    int newMaskBits = defaultMaskBits + bits;
    int hostBits = 32 - newMaskBits;
    int totalHosts = pow(2, hostBits) - 2;

    unsigned int mask = 0xFFFFFFFF << (32 - newMaskBits);

    cout << "\n--- Subnetting Details ---" << endl;
    cout << "IP Class: " << (char)toupper(ipClass[0]) << endl;
    cout << "Number of subnets: " << pow(2, bits) << endl;
    cout << "Number of bits borrowed: " << bits << endl;
    cout << "New Subnet Mask (/" << newMaskBits << "): ";

    // Display subnet mask in dotted decimal format
    for (int i = 3; i >= 0; i--) {
        cout << ((mask >> (i * 8)) & 255);
        if (i != 0) cout << ".";
    }

    cout << "\nNumber of hosts per subnet: " << totalHosts << endl;

    return 0;
}
