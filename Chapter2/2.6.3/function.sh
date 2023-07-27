#!/bin/sh

# foo() {
#     echo "Function foo is executing"
# }

# echo "script starting"
# foo
# echo "script ended"

# exit 0

# sample_text="global variable"

# foo() {
#     local sample_text="local variable"
#     echo "Function foo is executing"
#     echo $sample_text
# }

# echo "script staring"
# echo $sample_text

# foo

# echo "script ended"
# echo $sample_text

# exit 0

yes_or_no()
{
    echo "Is your name $* ?"
    while true
    do
        echo -n "Enter yes or no:"
        read x
        case "$x" in
            y | yes ) return 0;;
            n | no )  return 1;;
            * )       echo "Answer yes or no"
        esac
    done
}

echo "Original parameters are $*"

if yes_or_no "$1"
then
    echo "Hi $1, nice name"
else
    echo "Never mind"
fi

exit 0
