#!/bin/bash

#
# Test N times and get times
#

USAGE="Usage: $0 <file> <option> <exercise> <ntimes>\n
<file>: binary program p1 openmp\n
<option>: -e, --exercise\n
<exercise>: integer value\n
<ntimes: integer value"

if [ $# -ne 4 ]
then 
    echo -e $USAGE
    exit 1
fi

if [[ -f $1 ]]; then
    ile=$1
else
    echo "ERROR: first parameter must be real file."
    echo -e $USAGE
    exit 1
fi

mode=$2

if [ "$3" -eq "$3" ] 2>/dev/null
then
    exercise=$3
else
    echo "ERROR: third parameter must be an integer."
    echo -e $USAGE
    exit 1
fi

if [ "$4" -eq "$4" ] 2>/dev/null
then
    ntimes=$4
else
    echo "ERROR: fourth parameter must be an integer."
    echo -e $USAGE
    exit 1
fi

acc=0
tmp=0
mean=0

x=1
while [ $x -le $ntimes ]
do
  echo "Execution: $x"
  tmp=($(./main $mode $exercise | cut -d ';' -f2 ))
  acc=$(( $acc + $tmp ))
  x=$(( $x + 1 ))
done

mean=$(( $acc / $ntimes ))

echo ""
echo "TOTAL Executions: $ntimes"
echo "Average time: $(($mean))us"