<br />
<div align="center">
  <h1 align="center">WORK IN PROGRESS Umpire</h3>
  <p align="center">
    ⚖️ A blazingly fast competitive programming helper 
    <br />
    <br />
    <a href="https://github.com/udontur/judgel/issues/new">Report Bug</a>
    ·
    <a href="https://hadrianlau.com">Made with passion by Hadrian</a>
  </p>
</div>

## ⭐️ About
Writing...
DEMO VIDEO

## 📥 Installation (Linux and MacOS)
Umpire is available for both Linux (Nix and AUR) and MacOS (homebrew and Nix). 
> [!NOTE]
> To avoid large package size, please install the compilers that you use:
> ```nix
> gcc # C++, Installed by default
> python3 # Python
> go # Golang
> zulu # Java
> rustc # Rust
> ```
### ❄️ Nix (Linux and MacOS)
1. Add the url to your ```flake.nix``` input:
```nix
inputs = {
  umpire.url = "github:udontur/umpire";
  # ...
};
```
2. Add the pacakge in ```environment.systemPackages```:
```nix
environment.systemPackages = with pkgs; [
  inputs.umpire.packages."${system}".default
  # ...
];
```
3. Rebuild your configuration with Nix flakes enabled.
### 🍺 homebrew (MacOS)
### 🔵 AUR (Arch Linux)
<!-- ## Usage -->

## ⚙️ Development
[See development docs](docs/development.md)
