#!/bin/sh

# cat <<!FUNKY!
# hello
# this is a here
# document
# !FUNKY!

ed a_text_file <<!FunkyStuff!
3
d
.,\$s/is/was/
w
q
!FunkyStuff!

exit 0
