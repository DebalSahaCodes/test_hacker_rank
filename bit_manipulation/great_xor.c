/*
* Find all x in range (0, N) i.e. excluding 0 and N
* such that x ^ N > N

*/
long naive(long n)
{
    long count = 0;
    for(long i=1; i<n; ++i)
    {
        if((i^n) > n) ++count;
    }
    return count;
}

// Optimal solution:
// --------------------
//  result = sum of all 2-pow(count)
//  where count = number of 0's in 
//  bits of the long value
//
long optim(long n) {
    long count = 0L;
    long idx = 0L;    
    while(n>0) {
        if(n%2 == 0) {
            count += (long)pow(2, idx);
        }
        n = n/2;
        ++idx;
    }
    return count;
}

long theGreatXor(long x) {
    //return naive(x);
    return optim(x);
}
