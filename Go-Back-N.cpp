//4.Write a program to simulate Go-Back-N and Selective Repeat ARQ protocols using C/C++.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void goBackN(int totalFrames, int windowSize) {
    cout << "\n--- Go-Back-N ARQ ---\n";
    srand(time(0));
    int i = 1;
    while (i <= totalFrames) {
        int j;
        for (j = i; j < i + windowSize && j <= totalFrames; j++)
            cout << "Sending Frame " << j << endl;

        int lost = rand() % windowSize + i;  // randomly lose a frame
        if (lost <= totalFrames && rand() % 2 == 0) {
            cout << "Frame " << lost << " lost! Retransmitting from Frame " << lost << endl;
            i = lost;
        } else {
            cout << "All frames from " << i << " to " << j - 1 << " acknowledged.\n";
            i = j;
        }
    }
}

void selectiveRepeat(int totalFrames, int windowSize) {
    cout << "\n--- Selective Repeat ARQ ---\n";
    srand(time(0));
    int ack[50] = {0};
    int i = 1;

    while (i <= totalFrames) {
        for (int j = i; j < i + windowSize && j <= totalFrames; j++)
            if (ack[j] == 0)
                cout << "Sending Frame " << j << endl;

        for (int j = i; j < i + windowSize && j <= totalFrames; j++) {
            if (rand() % 2 == 0) {
                cout << "Frame " << j << " received. ACK sent.\n";
                ack[j] = 1;
            } else {
                cout << "Frame " << j << " lost!\n";
                ack[j] = 0;
            }
        }

        for (int j = i; j < i + windowSize && j <= totalFrames; j++)
            if (ack[j] == 0) {
                cout << "Resending Frame " << j << endl;
                cout << "Frame " << j << " received. ACK sent.\n";
                ack[j] = 1;
            }

        i += windowSize;
    }
}

int main() {
    int totalFrames, windowSize, choice;

    cout << "Enter total number of frames: ";
    cin >> totalFrames;
    cout << "Enter window size: ";
    cin >> windowSize;

    cout << "\n1. Go-Back-N ARQ\n2. Selective Repeat ARQ\nEnter choice: ";
    cin >> choice;

    if (choice == 1)
        goBackN(totalFrames, windowSize);
    else if (choice == 2)
        selectiveRepeat(totalFrames, windowSize);
    else
        cout << "Invalid choice!" << endl;

    return 0;
}
