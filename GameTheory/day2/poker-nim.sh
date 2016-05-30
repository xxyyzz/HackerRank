function solve {
    read t
    for tc in `seq 1 $t`; do
        read arr
        read arr
        res=0
        for x in $arr; do
            res=$(( res ^ x ))
        done
        if [ $res -eq 0 ]; then
            echo "Second"
        else
            echo "First"
        fi
    done
}

solve
