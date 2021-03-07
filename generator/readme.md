# Cyclic Subtitle Generator
The Cyclic Subtitle Generator is a programmable device for generating subtitles. It has 26 registers, marked with letters from A to Z. Each of them stores one text. The command set for the generator is as follows:

* ZERUJ r delete the contents of the registry 'r'
* WYPISZ r delete the contents of the registry 'r'
* ODWROC r reverse order of the string in the r register (from ABCDE we get EDCBA)
* USTAW r test entering the inscription test in the r register
* PRZESUN r n moving the n leading characters of the register r to its end; for A = ABCDEF PRZESUN A 2 will make A = CDEFAB
* USUN r n delete the leading n characters of the register r
* DOKLEJ r s appending the contents of the s register to the end of the r register; after this operation the s register is cleared
* SKOPIUJ r s appending the contents of the s register to the end of the r register; after this operation, the s register retains its original value
* MIESZAJ r s inserting into the r register a string containing alternately characters from r and s, when the contents of one of the registers is over, we only add characters from the second string; after this operation the s register is cleared; e.g. for A = ABC and B = 123 execution of MIESZAJ A B will cause that A = A1B2C3 and B = empty


#### r and s are registers (one of the letters from A to Z), in each command r will be different from s. The strings will be strings of characters consisting of letters (uppercase and lowercase), numbers, parentheses, underscore (_) or operators +, -, *, /. Immediately after booting, all registers store empty strings. Implement a Cyclic Subtitle Generator.

### Entry
#### The input will give the commands for the generator.
### Exit
#### Successive results of the operation should be written on the output WYPISZ.

### Example
### Input
```
USTAW A ABCDEF
WYPISZ A
PRZESUN A 2
WYPISZ A
USUN A 3
WYPISZ A
ODWROC A
WYPISZ A
ZERUJ A
WYPISZ A
USTAW A 123
USTAW B 456
DOKLEJ A B
WYPISZ A
USTAW B STUVWXYZ
MIESZAJ A B
WYPISZ A
USTAW A *
WYPISZ A
SKOPIUJ B A
DOKLEJ A B
WYPISZ A
SKOPIUJ B A
DOKLEJ A B
WYPISZ A
SKOPIUJ B A
DOKLEJ A B
WYPISZ A
```

### Output
```
ABCDEF
CDEFAB
FAB
BAF

123456
1S2T3U4V5W6XYZ
*
**
****
********
```
