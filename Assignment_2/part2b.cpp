// #include <iostream>
// using namespace std;

// int main()
// {
//     int max = 100; // set maximum value for a, b, and c
//     for (int a = 1; a <= max; a++)
//     {
//         for (int b = a; b <= max; b++)
//         {
//             for (int c = b; c <= max; c++)
//             {
//                 if (a*a + b*b - a*b == c*c)
//                 {
//                     cout << a << ", " << b << ", " << c << endl;
//                 }
//             }
//         }
//     }
//     return 0;
// }


#include <iostream>
#include <omp.h> // include OpenMP header file
using namespace std;

int main()
{
    int max = 100; // set maximum value for a, b, and c
    #pragma omp parallel for collapse(3) // parallelize the nested loops
    for (int a = 1; a <= max; a++)
    {
        for (int b = a; b <= max; b++)
        {
            for (int c = b; c <= max; c++)
            {
                if (a*a + b*b + a*b == c*c)
                {
                    #pragma omp critical // ensure that only one thread prints at a time
                    {
                        cout << a << ", " << b << ", " << c << endl;
                    }
                }
            }
        }
    }
    return 0;
}