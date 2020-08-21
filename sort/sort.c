#include "sort.h"

bool binary_search(int *v, int n, int x)
{
    int first = 0;
    int last = n - 1;

    int middle = (first + last) / 2;

    while (first <= last)
    {
        if (v[middle] < x)
        {
            first = middle + 1;
        }
        else
        {
            if (v[middle] > x)
            {
                last = middle - 1;
            }
            else
            {
                return true;
            }
        }

        middle = (first + last) / 2;
    }

    return false;
}

void bubble_sort(int *v, int n)
{
    while (n > 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i] > v[+1])
            {
                int aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
            }
        }
        n--;
    }
}

void selection_sort(int *v, int n)
{
    int min;

    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int aux = v[i];
            v[i] = v[min];
            v[min] = aux;
        }
    }
}

void insertion_sort(int *v, int n)
{
    int j;
    for (int i = 1; i < n; i++)
    {
        j = i;
        while (j > 0 && v[j - 1] > v[j])
        {
            int aux = v[j];
            v[j] = v[j - 1];
            v[j - 1] = aux;
            j--;
        }
    }
}