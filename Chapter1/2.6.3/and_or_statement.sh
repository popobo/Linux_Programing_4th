#!/bin/sh

touch file_one
rm -f file_two

# if [ -f file_one ] && echo "hello" && [ -f file_two ] && echo " there"
if [ -f file_two ] || echo "hello" || [ -f file_one ] || echo " there"
then
    echo "in if"
else
    echo "in else"
fi