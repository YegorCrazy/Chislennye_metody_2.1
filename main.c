#include "diff_eq.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv) {
    
    system("rm -f *output");
    
    if (strcmp(argv[1], "--help") == 0) {
        printf("Two arguments needed:\n");
        printf("1) Number of functions (1 or 2)\n");
        printf("2) Function number (one of implemented)\n");
        printf("Now implemented: 6 for 1 function, 17 for 2 functions\n");
        return 0;
    }
    
    if (argc < 3) {
        printf("2 arguments needed\n");
        return 0;
    }
    
    if (strtol(argv[1], NULL, 10) == 1) {
    
        long double x0;
        long double y0;
        long double xn;
        
        long double h;
        scanf("%Lf", &h);
        
        FILE *output0 = fopen("xoutput", "w");
        FILE *output1 = fopen("y1output", "w");
        FILE *output2 = fopen("y2output", "w");
        
        long double (*f) (long double, long double);
        long double (*real_f) (long double);
        
        if (strtol(argv[2], NULL, 10) == 6) {
            f = &func_6;
            real_f = &real_y_6;
            x0 = 0;
            y0 = 1;
            xn = 5;
        } else {
            printf("Unknown function number\n");
            return 0;
        }
        
        long long n = (long long) ((xn - x0) / h) + 1;
        printf("%Ld parts\n", n);
        
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
        
        system("python3.9 graph.py 1");
        
    } else if (strtol(argv[1], NULL, 10) == 2) {
        
        long double x0;
        long double u0;
        long double v0;
        long double xn;
        
        long double h;
        scanf("%Lf", &h);
        
        FILE *output0 = fopen("xoutput", "w");
        FILE *output1 = fopen("uoutput", "w");
        FILE *output2 = fopen("voutput", "w");
        
        long double (*f) (long double, long double, long double);
        long double (*g) (long double, long double, long double);
        
        if (strtol(argv[2], NULL, 10) == 17) {
            f = &func_17_1;
            g = &func_17_2;
            x0 = 0;
            u0 = 1;
            v0 = 0.5;
            xn = 5;
        } else {
            printf("Unknown function number\n");
            return 0;
        }
        
        long long n = (long long) ((xn - x0) / h) + 1;
        printf("%Ld parts\n", n);
        
        long double *resu = calloc(n + 1, sizeof(long double));
        long double *resv = calloc(n + 1, sizeof(long double));
        long long cur = 0;
        
        long double x1 = x0, u1 = u0, v1 = v0;
        
        for (long long i = 0; i <= n; ++i) {
            resu[cur] = u1;
            resv[cur++] = v1;
            fprintf(output1, "%Lf\n", u1);
            fprintf(output2, "%Lf\n", v1);
            next_val_2_4(x1, u1, v1, h, f, g, &u1, &v1);
            x1 += h;
        }
        
        x1 = x0;
        
        for (long long i = 0; i <= n; ++i) {
            fprintf(output0, "%Lf\n", x1);
            x1 += h;
        }
        
        //printf("Error is %Lf for 2 accuracy\n", q_err(res1, x0, n, h, real_f));
        
        fclose(output0);
        fclose(output1);
        fclose(output2);
        free(resu);
        free(resv);
        
        system("python3.9 graph.py 2");
        
    } else {
        
        printf("Unknown first argument\n");
        
    }
    
    return 0;
}
