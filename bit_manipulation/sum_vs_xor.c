/* Find all possible x in range [0,n]
*  such that : x + n = x ^ n
**/
long naive(long n)
{
    int count = 0;
    for(long i=0; i<=n; ++i)
    {
        if(i+n == (i^n)) ++count;
    }
    return count;
}

/*
* NOTE: optimized solution patttern
* -------------------------------------
* XOR is binary addition without carry.
*  The condition of result_XOR = result_ADD
*  happens when there is no carry.
*  
*  To achieve that for each number between
*  0 and n, we need to check for all the bits
*  in n that are 0 trailing the MSB.
*/

long optim(long n)
{
    
    long count = 0;
    long bit = log2(n); // get MSB
    
    // now find all 0's after MSB
    for(; bit >= 0L; --bit)
    {
        long mask = (1L << bit);
        if(!(n & mask)) ++count;
    }
    
    return 1L << count; // all possible combo of 0's i.e. 2-pow(count)
}

long sumXor(long n) {
    //return naive(n);
    return optim(n);
}
