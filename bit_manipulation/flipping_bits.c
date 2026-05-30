/*
* You will be given a list of 32 bit unsigned integers. Flip all the bits
* and return the result as an unsigned integer.
*/

// wrong solution : return ~((unsigned long)n);
// converting to unsigned long will move the bits from the position compared
// to their position in the input so the result will not match

// correct solution. Do flip by using NOT i.e. ~ and then AND with the largest
// possible unisgned int i.e. all bits set to 1 (in hex 0xFFFFFFFF).

long flippingBits(long n) {
    return ~n & 0xFFFFFFFFL  ;
}
