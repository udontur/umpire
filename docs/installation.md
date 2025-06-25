https://github.com/polygon/nix-buildproxy
nix develop
nix run github:polygon/nix-buildproxy#buildproxy-capture
cd build
cmake ..
cd ..
exit (exit the shell)

cat proxy_content.nix
