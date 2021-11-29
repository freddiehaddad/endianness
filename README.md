# Endianness

Endianness refers to the byte ordering of a word in memory.  Most common are
big-endian (BE) and little-endian (LE).  Big-endian system store the most
significant byte (MSB) of a word at the lowest memory address and the least
significant byte (LSB) at the highest.  Whereas a little-endian system does the
opposite, storing the LSB at the lowest address and MSB at the highest.

```text
   +-- MSB
   |     +-- LSB
   |     |
   v     v
0xA0B0C0D0  (4-byte word value)

                      Big-endian                        Little-endian
+---------------+---------------+    +---------------+---------------+
| Address (hex) |   Value (hex) |    | Address (hex) |   Value (hex) |
+---------------+---------------+    +---------------+---------------+
|            00 |            A0 |    |            00 |            D0 |
|            01 |            B0 |    |            01 |            C0 |
|            02 |            C0 |    |            02 |            B0 |
|            03 |            D0 |    |            03 |            A0 |
+---------------+---------------+    +---------------+---------------+
```

## Building

The C Standard Library is required for compilation.  On Ubuntu Linux or Debian based distributions, dependencies can be installed with:

```BASH
$ sudo apt install build-essential
```

Compiling the program:

```BASH
$ gcc -g endianness.c -o endianness
```

## Running and Debugging

Running the program directly:

```BASH
$ ./endianness
```

Debugging can be done with GDB:

```BASH
$ gdb ./endianness
```

## Sample Output

```text
$ ./endianness 
Little-endian detected
Byte ordering for address: 0x7ffc58d6f638 value: 0xa0b0c0d0
address: 0x7ffc58d6f638 value: 0xd0
address: 0x7ffc58d6f639 value: 0xc0
address: 0x7ffc58d6f63a value: 0xb0
address: 0x7ffc58d6f63b value: 0xa0
```
