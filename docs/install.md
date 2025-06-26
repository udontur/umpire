## All Linux Distributions
You can get Umpire for all Linux distros by manually building Umpire and including it in the PATH variable.

### ❓️ Prerequisites
The following packages must be installed in your system:
```
CMake: Version >= 3.27
GNUMake (Make): Version >= 4.2
GCC: Version >= 8.0 
```
This only works if your distribution follows the FHS (Filesystem Hierarchy Standard).


### 🛠️ Building Umpire
1. Clone the repository
```sh
git clone https://github.com/udontur/umpire && cd umpire
```
2. Create a build directory
```sh
mkdir -p build && cd build
```
3. Generate CMake files
```sh
cmake ..
```
4. Build CMake
```sh
cmake --build .
```
5. After building CMake, exit the build directory
```sh
cd ..
```
The resulting binary is located in `build/um`.

### 🛣️ Adding Umpire to the PATH variable
1. Make sure `/usr/local/bin` exists
```sh
sudo mkdir -p /usr/local/bin
```
2. Move the binary file to `/usr/local/bin`
```sh
sudo cp build/um /usr/local/bin/um
```
3. Symlink `umpire` with `um` (Optional)
```sh
sudo ln -s /usr/local/bin/um /usr/local/bin/umpire
```

### 👍️ Test if it works
1. Open a new terminal and type:
```sh
um
```
Expected output:
```
The directory is "./".
Error: "testcase" folder not found.
```
