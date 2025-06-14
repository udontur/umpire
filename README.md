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


## ⭐ Prerequisites
To avoid large package size, please install the compilers that you use:
```nix
gcc # C++, Installed by default
python3 # Python
go # Golang
zulu # Java
rustc # Rust
```
## 📥 Installation (Linux and MacOS)
### 🍺 homebrew (MacOS)
`umpire` is available in the Homebrew formulae
```sh
brew install umpire
```
### 🔵 Arch Linux (AUR)
`umpire` is available in the Arch User Repository (AUR)
```sh
yay -S umpire
```
### ❄️ Nix (Linux and MacOS)
1. Add the url to your ```flake.nix``` input
```nix
umpire.url = "github:udontur/umpire";
```
2. Add the pacakge in ```environment.systemPackages```
```nix
inputs.umpire.packages."${system}".default
```
3. Rebuild your configuration with Nix flakes enabled.

<!-- # Usage -->

## ⚙️ Development
[See the development docs](docs/development.md)