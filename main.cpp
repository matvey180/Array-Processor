#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream file; // file reading stream
    file.open("data.txt");  // opening file

    if (!file.is_open()) {  // checking if file opened successfully
        cout << "Error opening file" << endl; // printing error message
        return 1;
    }
    double N; // declaration of variable N

    file >> N;  // reading N value from file

    if (N < 1 || N > 10 || N != round(N)) { // checking N validity
        cout << "Incorrect value of N" << endl; // printing error message
        return 1;
    }

    cout << fixed << setprecision(6);  // setting output precision for fractional numbers


    int n = N - 1; // converting double to int
    const int I = 10; // declaration of variable I - number of elements in arrays
    double VEC[I];  // declaration of VEC array 
    double NEWVEC[I];  // declaration of NEWVEC array
    double sum = 0;  // declaration of variable sum - sum of all positive elements in the initial array
    double sum_n = 0;  // declaration of variable sum_n - sum of first N elements in the new array



    for (int i = 0; i < I; i++) {
        file >> VEC[i];  // reading array values from file
    }


    for (int i = 0; i < I; i++) {  // loop for summing all positive elements 
        if (VEC[i] > 0) {
            sum = sum + VEC[i];
        }
    }

    NEWVEC[0] = VEC[0]; // initializing the first element of the new array
    NEWVEC[n] = sum;  // initializing the exception element 
    cout << "NEWVEC[0] = " << NEWVEC[0] << endl; // printing the first element of the new array

    double k; // variable declaration for filling new array elements
    for (int i = 1; i < I; i++) { // loop for forming the new array
        k = 0; // initializing k
        if (i == n) {
            cout << "NEWVEC[" << i << "] = " << NEWVEC[i] << endl; // printing the exception array element
            continue; // skipping the exception element
        }
        for (int j = 0; j <= i; j++) {
            k += VEC[j]; // accumulating sum of array elements
        }
        NEWVEC[i] = k; // initializing new array elements
        cout << "NEWVEC[" << i << "] = " << NEWVEC[i] << endl; // printing formed array elements
    }


    for (int i = 0; i <= n; i++) { // loop for summing first N elements of the new array
        sum_n = sum_n + NEWVEC[i];
    }
    cout << "Value of the sum: " << sum_n << endl; // printing the sum value

    int count;  // declaration of variable count - index of the minimum element in the new array
    double min_el = NEWVEC[0]; // declaration of variable min_el - minimum element in the array

    for (int i = 1; i < I; i++) { // loop for finding the smallest absolute value element and its index
        if (abs(NEWVEC[i]) <= abs(min_el)) {
            min_el = NEWVEC[i];
            count = i;
        }
    }
    cout << "\n";
    cout << "The smallest element in absolute value: " << min_el << "\n" << "The index of the smallest element: " << count << endl; // printing the smallest absolute value element and its index

    file.close(); // closing the file
    return 0;
}
