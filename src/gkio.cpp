#include "gkio.h"

string int_to_string (int p_x)
{
    ostringstream temp;
    temp<<p_x;
    return temp.str();
}

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

string array_to_string(int* p_array, int p_len)
{
    string ret = "";
    for (int i=0; i<p_len; i++) {
        ret += int_to_string(p_array[i]) + "|";
    }
    return ret;
}

void up_quicksort(int valor[], int esquerda, int direita)
{
    int i, j, x, y;
    i = esquerda;
    j = direita;
    x = valor[(esquerda + direita) / 2];

    while(i <= j)
    {
        while(valor[i] < x && i < direita)
        {
            i++;
        }
        while(valor[j] > x && j > esquerda)
        {
            j--;
        }
        if(i <= j)
        {
            y = valor[i];
            valor[i] = valor[j];
            valor[j] = y;
            i++;
            j--;
        }
    }
    if(j > esquerda)
    {
        up_quicksort(valor, esquerda, j);
    }
    if(i < direita)
    {
        up_quicksort(valor,  i, direita);
    }
}


void down_quicksort(int valor[], int esquerda, int direita)
{
    int i, j, x, y;
    i = esquerda;
    j = direita;
    x = valor[(esquerda + direita) / 2];

    while(i <= j)
    {
        while(valor[i] > x && i < direita)
        {
            i++;
        }
        while(valor[j] < x && j > esquerda)
        {
            j--;
        }
        if(i <= j)
        {
            y = valor[i];
            valor[i] = valor[j];
            valor[j] = y;
            i++;
            j--;
        }
    }
    if(j > esquerda)
    {
        down_quicksort(valor, esquerda, j);
    }
    if(i < direita)
    {
        down_quicksort(valor,  i, direita);
    }
}
