#!/bin/bash

#of="data.js"

#echo "var data = [" >$of
rm fsegm.fa*
./split_parts enterococcus.fa 10000 >fsegm.fa
./split_parts enterococcus.fa 100 >fragm.fa
makeblastdb -dbtype nucl -in fsegm.fa 
#		bowtie -a -f -S fsegm fragm.fa >fmap.sam
blastn -db fsegm.fa -query fragm.fa -num_threads 12 -outfmt "6 sseqid qseqid evalue" -out enterococcus.out -max_target_seqs 500 -evalue 1e-10




