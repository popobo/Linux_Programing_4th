#!/bin/sh

salution="Hello"
echo $salution
echo "The program $0 is now running"
echo "The second parameter was $2"
echo "The second parameter was $1"
echo "The parameter list is $*"
echo "The user's home directory is $HOME"

echo "Please enter a new greeting"
read salution

echo $salution
echo "The Script is now complete"
exit 0
