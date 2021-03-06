#include <stdio.h>
#include <algorithm>

// A utility function to swap two elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] >= pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        char c;
        int arr[26];
        for (int i = 0; i < 26; i++)
        {
            arr[i] = 0;
        }
        int n = 0;
        while (1)
        {
            c = getchar();
            if (c == EOF || c == '\n')
                break;
            arr[c - 'A']++;
            n++;
        }
        quickSort(arr, 0, 25);
        int min = n;
        for (int k = 1; k <= 26; k++)
        {
            if (n % k)
                continue;
            int perChar = n / k;
            int cost = 0;
            for (int i = 0; i < k; i++)
            {
                if (arr[i] - perChar > 0)
                    cost += arr[i] - perChar;
            }
            for (int i = k; i < 26; i++)
            {
                cost += arr[i];
            }
            min = std::min(min, cost);
        }
        printf("%d\n", min);
    }
}