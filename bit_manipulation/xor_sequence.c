/*
* we have given an array A and the left and right index L, R. 
* we need to determine the XOR sum of the segment of A as:
*   A[L] XOR A[L + 1] XOR . . . A[R – 1] XOR A[R]
* 
*/


// naive xor_seqr
unsigned long long xor_seqr(unsigned long long l, unsigned long long r)
{
    unsigned long long L = (unsigned long long)l;
    unsigned long long R = (unsigned long long)r;

    unsigned long long tot = 0ULL;
    unsigned long long nxt = 0ULL;
    
    unsigned long long idx = 0ULL;
    
    printf("\n iter-%llu : nxt=%llu, tot=%llu \n", idx, nxt, tot);
    
    for(idx=1; idx <= R; ++idx)
    {
        nxt ^= idx;
        if(idx == L)
        {
            tot = nxt;
        }
        else if(idx > L)
        {
            tot ^= nxt;
        }
        printf("iter-%llu : nxt=%llu, tot=%llu \n", idx,nxt, tot);
    }

    return tot;

}

// optimized solution based on pattern seen in the sum of XOR's
long pattern_find(long x)
{
    switch(x%8)
    {
        case 0:
        case 1: return x;
        case 2:
        case 3: return 2;
        case 4:
        case 5: return x + 2;
        default: return 0;
    }
}

// Function from Hacker Rank
long xorSequence(long l, long r) {
    
    return pattern_find(r) ^ pattern_find(l-1);
}
