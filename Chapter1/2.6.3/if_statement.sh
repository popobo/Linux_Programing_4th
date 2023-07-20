#!/bin/sh

echo -n "Is is moring? Please answer yes or no " # -n 去掉换行符
read timeofday

# elif [ $timeofday = "yes" ]; then 输入回车变成[ = "yes" ]不合法
if [ "$timeofday" = "yes" ]; then
    echo "Good morning"
elif [ "$timeofday" = "no" ]; then
    echo "Good afternoon"
else
    echo "Sorry $timeofday not recognized. Enter yes or no"
    exit 1
fi

exit 0
