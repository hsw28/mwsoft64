#!/bin/bash

SEDARG='/% Program:/,/Ascii/d';

for F in *.cl
do

	OUT=$F'.nh';
echo 'sed '$SEDARG' '$F' > '$OUT;
sed "$SEDARG" $F > $OUT

done

	



