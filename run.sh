echo "# Results\n" > README.md
for i in *.cpp; do
    test=${i%.cpp}
    echo $test
    rm $test
    make -j4 $test
    ./$test >> README.md 2>&1
done
