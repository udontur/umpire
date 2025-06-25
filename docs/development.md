## 🛠️ Build the package
`umpire` is built using Nix, CMake, and Make.
1. Enter the Nix development shell
```sh
nix develop
```
2. Build the program from the source
```sh
nix build
```
3. Run the program with arguments
```sh
nix run . -- <PUT YOUR ARGS HERE>
```
> [!NOTE]
> The resulting binary is located at `./result/bin/um`, relative to the root directory.

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
./installation.md.sh
```
