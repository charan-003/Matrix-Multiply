#include <iostream>
#include <vector>
#include <ctime>
#include <omp.h> // Include OpenMP header

using namespace std;

double calculateTime(clock_t start, clock_t end) {
    return static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

int main() {
    int n;
    cout << "Enter matrix size: ";
    cin >> n;

    // Initialize matrices A, B, and C
    vector<vector<int>> A(n, vector<int>(n, 1));
    vector<vector<int>> B(n, vector<int>(n, 2));
    vector<vector<int>> C(n, vector<int>(n, 0));

    // Measure start time
    clock_t start = clock();

    // Perform matrix multiplication
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int temp = 0; // Use a temporary variable to avoid race conditions
            for (int k = 0; k < n; ++k) {
                temp += A[i][k] * B[k][j];
            }
            C[i][j] = temp; // Write result after computation
        }
    }

    // Measure end time
    clock_t end = clock();

    // Print elapsed time using the function
    cout << "Matrix multiplication completed in " << calculateTime(start, end) << " seconds.\n";

    return 0;
}
