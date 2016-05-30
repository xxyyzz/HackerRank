function solve {
    read t
    for tc in `seq 1 $t`; do
        read n
        all_ones=1
        read arr
        res=0
        for x in $arr; do
            if [ $x -ne 1 ]; then
                all_ones=0
            fi
            res=$(( res ^ x ))
        done
        if [ $all_ones -eq 1 ]; then
            b=$(( n % 2 ))
            if [ $b -eq 1 ]; then
                echo "Second"
            else
                echo "First"
            fi
        else
            if [ $res -eq 0 ]; then
                echo "Second"
            else
                echo "First"
            fi
        fi
    done
}

solve
