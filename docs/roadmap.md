### Functionality
- [x] Time parser (um -t)
- [ ] argument parser (a better one please)
- [x] compile program
- [x] path list maker
- [x] Multithread run case
- [x] Case runner
- [ ] TLE (I am doomed, it still does not work. Hour wasted: 5)
- [x] WA and AC comparer
- [x] Detect RTE (empty output?)
- [x] Time limit: accept doubles too (store it in milliseconds afterwards)
- [ ] Program cache handelder
    - [ ] Do it before and after the program (and error exits)
    - [ ] Check if the folder is empty first 
    - [ ] Clear cache function
    - [ ] Dedicated cache storage (programs and outputs ```~/.cache/umpire```)
- [ ] FTXUI output
- [ ] Add argument: user can specify which folder they can use
```
competition
- a-task
-- test case
-- main.cpp
- b-task
-- test case
--main.cpp

judgel b-task
```
- [x] Nix Flake: Add aarch64 and apple (make sure to edit githuv actions)
- [x] Symlink um to umpire (maybe move to cmake)

### Multi-language support (but huge pkg size)
- [x] C++ (Most common)
- [x] Python (Common)
- [x] Java (huge package size)
- [ ] Kotlin (might add or might not add since java is here)
- [x] Rust
- [x] Go
- [x] ~~JavaScript (might delete)~~

### Assisted Tools
- [ ] Template init (um init)
- [ ] testcase folder converter (um -c)
    - [ ] inputABC.txt outputABC.txt
    - [ ] input-ABC.txt output-ABC.txt
    - [ ] ABCin.txt ABCout.txt
    - [ ] ABC-in.txt ABC-out.txt 

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
- [ ] TestCase checker
- [ ] Build checker: GitHub Actions
  - [x] nix flakes / nixpkgs
  - [ ] PKGBUILD (Arch)
  - [ ] homebrew (Apple)

### Package Managment
#### Unstable Release
- nix flakes

#### Very Stable Release (main, with auto updates)
- [ ] AUR 
- [ ] homebrew
- [ ] nixpkgs (upload)

### Future Roadmaps
- [ ] MLE and Memory limit
- [ ] .deb
- [ ] .rpm