## 🛠️ Build the package
Umpire is built using CMake and Make.
1. Make the `build/` directory
```sh
mkdir -p build && cd build
```
2. Generate the CMake files
```sh
cmake ..
```
3. Build the program
```sh
cmake --build .
```
4. The resulting binary is located at `./um`, relative to the `build/` directory.

## 📝 Test Script
Test cases are located at `/test`.
```sh
cd test
```
Run the Test Script to check the application against common test cases
```sh
./test.sh
```
> [!IMPORTANT]
> Pay attention to the TLE test case, you will need to manually cancel it using `Ctrl + C`. 

The other test script `test-all.sh` checks the application against all test cases (hopefully):
```
./test-all.sh
```
