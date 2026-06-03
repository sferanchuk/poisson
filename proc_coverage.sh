for sp in enterococcus acinetobacter boletus amphimedon
do
	bowtie2-build $sp.fa $sp
	bowtie2 -x $sp -a -p 8 -1 ${sp}_1.fq -2 ${sp}_2.fq -S $sp.sam
done

