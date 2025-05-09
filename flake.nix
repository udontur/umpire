{
  description = "A Local C++ competitive programming judge";
  inputs.nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  outputs =
    { self, nixpkgs }:
    let 
      system = "x86_64-linux";
      pkgs = nixpkgs.legacyPackages.${system};
    in{
      packages.x86_64-linux.default =
        with import nixpkgs {
          system = "x86_64-linux";
        };
        stdenv.mkDerivation {
          name = "umpire";
          src = self;

          nativeBuildInputs = [
            pkgs.cmake
            pkgs.pkg-config 
          ];
          buildInputs = [
            pkgs.fmt
            pkgs.gcc
            pkgs.boost
          ];
          buildPhase = ''
            cmake ..
            echo "CMAKE DONE"
            cmake --build .
            cat Makefile
          '';
          installPhase = ''
            mkdir -p $out/bin
            pwd
            ls
            install -D ./um $out/bin/um
          '';

        };
    };
}

            # g++ -std=c++20 ./src/main.cpp -o um