mkdir -p build
cd build
cmake ..
cmake --build .
cd ..

# "go" "java" "javascript" "python" "rust"

array=("ac" "ca" "case" "nom" "rte" "tle" "wa")
for name in "${array[@]}"
do
    echo -e "\033[93m!!!$name test STARTED!!!\e[0m"
    sudo cp -p ./build/um $name/um
    cd $name
    ./um
    cd -
    sudo rm -f $name/um
    sudo rm -f $name/main
    echo -e "\033[93m!!!$name test ENDED!!!\n\e[0m"
done
