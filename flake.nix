{
  description = "Simple local C++ competitive programming judge";
  inputs.nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  outputs =
    { self, nixpkgs }:
    {
      packages.x86_64-linux.default =
        with import nixpkgs {
          system = "x86_64-linux";
        };
        stdenv.mkDerivation {
          name = "judgel";
          src = self;
          buildPhase = ''
            g++ -std=c++20 ./src/main.cpp -o judgel
          '';
          installPhase = ''
            mkdir -p $out/bin
            install -D ./judgel $out/bin/judgel
          '';
        };
    };
}
 