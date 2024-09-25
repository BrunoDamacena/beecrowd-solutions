#include <iostream>
#include <vector>
#include <cmath>

#define MOD 1000000007
#define SUM_1_TO_9 45

long long sumOfDigits(long long n, std::vector<long long>& dp) 
{ 
    if (n < 10) {
        return (n * (n + 1) / 2) % MOD; 
    }

    long long numOfDigits = (long long) std::log10(n); 
    long long powNumOfDigits = (long long) std::pow(10, numOfDigits); 
    long long mostSignificantDigit = n / powNumOfDigits; 

    long long msdContribution = mostSignificantDigit * dp[numOfDigits];
    long long triangularSum = mostSignificantDigit * (mostSignificantDigit - 1) / 2;
    long long triangularSumContribution = triangularSum * powNumOfDigits;
    long long remainingDigitsContribution = mostSignificantDigit * (1 + n % powNumOfDigits);
    long long recSum = sumOfDigits(n % powNumOfDigits, dp);

    return (msdContribution + triangularSumContribution + remainingDigitsContribution + recSum) % MOD;
} 

long long calculateBoundaryFrom1ToN(long long n) {
    int numOfDigits = std::max((int) std::log10(n), 1);
    std::vector<long long> dp(numOfDigits + 1); 
    dp[0] = 0; 
    dp[1] = SUM_1_TO_9;
    
    for (long long i = 2; i <= numOfDigits; i++) {
        long long powNumOfDigits = std::pow(10, i - 1);
        dp[i] = (dp[i - 1] * 10 % MOD) + (SUM_1_TO_9 * powNumOfDigits % MOD);
    }
    
    return sumOfDigits(n, dp); 
}

long long calculateBoundaryFromLToR(long long l, long long r) {
    long long sum = calculateBoundaryFrom1ToN(r);
    sum -= calculateBoundaryFrom1ToN(l - 1);
    return sum;
}

int main() {
    long long l, r;
    while (std::cin >> l >> r) {
        std::cout << calculateBoundaryFromLToR(l, r) << std::endl;
    }
    return 0;
}
