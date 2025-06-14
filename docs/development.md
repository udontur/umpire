## 🛠️ Build the package
`umpire` is built using Bazel
```sh
bazel build //src:main --enable_bzlmod --copt=-std=c++17
```
The resulting binary is located at `bazel-bin/src/main`

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

