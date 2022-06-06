for i in `seq 1 500`;
do
    ./stddev < data_10000.txt
     mv gmon.out gmon.out.$i
done

gprof -s stddev gmon.out.*

gprof stddev gmon.sum > gprof-result-huge.txt
rm -f gmon.out.* gmon.sum