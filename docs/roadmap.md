### Functionality
- [x] Time parser (um -t)
- [x] compile program
- [x] path list maker
- [x] Multithread run case
- [x] Case runner
- [x] ~~TLE (I am doomed, it still does not work. Hour wasted: 5)~~ manual cancel
- [x] WA and AC comparer
- [x] Detect RTE (empty output?)
- [x] Time limit: accept doubles too (store it in milliseconds afterwards)
- [x] Program cache handelder
    - [x] Do it before and after the program (and error exits)
    - [x] Check if the folder is empty first 
    - [x] Clear cache function
- [x] FTXUI output
- [x] FTXUI table color
- [x] Final verdict
- [x] Add argument: user can specify which folder they can use
- [x] argument parser [(a better one please)](https://github.com/p-ranav/argparse)
- [x] Nix Flake: Add aarch64 and apple (make sure to edit github actions)
- [x] Symlink um to umpire 
- [x] Help function

### Multi-language support (but huge pkg size)
- [x] C++ (Most common)
- [x] Python (Common)
- [x] Java (huge package size)
- [x] Rust
- [x] Go

### Build
- [x] CMake
- [x] CMake + Nix
- [x] CMake + PKGBUILD (Arch Linux AUR)
- [x] Make a static binary (cmake and stuff)

### Final Testing
- [x] Code refactoring (cleaner implementation)
- [x] Functionality clean up
- [x] Folder structures and formatting
- [x] Final Testing (please work after refactorring)

### Documentation (README)
- [x] readme: Clean and nice readme
- [x] readme: Package badge, version badge, and build badge
- [ ] readme: Concise installation guide (and one for the other linux distro)
- [x] readme: Clean, easy to understand usage guide
- [x] readme: What is it and why it helps you
- [x] docs: Good development docs
- [x] readme: a very eye catching demo
- [x] change dev guide

### CI
- [x] TestCase checker (development)
- [x] Build checker: GitHub Actions
  - [x] CMake
  - [x] nix flakes
  - [x] PKGBUILD (Arch)

### Package Managment
#### Unstable Release
- nix flakes

#### Stable Release
- [x] AUR (PKGBUILD Arch Linux) 

### Future Roadmaps
- [ ] MLE and Memory limit
- [ ] nixpkgs (upload)
- [ ] Better TLE mechanism
- [ ] A test case inputter
