function solve {
    read t
    for tc in `seq 1 $t`; do
        read n
        read arr
        i=0
        res=0
        for x in $arr; do
            b=$(( x % 2 ))
            if [ $b -eq 1 ]; then
                res=$(( res ^ i ))
            fi
            i=$(( i + 1 ))
        done
        if [ $res -eq 0 ]; then
            echo "Second"
        else
            echo "First"
        fi
    done
}

solve
