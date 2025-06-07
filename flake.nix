{
  description = "github:udontur/umpire Nix flake";
  inputs.nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  outputs = { self, nixpkgs }:
    let
      supportedSystems = [
        "x86_64-linux"
        "aarch64-linux"
        "x86_64-darwin"
        "aarch64-darwin"
      ];
      forAllSystems = nixpkgs.lib.genAttrs supportedSystems;
    in{
      packages = forAllSystems(system:
        let 
          pkgs = nixpkgs.legacyPackages.${system};
        in{
          default =
            pkgs.stdenv.mkDerivation {
              # Meta Data
              pname = "umpire";
              version = "nightly";
              
              src = self;

              nativeBuildInputs = with pkgs;[
                # Build tools
                cmake
                git
                vcpkg
                pkg-config
              ];
              
              # buildInputs = with pkgs;[
              #   # Libraries
              #   fmt
              #   boost186
              #   ftxui
              # ];

              # Build
              buildPhase = ''
                cmake ..
                cmake --build .
              '';

              #Install
              installPhase = ''
                runHook preInstall

                mkdir -p $out/bin
                install -Dm755 ./um $out/bin/um
                ln -s $out/bin/um $out/bin/umpire

                runHook postInstall
              '';
            };
        }
      );
    };
}

    
