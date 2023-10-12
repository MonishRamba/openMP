#include <iostream>
#include <cstring>
#include <cctype>
#include <omp.h>

void encryptVigenere(char *input, const char *key) {
    int keyLength = strlen(key);
    #pragma omp parallel for
    for (int i = 0; i < strlen(input); ++i) {
        int threadID = omp_get_thread_num();
        //std::cout << "Thread " << threadID << " is processing character at index " << i << std::endl;
        
        if (isalpha(input[i])) {
            char base = isupper(input[i]) ? 'A' : 'a';
            char keyChar = key[i % keyLength];
            char keyBase = isupper(keyChar) ? 'A' : 'a';
            input[i] = (input[i] - base + keyChar - keyBase) % 26 + base;
        }
    }
}

int main() {
    double start_time = omp_get_wtime(); // Get the start time

    int numThreads;
    std::cout << "Enter the number of threads: ";
    //std::cin >> numThreads;

    omp_set_num_threads(4);

    const char *key = "KEY";
    char input[] = "Hello, World!";
    
    std::cout << "Original string: " << input << std::endl;
    
    encryptVigenere(input, key);
    
    std::cout << "Encrypted string: " << input << std::endl;
    
    double end_time = omp_get_wtime(); // Get the end time
    std::cout << "Time elapsed: " << end_time - start_time << " seconds" << std::endl;

    return 0;
}