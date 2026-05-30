/*
Louise plays first; then Richard.
How to play the given number:
1. If number is power of 2 then divide by 2
2. If it isn't then subtract by closest & lower pow of 2
3. Whoever gets the number to be 1 first, wins the game.
*/

// function to be called by inidividual test case input
char* counterGame(long n) {

  // define the possible answers
  const char* P0 = "Louise";   // player to go first, player-0
  const char* P1 = "Richard";  // player to go next, player-1
  
  // handle input to allow correct bit shift 
  unsigned long N = (unsigned long)(n);

  int winner = 1; // initialize winner so that First Toggle leads to player-0

  // example N = 6
  // in binary, say 4 bit, is 0b0110
  
  // remove trailing zeros and toggle winner
  while((N & 1) == 0) {
    winner ^= 1;
    N >>= 1UL;
  }

  // now 0b0011 is produced
  --N; // dont count remaining 1
  
  // now 0b0010 is produced
  // remove biggest pow of 2 i.e. count set bits
  // (toggle winner for the number of set bits)
  while(N > 0UL) {
    winner ^= 1;
    N &= (N - 1UL); 
  }
  
  return (winner == 0) ? P0 : P1;
}
