# OpenMP Matrix Multiplication
A simple project demonstrating parallel matrix multiplication using OpenMP, with an automated build and testing workflow via a Bash script. It highlights parallel programming concepts, performance benchmarking, and CI/CD basics in high-performance computing.

## Features
- **Parallel Computation:** Uses OpenMP to parallelize matrix multiplication.
- **Automation Script:** Automates compilation, testing, and result logging with a Bash script (`build.sh`).
- **Performance Metrics:** Measures and logs execution time for different matrix sizes.

## How to Run

1. **Install Dependencies:**
   Ensure `g++-14` and OpenMP are installed. On macOS:
   ```bash
   brew install libomp
