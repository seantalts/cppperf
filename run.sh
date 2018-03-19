for i in *.cpp; do
    test=${i%.cpp}
    echo $test
    rm $test
    make -j4 $test
    ./${test} --benchmark_out=${test}_results.txt --benchmark_out_format=console
done
