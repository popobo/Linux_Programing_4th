#!/bin/sh

echo  -n "Is it morning? Please answer yes or no? "
read timeofday

# case "$timeofday" in
#     yes) echo "Good morning";;
#     no ) echo "Good afternoon";;
#     y  ) echo "Good morning";;
#     n  ) echo "Good afternoon";;
#     *  ) echo "Sorry answer not recognized";;
# esac

# case "$timeofday" in
#     yes | y | Yes | YES ) echo "Good morning";;
#     n* | N* ) echo "Good afternoon";;
#     *  ) echo "Sorry answer not recognized";;
# esac

case "$timeofday" in
    yes | y | Yes | YES )
        echo "Good morning"
        echo "Up bright and early this morning"
        ;;
    [nN]* )
        echo "Good afternoon"
        ;;
    *  )
        echo "Sorry answer not recognized"
        echo "Please answer yse or no"
        exit 1
        ;;
esac

exit 0
