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
- [ ] Final verdict
- [ ] Add argument: user can specify which folder they can use
- [ ] argument parser [(a better one please)](https://github.com/p-ranav/argparse)
```
competition
- a-task
-- test case
-- main.cpp
- b-task
-- test case
--main.cpp

um b-task -t 3.5
um -t 3.5 b-task
um --help
```
- [x] Nix Flake: Add aarch64 and apple (make sure to edit github actions)
- [x] Symlink um to umpire 
- [ ] Help function
- [ ] All output clean up

### Multi-language support (but huge pkg size)
- [x] C++ (Most common)
- [x] Python (Common)
- [x] Java (huge package size)
- [x] Rust
- [x] Go

### Build
- [ ] CMake, fetch deps from system
- [x] CMake + Nix
- [ ] CMake + homebrew (MacOS Apple)
- [ ] CMake + PKGBUILD (Arch Linux AUR)

### Final Testing
- [ ] Code refactoring (cleaner implementation)
- [ ] Functionality clean up
- [ ] Folder structures and formatting
- [ ] Final Testing (please work after refactorring)

### Documentation (README)
- [ ] readme: Clean and nice readme
- [ ] readme: Package badge, version badge, and build badge
- [ ] readme: Concise installation guide
- [ ] docs: Write a installation guide for all linux systems + detail ones for the ones we support
- [ ] readme: Clean, easy to understand usage guide
- [ ] docs: Write a detailed usage guide in the docs
- [ ] readme: A demo of how it works
- [ ] readme: What is it and why it helps you
- [ ] docs: Good development docs

### CI
- [x] TestCase checker (development)
- [ ] Build checker: GitHub Actions
  - [ ] CMake that fetch deps from system
  - [x] nix flakes
  - [ ] PKGBUILD (Arch)
  - [ ] homebrew (Apple)

### Package Managment
#### Unstable Release
- nix flakes

#### Stable Release
- [ ] AUR (PKGBUILD Arch Linux) 
- [ ] homebrew (MacOS)

### Future Roadmaps
- [ ] MLE and Memory limit
- [ ] nixpkgs (upload)
- [ ] Better TLE mechanism
