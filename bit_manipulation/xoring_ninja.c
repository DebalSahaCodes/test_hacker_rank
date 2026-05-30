/*
* XOR on a list means : x_0 XOR x_1 XOR ... XOR x_n-1
* Call it operation XOR_on_list
* XorSum of list means Sum of XOR_on_list of all possible 
* non-empty set/list that can be created from the elements
* in the given list.
* Call it XorSum_of_list
* 
* Given a list of numbers, find : (XorSum_of_list % (pow(10,9) + 7))
* where pow is power operation and % is modulus. 
*/



int xorSum1(int n, int* arr) {
    int sum = 0;
    int magic_num = 1000000007;

    for(int i=0; i< n; ++i) sum |= arr[i];
    while(--n) sum = (sum << 1) % magic_num;
  
    return sum;
}


int xoringNinja(int arr_count, int* arr) {
    return xorSum1(arr_count, arr);
}
