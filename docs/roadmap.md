### Functionality
- [x] Time parser (um -t)
- [ ] argument parser [(a better one please)](https://github.com/p-ranav/argparse)
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
- [ ] FTXUI table color
- [ ] Final verdict
- [ ] All output clean up
- [ ] Add argument: user can specify which folder they can use
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

### Multi-language support (but huge pkg size)
- [x] C++ (Most common)
- [x] Python (Common)
- [x] Java (huge package size)
- [ ] ~~Kotlin (might add or might not add since java is here)~~
- [x] Rust
- [x] Go
- [x] ~~JavaScript (might delete)~~

### Build
- [x] Full CMake and Make build
- [ ] CMake + Nix (Nix is sandbox so Cmake can't FetchContent)
- [ ] CMake + homebrew (MacOS Apple)
- [ ] CMake + PKGBUILD (Arch Linux AUR)

### Final Testing
- [ ] Code refactoring (cleaner implementation)
- [ ] Functionality clean up
- [ ] Folder structures and formatting
- [ ] Final Testing (please work after refactorring)

### Documentation
- [ ] README (with badges + demo + clearn usage and installtion guide)
- [ ] help function (the --help or -h)

### CI
- [ ] TestCase checker (development)
- [ ] Build checker: GitHub Actions
  - [ ] CMake
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
