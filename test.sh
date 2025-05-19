git add .
# nix develop
nix build

# "go" "java" "javascript" "python" "rust"

array=("ac" "ca" "case" "nom" "rte" "tle" "wa" )
for name in "${array[@]}"
do
    echo -e "\033[93m$name test STARTED \e[0m"
    cp -p result/bin/um test/$name/um
    cd test/$name
    ./um
    cd -
    rm -f test/$name/um
    rm -f test/$name/main
    echo -e "\033[93m$name test ENDED\n\e[0m"
done