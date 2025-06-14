<br />
<div align="center">
  <h1 align="center">WORK IN PROGRESS Umpire</h3>
  <p align="center">
    ⚖️ A Fully-Featured Offline Competitive Programming CLI Judge 
    <br />
    <br />
    <a href="https://github.com/udontur/judgel/issues/new">Report Bug</a>
    ·
    <a href="https://hadrianlau.com">Made with passion by Hadrian</a>
  </p>
</div>

# About
Writing...
DEMO VIDEO

# 📥 Installation (Linux and MacOS)
## ⭐ Prerequisites
To avoid large package size, please install the compilers that you use:
```nix
gcc # C++
python3 # Python
go # Golang
zulu # Java
rustc # Rust
```

## 🔵 Arch Linux (AUR)
## 🍺 MacOS (homebrew)
## ❄️ Nix (Linux and MacOS)
1. Add the url to your ```flake.nix``` input
```nix
umpire.url = "github:udontur/umpire";
```
2. Add the pacakge in ```environment.systemPackages```
```nix
inputs.umpire.packages."${system}".default
```
3. Rebuild your configuration with nix flakes enabled.
## 🐧 Other Linux (flatpak)

# Usage

# ⚙️ Development
## 🛠️ Build the package
1. Enter the nix shell
```sh
nix develop
```
2. Build the package using Nix
```sh
nix build
```
3. Run the built binary
```sh
nix run # Also builds the package
```
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

