{
  description = "github:udontur/umpire Nix flake";
  inputs.nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  
  outputs = { self, nixpkgs, ... }:
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
        };
        fmt_src = builtins.fetchTarball{
          url = "https://github.com/fmtlib/fmt/archive/refs/tags/11.2.0.tar.gz";
          sha256 = "sha256:0x8j1k1cnmvv5hbhhyfm7bqw2d2rb3jpmz6bc4a195z8pzj582dh";
        };

        ftxui_src = builtins.fetchTarball{
          url = "https://github.com/ArthurSonzogni/FTXUI/archive/refs/tags/v6.1.9.tar.gz";
          sha256 = "sha256:1sbgp1b5v0z8dcfwmgincd759brc1bz64vifdfp4r1afp1672lm6";
        };

        argparse_src = builtins.fetchTarball{
          url = "https://github.com/p-ranav/argparse/archive/refs/tags/v3.2.tar.gz";
          sha256 = "sha256:04wp0q5sxn4hlqzsbq1g99q4k8wn0y1y2ldwld7g3k7yibqi90n3";
        };
                  
      in{
        default =
          pkgs.stdenv.mkDerivation rec {
            pname = "umpire";
            version = "0.2";
            src = self;

            # Packages used by the builder
            nativeBuildInputs = with pkgs;[
              cmake
              gnumake
              gcc
              git
            ];

            configurePhase = ''
              export fmt_src=${fmt_src}
              export ftxui_src=${ftxui_src}
              export argparse_src=${argparse_src}
            '';
            
            cmakeFlags = [
              "-DCMAKE_BUILD_TYPE=Release"
              "-Dfmt_src=${fmt_src}"
              "-Dftxui_src=${ftxui_src}"
              "-Dargparse_src=${argparse_src}"
            ];

            buildPhase = ''
              mkdir -p build
              cd build
              cmake ..
              cmake --build .
            '';
              
            
            installPhase = ''
              runHook preInstall
              
              mkdir -p $out/bin
              install -Dm755 ./um $out/bin/um
              ln -s $out/bin/um $out/bin/umpire

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
