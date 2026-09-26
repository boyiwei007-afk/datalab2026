/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

 /*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Max ops: 7
 * Difficulty: 1
 */
int bitAnd(int x, int y) {
    
    return ~((~x)|(~y));
}

/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1          
 *   Legal ops: ~ &                     
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int x, int y) {  
    return ~(x&y)&~(~x&~y);
}

/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int x, int y) {
    if(!x&&!y) return 1;
    if(!x) return 0;
    if(!y) return 0;
    return !((x>>31)^(y>>31));
}

/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int v) {
    int ans=0,t;
    t=((v>>16)>0)<<4;
    ans=ans|t;  //先看前16位 t=1or0
    v=v>>t; //t=1移动  否则在低16位 不移动

    t=((v>>8)>0)<<3;
    ans=ans|t;
    v=v>>t;

    t=((v>>4)>0)<<2;
    ans=ans|t;
    v=v>>t;

    t=((v>>2)>0)<<1;
    ans=ans|t;
    v=v>>t;

    t=(v>>1)>0;

    ans=ans|t;
    return ans;
}

/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
int byteSwap(int x, int n, int m) {
    int n1=n<<3;
    int m1=m<<3;
    int b1=((x>>n1)&0xFF)<<m1;
    int b2=((x>>m1)&0xFF)<<n1;
    x=x&(~((0xFF<<n1)|(0xFF<<m1)))|b1|b2;
    return x;
}

/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned v) {
    unsigned ans=0;
    ans=((v&0x55555555)<<1)|((v&0xAAAAAAAA)>>1);
    ans=((ans&0x33333333)<<2)|((ans&0xCCCCCCCC)>>2);
    ans=((ans&0xF0F0F0F)<<4)|((ans&0xF0F0F0F0)>>4);
    ans=((ans&0xFF00FF)<<8)|((ans&0xFF00FF00)>>8);
    ans=((ans&0xFFFF)<<16)|((ans&0xFFFF0000)>>16);
    return ans;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
int logicalShift(int x, int n) {
    
    return (x>>n)&(0xFFFFFFFF>>n);
}

/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int x) {
    int t;
    int ans=0;
    int x1=x;
    t=(!((x>>16)+1))<<4;//t大于0 则说明前16全是1 然后应该往后面8位来找 否则往前面8位
    ans+=t;
    x=x<<t;

    t=(!((x>>24)+1))<<3;
    ans+=t;
    x=x<<t;

    t=(!((x>>28)+1))<<2;
    ans+=t;
    x=x<<t;

    t=(!((x>>30)+1))<<1;
    ans+=t;
    x=x<<t;

    t=(!((x>>31)+1));
    ans+=t;
    
    return ans+!(~x1);
}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x) {
    unsigned ans=0;
    if(x==0) return 0;
    unsigned ux;
    if(x<0) { ans=0x80000000; ux =~x;ux=ux+1; }//防止溢出
    else        
       ux = x;
    int r=0,t,a=16,b=4;//标记前面连续0的个数  仿照前面int leftBitCount(int x)
    for(int i=16;b>=0;i+=a)
      {t=((ux>>i)==0)<<b--;
        ux=ux<<t;
        r=r+t;
        a=a>>1;
    }
    unsigned rem=ux&0xFF;
    ux=ux>>8;
    if ((rem>0x80)|((rem==0x80)&(ux & 1)))   
        ux++;                        
    if (ux>>24) {                          
        ux=ux>>1;
        r=r-1;                           
    }  
    ans|=((ux&0x7FFFFF))|((158-r)<<23);
  return ans;
}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf) {
    unsigned  e=(uf>>23)&0xFF;
    unsigned  m=uf&0x7FFFFF;
    if((e==0)&(m==0)) return uf;
    if((e==0xFF)&(m==0)) return uf;
    if((e==0xFF)&(m!=0))return uf;
    if((e==0)&(m!=0)) return (uf&0x80000000)|(uf<<1);
    if(e==0xFE) return (uf&0x80000000) |0x7F800000;
    return uf+0X800000;  
}

/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
    unsigned e=(uf2<<1)>>21;
    unsigned ch=uf2>>31;
    unsigned m1=(uf2&0xFFFFF)|0x100000;
    unsigned m2=uf1;
    if(!e) return 0;
    int E=e-1023;
    int ans;
    if(E>=31) return 0x80000000;
    if(E<0) return 0;
    if(E<=20)
      {
         ans=m1>>(20-E);
      }
    else
      ans=(m1<<(E-20))|(m2>>(52-E));
    if(!ch) return ans;
    return -ans;
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x) {
    if (x > 127)            
        return 0x7F800000;  
    if (x >= -126)          
        return (x + 127) << 23;
    if (x >= -149)          
        return 1 << (x + 149);
    return 0;
}
