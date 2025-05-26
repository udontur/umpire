git add .
# nix develop
nix build

# "go" "java" "javascript" "python" "rust"

array=("ac" "ca" "case" "nom" "rte" "tle" "wa" )
for name in "${array[@]}"
do
    echo -e "\033[93m$name test STARTED \e[0m"
    sudo cp -p result/bin/um test/$name/um
    cd test/$name
    ./um
    cd -
    sudo rm -f test/$name/um
    sudo rm -f test/$name/main
    echo -e "\033[93m$name test ENDED\n\e[0m"
done