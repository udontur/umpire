git add .
cd ..
mkdir -p build
cd build
cmake ..
cmake --build .
cd ..
cd test

array=("ac" "ca" "case" "nom" "rte" "tle" "wa" "go" "java" "python" "rust")
for name in "${array[@]}"
do
    echo -e "\033[93m!!!$name test STARTED!!!\e[0m"
    ../build/um $name    
    echo -e "\033[93m!!!$name test ENDED!!!\n\e[0m"
done

echo -e "\033[93m!!!arg test STARTED!!!\e[0m"
../build/um -t 0.5 ac
echo -e "\033[93m!!!arg test ENDED!!!\n\e[0m"

echo -e "\033[93m!!!arg_error test STARTED!!!\e[0m"
../build/um -wrong
echo -e "\033[93m!!!arg_error test ENDED!!!\n\e[0m"

echo -e "\033[93m!!!arg_extra test STARTED!!!\e[0m"
../build/um ac -t 1.5 alskdjkasd alksdjalsdkdj lakjdaskljdl alkjdlkasjdklasj
echo -e "\033[93m!!!arg_extra test ENDED!!!\n\e[0m"

echo -e "\033[93m!!!arg_none test STARTED!!!\e[0m"
cd ac &> /dev/null
../../build/um
cd .. &> /dev/null
echo -e "\033[93m!!!arg_non test ENDED!!!\n\e[0m"
