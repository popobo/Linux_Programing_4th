#!/bin/sh

trap 'rm -f /tmp/my_temp_file_$$' INT
echo creating file /tmp/my_temp_file_$$
date > /tmp/my_temp_file_$$

echo "press interrupt (CTRL-C) to interrupt ...."
while [ -f /tmp/my_temp_file_$$ ]; do
    echo File exists
    sleep 1
done
echo The file no longer exists

trap INT
echo creating file /tmp/my_temp_file_$$
date > /tmp/my_temp_file_$$

echo "press interrupt (CTRL-C) to interrupt ...."
while [ -f /tmp/my_temp_file_$$ ]; do
    echo File exists
    sleep 1
done

echo we never get here
exit 0
