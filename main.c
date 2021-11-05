#include "diff_eq.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
    
    long double x0 = 0;
    long double y0 = 1;
    long double xn = 5;
    
    long double h;
    scanf("%Lf", &h);
    
    FILE *output0 = fopen("xoutput", "w");
    FILE *output1 = fopen("y1output", "w");
    FILE *output2 = fopen("y2output", "w");
    
    long double (*f) (long double, long double) = &func_6;
    long double (*real_f) (long double) = &real_y_6;
    
    long long n = (long long) ((xn - x0) / h) + 1;
    printf("%Ld\n", n);
    
    long double *res1 = calloc(n + 1, sizeof(long double));
    long double *res2 = calloc(n + 1, sizeof(long double));
    long long cur = 0;
    
    long double x1 = x0, y1 = y0;
    
    for (long long i = 0; i <= n; ++i) {
        res1[cur++] = y1;
        fprintf(output1, "%Lf\n", y1);
        y1 = next_val_2(x1, y1, h, f);
        x1 += h;
    }
    
    printf("Error is %Lf for 2 accuracy\n", q_err(res1, x0, n, h, real_f));
    
    x1 = x0;
    y1 = y0;
    cur = 0;
    
    for (long long i = 0; i <= n; ++i) {
        res2[cur++] = y1;
        fprintf(output2, "%Lf\n", y1);
        y1 = next_val_4(x1, y1, h, f);
        x1 += h;
    }
    
    printf("Error is %Lf for 4 accuracy\n", q_err(res2, x0, n, h, real_f));
    
    x1 = x0;
    
    for (long long i = 0; i <= n; ++i) {
        fprintf(output0, "%Lf\n", x1);
        x1 += h;
    }
    
    fclose(output0);
    fclose(output1);
    fclose(output2);
    free(res1);
    free(res2);
    
    system("python3.9 graph.py");
    
    return 0;
}
