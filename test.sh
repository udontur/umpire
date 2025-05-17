git add .
nix build

# echo -e "\033[93mAC test STARTED \e[0m"
# cp -p result/bin/um test/ac/um
# cd test/ac
# ./um
# cd -
# rm -f test/ac/um
# echo -e "\033[93mAC test ENDED\n\e[0m"

# echo -e "\033[93mCA test STARTED \e[0m"
# cp -p result/bin/um test/ca/um
# cd test/ca
# ./um
# cd -
# rm -f test/ca/um
# echo -e "\033[93mCA test ENDED\n\e[0m"

# echo -e "\033[93mCASE test STARTED \e[0m"
# cp -p result/bin/um test/case/um
# cd test/case
# ./um
# cd -
# rm -f test/case/um
# echo -e "\033[93mCASE test ENDED\n\e[0m"

# echo -e "\033[93mNOM test STARTED \e[0m"
# cp -p result/bin/um test/nom/um
# cd test/nom
# ./um
# cd -
# rm -f test/nom/um
# echo -e "\033[93mNOM test ENDED\n\e[0m"

# echo -e "\033[93mRTE test STARTED \e[0m"
# cp -p result/bin/um test/rte/um
# cd test/rte
# ./um
# cd -
# rm -f test/rte/um
# echo -e "\033[93mRTE test ENDED\n\e[0m"

echo -e "\033[93mTLE test STARTED \e[0m"
cp -p result/bin/um test/tle/um
cd test/tle
./um
cd -
rm -f test/tle/um
echo -e "\033[93mTLE test ENDED\n\e[0m"

# echo -e "\033[93mWA test STARTED \e[0m"
# cp -p result/bin/um test/wa/um
# cd test/wa
# ./um
# cd -
# rm -f test/wa/um
# echo -e "\033[93mWA test ENDED\n\e[0m"
