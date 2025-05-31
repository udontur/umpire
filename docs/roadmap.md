### Functionality
- [x] Time parser (um -t)
- [ ] argument parser (a better one please)
- [x] compile program
- [x] path list maker
- [x] Multithread run case
- [x] Case runner
- [ ] ~~TLE (I am doomed, it still does not work. Hour wasted: 5)~~ manual cancel
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
- [x] Nix Flake: Add aarch64 and apple (make sure to edit githuv actions)
- [x] Symlink um to umpire (maybe move to cmake)

### Multi-language support (but huge pkg size)
- [x] C++ (Most common)
- [x] Python (Common)
- [x] Java (huge package size)
- [ ] ~~Kotlin (might add or might not add since java is here)~~
- [x] Rust
- [x] Go
- [x] ~~JavaScript (might delete)~~

### Assisted Tools
- [ ] Template init (um init)

### Final Testing
- [ ] Code refactoring (cleaner implementation)
- [ ] Functionality clean up
- [ ] Output clean up
- [ ] Folder structures and formatting
- [ ] Final Testing (please work after refactorring)

### Documentation
- [ ] README
- [ ] help function (the --help or -h)
- [ ] man page (man um, more detail)
### CI
- [ ] TestCase checker (development)
- [ ] Build checker: GitHub Actions
  - [x] nix flakes / nixpkgs
  - [ ] PKGBUILD (Arch)
  - [ ] homebrew (Apple)
  - [ ] flatpak

### Package Managment
#### Unstable Release
- nix flakes

#### Stable Release
- [ ] AUR 
- [ ] homebrew
- [ ] flatpak

### Future Roadmaps
- [ ] MLE and Memory limit
- [ ] nixpkgs (upload)
- [ ] Better TLE mechanism