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
//     0xA0B0C0D0  (4-byte word value)
//
//                           Big-endian                        Little-endian
//     +---------------+---------------+    +---------------+---------------+
//     | Address (hex) |   Value (hex) |    | Address (hex) |   Value (hex) |
//     +---------------+---------------+    +---------------+---------------+
//     |            00 |            A0 |    |            00 |            D0 |
//     |            01 |            B0 |    |            01 |            C0 |
//     |            02 |            C0 |    |            02 |            B0 |
//     |            03 |            D0 |    |            03 |            A0 |
//     +---------------+---------------+    +---------------+---------------+
//

#include <stdio.h>

// ---------------------------------------------------------------- Entry Point
//
// Writes the detected endianness and byte ordering to stdout on the machine.
//

int main(int arg, char *argv[])
{
	unsigned int value = 0xA0B0C0D0u;
	unsigned int mask = 0x000000FFu;
	const char *endianness = NULL;

	unsigned char *b = (unsigned char *)&value;
	unsigned char *e = b + sizeof(unsigned int);

	unsigned char lsb = value & mask;

	if (*b == lsb)
	{
		endianness = "Little";
	}
	else
	{
		endianness = "Big";
	}

	printf("%s-endian detected\n", endianness);

	printf("Byte ordering for address: %p value: 0x%x\n", &value, value);
	while (b != e)
	{
		printf("address: %p value: 0x%x\n", b, *b);
		b++;
	}

	return 0;
}
