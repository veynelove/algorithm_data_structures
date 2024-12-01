#include "./chapter_2/algorithm_analysis.h"

void chapter_2()
{
    int test[6] = {-2,11,-4,13,-5,-2};
    printf("MaxSubsequenceSum answer is: %d.\n", MaxSubsequenceSum(test, 6));
    printf("BinarySearch answer is: %d.\n", BinarySearch(test, -4, 6));
    printf("Gcd answer is: %d.\n", Gcd(50,15));
    printf("Pow answer is: %ld.\n", Pow(2, 5));
}

int main()
{   
    chapter_2();
    return 0;
}
