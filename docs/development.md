## 🛠️ Build the package
`umpire` is built using Cmake and Make.

1. Make the `build` directory
```sh
mkdir -p build
cd build
```
2. Make the CMake files
```sh
cmake ..
```
3. Build using CMake and Make
```sh
cmake --build .
```
The resulting binary is located at `./um`.

## 📝 Test Script
Test cases are located at `/test`.
```sh
cd test
```
Run the Test Script to check the application against the test cases
```sh
./test.sh
```
> [!NOTE]
> Pay attention to the TLE test case, you will need to manually cancel it using `Ctrl + C`. 

