// ----------------------------------------------------------------- Endianness
//
// Endianness refers to the byte ordering of a word in memory.  Most common are
// big-endian (BE) and little-endian (LE).  Big-endian system store the most
// significant byte (MSB) of a word at the lowest memory address and the least
// significant byte (LSB) at the highest.  Whereas a little-endian system does
// the opposite, storing the LSB at the lowest address and MSB at the highest.
//
//        +-- MSB
//        |     +-- LSB
//        |     |
//        v     v
//     0xAABBCCDD  (4-byte word value)
//
//                           Big-endian                        Little-endian
//     +---------------+---------------+    +---------------+---------------+
//     | Address (hex) |   Value (hex) |    | Address (hex) |   Value (hex) |
//     +---------------+---------------+    +---------------+---------------+
//     |            00 |            AA |    |            00 |            DD |
//     |            01 |            BB |    |            01 |            CC |
//     |            02 |            CC |    |            02 |            BB |
//     |            03 |            DD |    |            03 |            AA |
//     +---------------+---------------+    +---------------+---------------+
//

#include <stdio.h>

// ---------------------------------------------------------------- Entry Point
//
// Writes the byte ordering to stdout and the endianess detected on the
// machine.
//

int main(int arg, char *argv[])
{
	unsigned int value = 0xAABBCCDDu;
	unsigned int mask = 0x000000FFu;
	const char *endianess = NULL;

	unsigned char *b = (unsigned char *)&value;
	unsigned char *e = b + sizeof(unsigned int);

	unsigned char lsb = value & mask;

	if (*b == lsb)
	{
		endianess = "Little";
	}
	else
	{
		endianess = "Big";
	}

	printf("%s-endian detected\n", endianess);

	printf("Byte ordering for address: %p value: 0x%x\n", &value, value);
	while (b != e)
	{
		printf("address: %p value: 0x%x\n", b, *b);
		b++;
	}

	return 0;
}
