#include <iostream>
#include <cstring>
#include <cctype>
#include <ctime>

void encryptVigenere(char *input, const char *key) {
    int keyLength = strlen(key);
    for (int i = 0; i < strlen(input); ++i) {
        if (isalpha(input[i])) {
            char base = isupper(input[i]) ? 'A' : 'a';
            char keyChar = key[i % keyLength];
            char keyBase = isupper(keyChar) ? 'A' : 'a';
            input[i] = (input[i] - base + keyChar - keyBase) % 26 + base;
        }
    }
}

int main() {
    const char *key = "KEY";
    char input[] = "Hello, World!";

    std::cout << "Original string: " << input << std::endl;

    clock_t start_time = clock(); //start time

    encryptVigenere(input, key);

    clock_t end_time = clock(); //end time

    double elapsed_time = double(end_time - start_time) * 1000.0 / CLOCKS_PER_SEC; // Convert to milliseconds
    std::cout << "Encrypted string: " << input << std::endl;
    std::cout << "Time elapsed: " << elapsed_time << " milliseconds" << std::endl;

    return 0;
}