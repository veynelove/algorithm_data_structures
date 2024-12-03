#include "hashing.h"

//not recommended
Index Hash0(const char *Key, int TableSize)
{
    unsigned int HashVal = 0;
    while(*Key != '\0')
        HashVal += *Key++;
    return HashVal % TableSize;
}
//not recommended
Index Hash1(const char *Key, int TableSize)
{
    return (Key[0] + 27*Key[1] + 729*Key[2]) % TableSize;
}

Index Hash2(const char *Key, int TableSize)
{
    unsigned int HashVal = 0;
    while(*Key != '\0')
        HashVal = (HashVal << 5) + *Key++;
    return HashVal % TableSize;
}

Index Hash3(int Key, int TableSize)
{
    return Key % TableSize;
}

int isPrime(int num)
{
    if(num <= 1) return 0;
    if(num == 2) return 1;
    if(num % 2 == 0) return 0;
    for(int i=3;i<sqrt(num); i+=2) {
        if(num % i == 0) return 0;
    }
    return 1;
}

int NextPrime(int n)
{
    int candidate = n+1;
    while(!isPrime(candidate)) {
        candidate++;
    }
    return candidate;
}
