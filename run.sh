echo "# Results" > README.md
for i in *.cpp; do
    test=${i%.cpp}
    echo $test
    rm $test
    make -j4 $test
    ./$test --benchmark_out=results.txt --benchmark_out_format=console
    cat results.txt >> README.md
done
rm results.txt
