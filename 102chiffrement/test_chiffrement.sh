./102chiffrement "thoma" 1 9 9 4 "01" 0 | cat -e

echo 
./102chiffrement "1011100 11010100 10000100 10111011 1 1001" 1 9 9 4 "01" 1

echo
./102chiffrement "TSTTTSS TTSTSTSS TSSSSTSS TSTTTSTT T TSST" 1 9 9 4 "ST" 1 | cat -e

echo
./102chiffrement "av czar" 2 5 1 3 "CESAR" 0

echo
./102chiffrement "RR SRE A ER SCA ECEA ESE AAC" 2 5 1 3 "CESAR" 1

echo
./102chiffrement "RR SRE A ER SCA ECEA ESE AAC" 2 5 1 3 "EPIC" 1
