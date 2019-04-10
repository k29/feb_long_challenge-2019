#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        char str[1000000];
        long long count[26] = {0};
        long long final_unique;
        long long final_count;
        long long sum = 0;

        long long sol = LLONG_MAX;
        long long unique = 0;
        scanf("%s", str);

        for (long long i = 0; str[i] != '\0'; i++)
        {
            count[str[i] - 'A']++;
        }

        for (long long i = 0; i < 26; i++)
        {
            if (count[i] != 0)
            {
                unique++;
                sum += count[i];
            }
        }
        if (unique == 0)
        {
            return 0;
        }
        else
        {
            final_unique = 26;
        }

        while (final_unique > 0)
        {
            if (sum % final_unique == 0)
            {
                long long output = 0;
                final_count = sum / final_unique;

                long long arr_final_count[26] = {0};
                for (int i = 0; i < final_unique; i++)
                {
                    arr_final_count[i] = final_count;
                }
                sort(count, count + 26, greater<int>());
                long long counter = 0;
                if (final_unique > unique)
                    counter = final_unique;
                else
                    counter = unique;
                for (long long i = 0; i < counter; i++)
                {
                    output += abs(count[i] - arr_final_count[i]);
                }
                output /= 2;
                if (output < sol)
                {
                    sol = output;
                }
            }
            final_unique--;
        }
        cout << sol << endl;
    }

    return 0;
}