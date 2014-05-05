# Run this in the directory it's in

rm -f *.bc
for f in `ls *.c`; do llvm-gcc -I ../../include -g -c -emit-llvm $f -o ${f/.c/.bc} ; done
llvm-link -o Final.bc *.bc
klee --libc=uclibc --posix-runtime Final.bc
