#include <stdio.h>

main() {
    double x;
    int n, i;
    double pot = 1;
    int nOrig;
    printf("x, n? ");
    scanf("%lf%d", &x, &n);

    nOrig = n;
    if (n < 0) {
        n = -n;
    }
    for(i = 0 ; i < n ; i++) {
        pot = pot * x;
    }
    if (nOrig < 0) {
        pot = 1 / pot;
    }
    printf("%lf elevado a %d = %lf\n",
            x, nOrig, pot );

}

