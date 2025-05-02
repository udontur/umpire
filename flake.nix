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
            mkdir build
            cd build
            cmake ..
            cmake --build .
          '';
          installPhase = ''
            mkdir -p $out/bin
            install -D ./build/um $out/bin/um
          '';
        };
    };
}

# termcolor
# fmt
 