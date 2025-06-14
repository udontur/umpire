git add .
# nix develop
nix build

# "go" "java" "javascript" "python" "rust"

array=("ac" "ca" "case" "nom" "rte" "tle" "wa" "go" "java" "python" "rust")
for name in "${array[@]}"
do
    echo -e "\033[93m!!!$name test STARTED!!!\e[0m"
    sudo cp -p ../bazel-bin/src/main $name/um
    cd $name
    ./um
    cd -
    sudo rm -f $name/um
    sudo rm -f $name/main
    echo -e "\033[93m!!!$name test ENDED!!!\n\e[0m"
done