
#include <stdio.h>
#include <math.h>

int main() {
    // Total possible keys ignoring identical encryption results
    double totalKeys = tgamma(26); // Gamma function for 25! (25 factorial)
    double log2TotalKeys = log2(totalKeys); // Convert to base 2
    
    // Effective unique keys accounting for identical results
    double effectiveKeys = pow(2, 49); // Approximation for effective keyspace
    double log2EffectiveKeys = log2(effectiveKeys);
    
    printf("Approximate power of 2 for total keys (ignoring identical results): 2^%.2f\n", log2TotalKeys);
    printf("Approximate power of 2 for effective unique keys: 2^%.2f\n", log2EffectiveKeys);
    
    return 0;
}
