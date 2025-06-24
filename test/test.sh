git add .
nix build

# "go" "java" "javascript" "python" "rust"

array=("ac" "ca" "case" "nom" "rte" "tle" "wa")
for name in "${array[@]}"
do
    echo -e "\033[93m!!!$name test STARTED!!!\e[0m"
    sudo cp -p ./result/bin/um $name/um &> /dev/null
    cd $name &> /dev/null
    ./um
    cd - &> /dev/null
    sudo rm -f $name/um
    sudo rm -f $name/main
    echo -e "\033[93m!!!$name test ENDED!!!\n\e[0m"
done
