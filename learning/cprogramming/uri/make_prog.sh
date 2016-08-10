echo -n "Type program number: "
read prog
mkdir $prog
cp in.txt $prog 
cp prog.c $prog 
cp makefile $prog 
cd $prog 
sublime in.txt prog.c
