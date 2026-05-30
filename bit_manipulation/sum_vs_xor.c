/* Find all possible x in range [0,n]
*  such that : x + n = x ^ n
*
*  
*/


long naive(long n)
{
    int count = 0;
    for(long i=0; i<=n; ++i)
    {
        if(i+n == (i^n)) ++count;
    }
    return count;
}


long optim(long n)
{
    // find the 0's before MSB
    // say, n_zeros is count,
    // and return all possible 
    // combinations i.e. 
    // 2-pow(n_zeros)
    
    long count = 0;
    long bit = log2(n); // get MSB
    
    // now find all preceding 0's
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
