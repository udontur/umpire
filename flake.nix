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
        pkgs = import nixpkgs {inherit system; };
      in{
        default =
          pkgs.stdenv.mkDerivation rec {
            # Meta Data
            pname = "umpire";
            version = "1.0";
            
            src = self;

            # Packages used by the builder
            nativeBuildInputs = with pkgs;[
              cmake
              gnumake
            ];

            buildInputs = with pkgs;[
              ftxui
              fmt
              boost
            ];

            cmakeFlags = [ "-DCMAKE_BUILD_TYPE=Release" ];
            
            # Install
            installPhase = ''
              runHook preInstall
              
              mkdir -p $out/bin
              install -Dm755 ./umpire $out/bin/umpire
              ln -s $out/bin/umpire $out/bin/um

              runHook postInstall
            '';
          };
        }
      );
    };
}
