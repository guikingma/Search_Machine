#ifndef GKIO_H
#define GKIO_H

#define print(S) cout << S;
#define println(S) cout << S << endl;

#include <iostream>
#include <sstream>

using namespace std;

// --- String operations --- //
string int_to_string (int p_x);

// --- Array operations --- //
string array_to_string(int* p_array, int p_len);
/* This function swaps two numbers
Arguments : a, b - the numbers to be swapped */
void swap(int &a, int &b);
void up_quicksort(int valor[], int esquerda, int direita);
void down_quicksort(int valor[], int esquerda, int direita);




#endif // GKIO_H
