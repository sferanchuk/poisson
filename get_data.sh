#entrococcus faecium
#PRJNA82427
wget -O - ftp://ftp.sra.ebi.ac.uk/vol1/fastq/SRR530/SRR530535/SRR530535_1.fastq.gz | gzip -c -d >enterococcus_1.fq
wget -O - ftp://ftp.sra.ebi.ac.uk/vol1/fastq/SRR530/SRR530535/SRR530535_2.fastq.gz | gzip -c -d >enterococcus_2.fq
wget -O https://ftp.ncbi.nlm.nih.gov/genomes/all/GCF/000/321/625/GCF_000321625.1_Ente_faec_E1007_V1/GCF_000321625.1_Ente_faec_E1007_V1_genomic.fna.gz gzip -c -d >enterococcus.fa
#2nd
wget -O - https://ftp.ncbi.nlm.nih.gov/genomes/all/GCF/009/734/005/GCF_009734005.1_ASM973400v2/GCF_009734005.1_ASM973400v2_genomic.fna.gz | gzip -c -d >enterococcus2.fa

#acinetobacter baumanii
#PRJNA53447
wget -O - ftp://ftp.sra.ebi.ac.uk/vol1/fastq/SRR387/SRR387315/SRR387315_1.fastq.gz | gzip -c -d >acinetobacter_1.fq
wget -O - ftp://ftp.sra.ebi.ac.uk/vol1/fastq/SRR387/SRR387315/SRR387315_2.fastq.gz | gzip -c -d >acinetobacter_2.fq
wget -O - https://ftp.ncbi.nlm.nih.gov/genomes/all/GCF/000/309/275/GCF_000309275.1_gacin36v1.0/GCF_000309275.1_gacin36v1.0_genomic.fna.gz | gzip -c -d >acinetobacter.fa

#boletus edulis
wget -O - ftp://ftp.sra.ebi.ac.uk/vol1/fastq/SRR896/SRR896028/SRR896028_1.fastq.gz | gzip -c -d | head -n 20000000 >boletus_1.fq
wget -O - ftp://ftp.sra.ebi.ac.uk/vol1/fastq/SRR896/SRR896028/SRR896028_2.fastq.gz | gzip -c -d | head -n 20000000 >boletus_2.fq
wget -O - https://ftp.ncbi.nlm.nih.gov/genomes/all/GCA/015/179/015/GCA_015179015.1_Boled5/GCA_015179015.1_Boled5_genomic.fna.gz | gzip -c -d >boletus.fa
#2nd
wget -O - https://ftp.ncbi.nlm.nih.gov/genomes/all/GCA/054/741/165/GCA_054741165.1_BolEdBiel_h2/GCA_054741165.1_BolEdBiel_h2_genomic.fna.gz | gzip -c -d >boletus2.fa

#amphimedon queenslandica
wget -O - ftp://ftp.sra.ebi.ac.uk/vol1/fastq/SRR994/006/SRR9945486/SRR9945486_1.fastq.gz | gzip -c -d | head -n 20000000 >amphimedon_1.fq
wget -O - ftp://ftp.sra.ebi.ac.uk/vol1/fastq/SRR994/006/SRR9945486/SRR9945486_2.fastq.gz | gzip -c -d | head -n 20000000 >amphimedon_2.fq

wget -O - https://ftp.ncbi.nlm.nih.gov/genomes/all/GCF/000/090/795/GCF_000090795.2_v1.1/GCF_000090795.2_v1.1_genomic.fna.gz | gzip -c -d >amphimedon.fa

#2nd
wget -O - https://ftp.ncbi.nlm.nih.gov/genomes/all/GCA/016/292/275/GCA_016292275.1_UQ_AmQuee_3/GCA_016292275.1_UQ_AmQuee_3_genomic.fna.gz | gzip -c -d >amphimedon2.fa