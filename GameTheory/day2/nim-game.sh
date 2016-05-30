function solve {
    local t
    local n
    local arr
    read t
    for x in `seq 1 $t`; do
        local res=0
        read n
        read arr
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
