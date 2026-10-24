<br />
<div align="center">
  <h1 align="center">Judgel</h3>
  <p align="center">
    ⚖️ Simple local C++ competitive programming judge
    <br />
    <br />
    <a href="https://github.com/udontur/judgel/issues/new">Report Bug</a>
    ·
    <a href="https://hadrianlau.com">Made with passion by Hadrian</a>
  </p>
</div>

## ⭐ About
```judgel``` is a simple local C++ competitive programming judge. It is straightforward to set up and use. 

- Available verdicts:
  1. Accepted
  2. Wrong Answer
  3. Time Limit Exceeded
  4. Runtime Error
  5. Compilation Error


## 🛠️ Installation (Linux)
1. Add the Nix flake to your ```flake.nix``` input:
```nix
judgel.url="github:udontur/judgel";
```
2. Add the package to your NixOS ```configuration.nix```:
```nix
inputs.judgel.packages."${system}".default
```
3. Rebuild your Nix configuration.

## ⚙️ Prerequisites
1. Testcase folder name: ```testcase```
	- Each testcase file format: ```ABC.in``` and ```ABC.out```
2. Code file name: ```main.cpp```

## 🔧 Usage

Run the following command in your **code directory**:
```sh
judgel <TIME LIMIT>
```
> [!IMPORTANT]
> The time limit must be an **integer**.

> [!TIP]
> 1. Leave the time limit blank for a 1 second time limit.
> 2. ```cd /path/to/dir``` to navigate to your code directory

## 💾 Demo
Try it out first:
```sh
$ nix shell github:udontur/judgel -c judgel
```
![](assets/demo.gif)
