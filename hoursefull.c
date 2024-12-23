#include <stdio.h>
#include <string.h>
#define ALPHABET_SIZE 256  
void createBadCharTable(char* pattern, int* badCharTable, int m) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        badCharTable[i] = m; 
    }
    for (int i = 0; i < m - 1; i++) {
        badCharTable[(int)pattern[i]] = m - i - 1;
    }
}
int horspoolSearch(char* text, char* pattern) {
    int n = strlen(text);      
    int m = strlen(pattern);  
    int badCharTable[ALPHABET_SIZE];
    createBadCharTable(pattern, badCharTable, m);
    int i = m - 1;  
    while (i < n) {
        int j = m - 1; 
        while (j >= 0 && text[i - (m - 1 - j)] == pattern[j]) {
            j--;
        }
        if (j < 0) {
            return i - (m - 1);  
        }
        i += badCharTable[(int)text[i]];
    }
    return -1;  
}
int main() {
    char text[100], pattern[100];
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; 
    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; 
    int result = horspoolSearch(text, pattern);
    if (result != -1) {
        printf("Pattern found at index %d\n", result);
    } else {
        printf("Pattern not found in the text\n");
    }
    return 0;
}
