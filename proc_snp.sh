
for sp in enterococcus boletus amphimedon
do
	nucmer $sp.fa ${sp}2.fa
	rm $sp.aln
	grep \> $sp.fa | while read line
	do
		id1=`echo $line | awk '{ print substr( $1, 2 ); }'`
		grep \> ${sp}2.fa | while read line2
		do
			id2=`echo $line2 | awk '{ print substr( $1, 2 ); }'`
			echo $id1 $id2
			show-aligns out.delta $id1 $id2 >>$sp.aln
		done
	done
done
