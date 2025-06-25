{
  description = "github:udontur/umpire Nix flake";
  inputs.nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  inputs.nix-buildproxy.url = "github:polygon/nix-buildproxy";
  
  outputs = { self, nixpkgs, nix-buildproxy, ... }:
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
        pkgs = import nixpkgs {
          inherit system;
          overlays = [ nix-buildproxy.overlays.default ];
        };
        buildproxy = pkgs.lib.mkBuildproxy ./proxy_content.nix;
      in{
        default =
          pkgs.stdenv.mkDerivation rec {
            pname = "umpire";
            version = "0.1";
            src = self;

            # Packages used by the builder
            nativeBuildInputs = with pkgs;[
              cmake
              gnumake
              gcc
              buildproxy
              curl
            ];

            prePatch = ''
              source ${buildproxy}
            '';
            
            cmakeFlags = [ "-DCMAKE_BUILD_TYPE=Release" ];
            
            installPhase = ''
              runHook preInstall
              
              mkdir -p $out/bin
              install -Dm755 ./umpire $out/bin/umpire
              ln -s $out/bin/umpire $out/bin/um

              runHook postInstall
            '';

            
            meta = {
              homepage = "https://github.com/udontur/umpire";
              description = "A blazingly fast competitive programming helper";
              mainProgram = "umpire";
              license = pkgs.lib.licenses.mit;
              platforms = pkgs.lib.platforms.all;
            };
          };
        }
      );
    };
}
