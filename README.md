# ⚖️ Umpire

Umpire is a hassle free multithreaded TUI helper for competitive programming that eliminates all the hassle for compiling your code, testing your code, and matching test cases.

![Demo Video](asset/demo.gif)

## Installation
Umpire is available for both Linux and MacOS.
> [!NOTE]
> To avoid large package size, please install the compilers that you use:
> ```sh
> gcc # C++
> python3 # Python
> go # Golang
> zulu # Java
> rustc # Rust
> ```
### Nix (Linux or MacOS)
Umpire is available via [Nix flakes](https://wiki.nixos.org/wiki/Flakes).
```
inputs.umpire.packages."${system}".default
```
### All Linux distros 
Please install [CMake](https://cmake.org/) and [Make](https://www.gnu.org/software/make/), then run the following command in your terminal:
```sh
git clone https://github.com/udontur/umpire && cd umpire && sudo make install
```

## Usage
See all details in the [documentations](./docs/run.md).

### Prerequisite
Organize your code directory as follows:
```sh
task-a/ # The folder that stores everything
└─ main.cpp # File name must be "main"
└─ testcase # Exact name
  ├─ ABC.in
  ├─ ABC.out 
```

### Running Umpire
Run `umpire` in the **current** directory:
```sh
um
```
Or specify a directory:
```
um task-a
```
### Options

The [documentation](./docs/run.md) provides a list of options, including test case outputs and custom time limits.
