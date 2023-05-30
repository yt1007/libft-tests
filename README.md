# libft-tests
A set of unit tests for libft functions

## Installation
Clone the repository to your computer. Then, edit the `LIBFT_DIR` variable in the `Makefile` to point to the directory containing your libft project files.

## Running the Tests
In the repository, type:
1. `make` to run tests on mandatory functions.
2. `make bonus` to run tests on bonus functions.
3. `make all` to run tests on all functions.
4. `make ft_isalpha` to run tests only on the specified function.

## Notes
1. This test does not explicitly test for the presence of `Makefile` and `libft.h` files in your libft submission. Some tests may, however, fail if your submission folder does not contain these files.
2. This test also does not check for norm errors.
3. It is recommended to run the tests with a `-i` flag to ignore errors and proceed with other tests if you want an overview of which tests will fail.
4. Certain tests depends on other libraries in your libft submissions.
5. Tests are run with `-fsanitise=address`, hence, if your function fails with memory errors, do comment/uncomment tests in `main.c` to find out which test case is causing the error.
6. Mandatory functions are tested against the C library function they are mirroring.
