git add .
nix build

# "go" "java" "javascript" "python" "rust"

array=("ac" "ca" "case" "nom" "rte" "tle" "wa")
for name in "${array[@]}"
do
    echo -e "\033[93m!!!$name test STARTED!!!\e[0m"
    ./result/bin/um $name    
    echo -e "\033[93m!!!$name test ENDED!!!\n\e[0m"
done
