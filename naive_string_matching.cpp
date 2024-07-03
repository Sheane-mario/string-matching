#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#define unsigned char char
using namespace std;
typedef long long ll;

char T[100000000];
char P[100000000];

void naiveMatching() {
    int n = strlen(T), m = strlen(P);
    for (int i = 0; i < n; i++) { // try all potential starting indices
        bool found = true;
        for (int j = 0; j < m && found; j++) {
            if (i + j >= n || P[j] != T[i + j]) // if mismatch found
                found = false;     // abort this, shift the starting index i by +1
        }
        if (found)  // if P[0..m-1] == T[i..i+m-1]
            cout << "P is found at index " << i << " in T\n";

    }
}

int32_t main() {
    char buffer[10000];
    while (cin.getline(buffer, 10000)) {
           strcat(T, buffer); 
    }
//    string t = T;
    string p = "P";
    strcpy(P, p.c_str());
//    cout << t;
    naiveMatching();    
}
