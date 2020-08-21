void insertionsort(int *v, int n)
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