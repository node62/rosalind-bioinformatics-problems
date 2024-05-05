#ifndef FASTA_H
#define FASTA_H

#include <string>

class fasta {
public:
    int count = 0;
    std::string** rosa;

    fasta(const std::string& s) {
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '>') count++;
        }

        rosa = new std::string*[count];
        for (int i = 0; i < count; ++i) {
            rosa[i] = new std::string[2];
            rosa[i][0] = "";
            rosa[i][1] = "";
        }

        int a = -1, b = 0;
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '>') {
                a++; b = 0;
                continue;
            }
            else if (s[i] == '\n' && b == 0) {
                b = 1;
                continue;
            }
            else if (s[i] == '\n') continue;

            rosa[a][b] += s[i];
        }
    }

    ~fasta() {
        for (int i = 0; i < count; ++i) {
            delete[] rosa[i];
        }
        delete[] rosa;
    }
};

#endif // FASTA_H
