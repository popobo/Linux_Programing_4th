#!/bin/sh
 
# for foo in bar fud 43
for file in $(ls f*.sh)
do
    echo $file
done
exit 0
