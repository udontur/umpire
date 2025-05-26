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

          nativeBuildInputs = with pkgs;[
            cmake
            pkg-config 
          ];
          buildInputs = with pkgs;[
            fmt
            boost186
            ftxui
            
            gcc
            python314
            go
            zulu8
            rustc
            bun
          ];

          buildPhase = ''
            cmake ..
            cmake --build .
          '';
          installPhase = ''
            mkdir -p $out/bin
            install -D ./um $out/bin/um
          '';
          # shellHook = ''
          #   export PATH=${pkgs.go}/bin:$PATH
          #   export PATH=${pkgs.gcc}/bin:$PATH
          #   export PATH=${pkgs.rustc}/bin:$PATH
          #   export PATH=${pkgs.python314}/bin:$PATH
          #   export PATH=${pkgs.bunc}/bin:$PATH
          #   export PATH=${pkgs.zulu8}/bin:$PATH
          # '';
        };
    };
}
