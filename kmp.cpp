#include <bits/stdc++.h>
#include <string>
#include <cstring>
#define MAX_N 10000010 
#define BUFFER_SIZE 10000
using namespace std;
typedef long long ll;

char T[MAX_N], P[MAX_N];
char buffer[BUFFER_SIZE];
int n, m;
int b[MAX_N];

void kmpPreprocess() {                           // call this before calling kmpSearch()
    int i = 0, j = -1;                           // starting values
    b[0] = -1;
    while (i < m) {                              // preprocess the pattern string P
        while (j >= 0 && P[i] != P[j]) j = b[j]; // different, reset j using b
        i++; j++;
        b[i] = j;                                // observe i = 8, 9, 10, 11, 12, 13 
                                                 // with j = 0, 1, 2, 3, 4, 5
                                                 // in the example of P = "SEVENTY SEVEN"
    }
}
void kmpSearch() {                              // this is similar as kmpPreprocess(), but on string T
    int i = 0, j = 0;                           // starting values
    while (i < n) {                             // seatch through string T
        while (j >= 0 && T[i] != P[j]) j = b[j];  // different, reset j using b
        i++; j++;
        if (j == m) {
            printf("P is found at index %d in T\n", i - j);
            j = b[j];                           // prepare j for the next possible match
        }
    }
}

int32_t main() {
    string p = "algorithm";
    strcpy(P, p.c_str());
    
    while (cin.getline(buffer, BUFFER_SIZE)) {
        strcat(T, buffer);
    }

    n = strlen(T);
    m = strlen(P);

    kmpPreprocess();
    kmpSearch();
}
