#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int max = 100; // set maximum value for a, b, and c
    for (int a = 1; a <= max; a++)
    {
        for (int b = a; b <= max; b++)
        {
            for (int c = b; c <= max; c++)
            {
                if (a*a + b*b == c*c)
                {
                    cout << a << ", " << b << ", " << c << endl;
                }
            }
        }
    }
    return 0;
}




// #include <iostream>
// #include <cmath>
// #include <omp.h>

// using namespace std;

// int main() {
//     int num_threads = omp_get_max_threads();
//     int count = 0;

//     // Set the number of threads
//     omp_set_num_threads(num_threads);

//     // Loop through all possible values of a, b, and c
//     #pragma omp parallel for collapse(3) reduction(+:count)
//     for (int a = 1; a <= 100; a++) {
//         for (int b = 1; b <= 100; b++) {
//             for (int c = 1; c <= 100; c++) {
//                 // Check if a^2 + b^2 = c^2
//                 if (pow(a, 2) + pow(b, 2) == pow(c, 2)) {
//                     // Print the Pythagorean triple
//                     cout << a << "^2 + " << b << "^2 = " << c << "^2" << endl;
//                     count++;
//                 }
//             }
//         }
//     }

//     // Print the total number of Pythagorean triples found
//     cout << "Total Pythagorean triples found: " << count << endl;

//     return 0;
// }
