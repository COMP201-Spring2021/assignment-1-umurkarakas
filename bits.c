/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2020 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    int res = ~((~(~x&y))&(~(x&~y)));
    return res;
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
    /* creates a temp int which has nth byte in mth byte's location and another temp int which has mth byte in nth byte's location, other bits are 1. Then uses or operator for the resulting int */
    int shift1 = n << 3;  // to get 8*n
    int shift2 = m << 3;  // to get 8*m
    int temp1 = ~((~(x >> shift1) & 0xff) << shift2); // shifting nth byte to mth byte's position, the rest bits are 1
    int temp2 = ~((~(x >> shift2) & 0xff) << shift1); // shifting mth byte to nth byte's position, the rest bits are 1
    int res = (x | (0xff << shift1) | (0xff << shift2)) & temp1 & temp2;
    return res;
}
/* 
 * isLowerCaseLetter - return 1 if 0x61 <= x <= 0x7A (ASCII codes for characters 'a' to 'z')
 *   Example: isLowerCaseLetter(0x65) = 1.
 *            isLowerCaseLetter(0x60) = 0.
 *            isLowerCaseLetter(çok ) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isLowerCaseLetter(int x) {
    /* checks whether x is between 0b01100001 and 0b01111010 */
    int res = (!(x >> 7) & ((x >> 6) & (x >> 5))) & !(((x & 31) + 5) >> 5) & !(!(x & 31));
    return res;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
    /* uses a mask to find the number of 1 bits in each byte and creates another mask then uses newly created mask to sum the number of 1 bits in each byte */ 
    int mask = 1 | (1 << 8) | (1 << 16) | (1 << 24); // mask to calculate number of 1 bits in each byte
    int bitCountBytes = (mask & x) + (mask & (x >> 1)) + (mask & (x >> 2)) + (mask & (x >> 3)) + (mask & (x >> 4)) + (mask & (x >> 5)) + (mask & (x >> 6)) + (mask & (x >> 7)); // number of 1 bits in each byte
    int res = (bitCountBytes & 0xff) + ((bitCountBytes >> 8) & 0xff) + ((bitCountBytes >> 16) & 0xff) + ((bitCountBytes >> 24) & 0xff);
    return res;
}
/* 
 * divpwr4 - Compute x/(4^n), for 0 <= n <= 15
 *  Round toward zero
 *   Examples: divpwr4(15,1) = 3, divpwr4(-33,2) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 17
 *   Rating: 2
 */
int divpwr4(int x, int n) {
    /* shifts x to the right by 2n to divide by 4^n and then evaluates the extreme cases where there is either no shift or there is a remainder from dividing by 4^n */
    int shiftedVal = ((x >> n) >> n); // division by 4^n
    return shiftedVal + ((!(~x >> 31)) & !(!n) & !(!(((1 << n << n) + ~0) & x))); // checking extreme cases and adding 1 accordingly
}
/*
 * ezThreeFourths - multiplies by 3/4 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/4),
 *   including overflow behavior.
 *   Examples: ezThreeFourths(11) = 8
 *             ezThreeFourths(-9) = -6
 *             ezThreeFourths(1073741824) = -268435456 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int ezThreeFourths(int x) {
    /* creates an int for 3*x/4 and checks extreme cases where the number is negative and there is a remainder from dividing by 4 */ 
    int multipleOfThreeForths = (x + (x << 1)) >> 2; // 3*x/4 
    int res = multipleOfThreeForths + (!(~multipleOfThreeForths >> 31) & ((x & 1) | ((x >> 1) & 1))); // checking the extreme case if 3*x/4 has a remainder and 3*x/4 is negative or not
    return res;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
    /* equalizes all bits to 1 that comes after the most significant 1 bit, then counts the number of 1 bits and evaluates the extreme cases where x is negative and it has only one 1-bit */
    int absVal = ((x >> 31) & (~x + 1)) | ((~x >> 31) & x); // absolute value of X
    int mask = (absVal | ((absVal >> 1) & ~0)); // to prevent any error caused by arithmetical right shift in negative ints
    int mask1, bitCountBytes, res;
    mask = mask | (mask >> 2);
    mask = mask | (mask >> 4);
    mask = mask | (mask >> 8) | (mask >> 16) | (mask >> 24); // mask is filled with 1's from the most significant 1-bit to the least significant bit
    mask1 = 1 | (1 << 8) | (1 << 16) | (1 << 24);
    bitCountBytes = (mask1 & mask) + (mask1 & (mask >> 1)) + (mask1 & (mask >> 2)) + (mask1 & (mask >> 3)) + (mask1 & (mask >> 4)) + (mask1 & (mask >> 5)) + (mask1 & (mask >> 6)) + (mask1 & (mask >> 7));
    res = (bitCountBytes & 0xff) + ((bitCountBytes >> 8) & 0xff) + ((bitCountBytes >> 16) & 0xff) + ((bitCountBytes >> 24) & 0xff); // counting the 1 bits in mask
    res = ~(~res + (1 & !(((1 << res) >> 1) ^ absVal) & (1 & (x >> 31))));    
    res = res + (1 & !(!(x ^ (1 << 31)))); // checking the extreme cases
    return res;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
    /* returns the negative of uf if it doesn't correspond to NaN, if it's NaN returns uf */
    unsigned negUf = uf ^ (1 << 31); // negative of uf
    if (!(((negUf >> 23) & 0xff) ^ 0xff) && (negUf << 9)) {
	return uf; // for NaN cases
    } else {
        return negUf;
    }
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
    /* returns uf if it's NaN, if exponent is 0x00 or 0x01, checks if it's 2nd least significant bit is 1, if so adds 1 to fraction shifts the entire floating point to the right by 1 except the sign bit, if there's no extreme case, it only subtracts 1 from exponent then returns the value */
    unsigned int fraction = (uf << 9) >> 9; 
    unsigned int sign = (uf >> 31) << 31;
    unsigned int exponent = ((uf << 1) >> 24);
    if ((!exponent) || !(exponent ^ 1)) { // for the cases where the exponent is minimum
        return (sign | ((fraction + (1 & ((fraction & 2) >> 1 ))) >> 1)) | (exponent << 22);
    } else if (!(exponent ^ 0xff)) { // checking the NaN case
        return uf;
    } else { // 1 is subtracted from exponent
        return sign | fraction | (~(~exponent + 1) << 23);
    }  
}
