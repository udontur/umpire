{
  description = "An Offline Competitive Programming C++ Judge";
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
            pkgs.boost186
            pkgs.ftxui
          ];

          buildPhase = ''
            cmake ..
            cmake --build .
          '';
          installPhase = ''
            mkdir -p $out/bin
            install -D ./um $out/bin/um
          '';

        };
    };
}
