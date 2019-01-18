/*
 * Assignment 2 test program
 *
 * cc -Wall -Wextra -o test_assignment2 test_assignment2.c
 */

#include <stdio.h>

#include <sys/types.h>

static inline void
__cpuid(unsigned int *eax, unsigned int *ebx, unsigned int *ecx,
    unsigned int *edx)
{
      asm volatile("cpuid"
            : "=a" (*eax),
              "=b" (*ebx),
              "=c" (*ecx),
              "=d" (*edx)
            : "0" (*eax), "1" (*ebx), "2" (*ecx), "3" (*edx));
}

int
main(int argc, char **argv)
{
	unsigned int eax, ebx, ecx, edx;

	eax = 0x0;
	__cpuid(&eax, &ebx, &ecx, &edx);
	printf("CPUID(0x0) Brand String = %c%c%c%c%c%c%c%c%c%c%c%c\n",
	    (char)((ebx & 0xFF)),
	    (char)((ebx & 0xFF00) >> 8),
	    (char)((ebx & 0xFF0000) >> 16),
	    (char)(ebx >> 24),

	    (char)((edx & 0xFF)),
	    (char)((edx & 0xFF00) >> 8),
	    (char)((edx & 0xFF0000) >> 16),
	    (char)(edx >> 24),

	    (char)((ecx & 0xFF)),
	    (char)((ecx & 0xFF00) >> 8),
	    (char)((ecx & 0xFF0000) >> 16),
	    (char)(ecx >> 24));

	if (argc >= 2) {
		ebx = argv[1][0] | ((unsigned int)argv[1][1] << 8) |
		    ((unsigned int)argv[1][2] << 16) |
		    ((unsigned int)argv[1][3] << 24);
		edx = argv[1][4] | ((unsigned int)argv[1][5] << 8) |
		    ((unsigned int)argv[1][6] << 16) |
		    ((unsigned int)argv[1][7] << 24);
		ecx = argv[1][8] | ((unsigned int)argv[1][9] << 8) |
		    ((unsigned int)argv[1][10] << 16) |
		    ((unsigned int)argv[1][11] << 24);
		eax = 0x4FFFFFFE;
		printf("set override eax=%x ebx=%x ecx=%x edx=%x\n",
		    eax, ebx, ecx, edx);
		__cpuid(&eax, &ebx, &ecx, &edx);
		printf("CPUID(0x4FFFFFFE)\n");	
	}

	eax = 0x4FFFFFFF;
	__cpuid(&eax, &ebx, &ecx, &edx);
	printf("CPUID(0x4FFFFFFF)\n");	

	eax = 0x0;
	__cpuid(&eax, &ebx, &ecx, &edx);
	printf("CPUID(0x0) Brand String = %c%c%c%c%c%c%c%c%c%c%c%c\n",
	    (char)((ebx & 0xFF)),
	    (char)((ebx & 0xFF00) >> 8),
	    (char)((ebx & 0xFF0000) >> 16),
	    (char)(ebx >> 24),

	    (char)((edx & 0xFF)),
	    (char)((edx & 0xFF00) >> 8),
	    (char)((edx & 0xFF0000) >> 16),
	    (char)(edx >> 24),

	    (char)((ecx & 0xFF)),
	    (char)((ecx & 0xFF00) >> 8),
	    (char)((ecx & 0xFF0000) >> 16),
	    (char)(ecx >> 24));
	
	eax = 0x4FFFFFFF;
	__cpuid(&eax, &ebx, &ecx, &edx);
	printf("CPUID(0x4FFFFFFF)\n");	

	eax = 0x0;
	__cpuid(&eax, &ebx, &ecx, &edx);
	printf("CPUID(0x0) Brand String = %c%c%c%c%c%c%c%c%c%c%c%c\n",
	    (char)((ebx & 0xFF)),
	    (char)((ebx & 0xFF00) >> 8),
	    (char)((ebx & 0xFF0000) >> 16),
	    (char)(ebx >> 24),

	    (char)((edx & 0xFF)),
	    (char)((edx & 0xFF00) >> 8),
	    (char)((edx & 0xFF0000) >> 16),
	    (char)(edx >> 24),

	    (char)((ecx & 0xFF)),
	    (char)((ecx & 0xFF00) >> 8),
	    (char)((ecx & 0xFF0000) >> 16),
	    (char)(ecx >> 24));
}
	
	
