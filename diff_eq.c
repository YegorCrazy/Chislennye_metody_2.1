#include <math.h>

long double func_6 (long double x, long double y) {
    x = (1 - x) * x;
    x *= y;
    return x;
}

long double real_y_6 (long double x) {
    return expl(((-1) / 6.0) * x * x * (-3 + 2 * x));
}

long double func_17_1 (long double x, long double u, long double v) {
    return sin(1.4 * u * u) - x + v;
}

long double func_17_2 (long double x, long double u, long double v) {
    return x + u - 2.2 * v * v + 1;
}

long double next_val_2 (long double xi, long double yi, long double h, 
                        long double (*f) (long double, long double)) {
    long double cur_f = f(xi, yi);
    long double y_pred = yi + cur_f * h;
    return yi + (cur_f + f(xi + h, y_pred)) * h / 2;
}

long double next_val_4 (long double xi, long double yi, long double h, 
                        long double (*f) (long double, long double)) {
    long double k1 = f(xi, yi);
    long double k2 = f(xi + h / 2, yi + (h * k1 / 2));
    long double k3 = f(xi + h / 2, yi + (h * k2 / 2));
    long double k4 = f(xi + h, yi + (h * k3));
    return yi + h * (k1 + 2 * (k2 + k3) + k4) / 6;
}

void next_val_2_4 (long double xi, long double ui, long double vi, long double h,
                    long double (*f) (long double, long double, long double),
                    long double (*g) (long double, long double, long double),
                    long double *newu, long double *newv) {
    long double k1 = f(xi, ui, vi) * h;
    long double m1 = g(xi, ui, vi) * h;
    long double k2 = f(xi + h / 2, ui + k1 / 2, vi + m1 / 2) * h;
    long double m2 = g(xi + h / 2, ui + k1 / 2, vi + m1 / 2) * h;
    long double k3 = f(xi + h / 2, ui + k2 / 2, vi + m2 / 2) * h;
    long double m3 = g(xi + h / 2, ui + k2 / 2, vi + m2 / 2) * h;
    long double k4 = f(xi + h, ui + k3, vi + m3) * h;
    long double m4 = g(xi + h, ui + k3, vi + m3) * h;
    *newu = ui + (k1 + 2 * (k2 + k3) + k4) / 6;
    *newv = vi + (m1 + 2 * (m2 + m3) + m4) / 6;
}

long double q_err (long double *res, long double x0, long long n, long double h, 
                    long double (*real) (long double)) {
    long double err = 0;
    for (long long i = 0; i <= n; ++i) {
        err += powl(fabsl(real(x0) - res[i]), 2);
        x0 += h;
    }
    err /= n;
    return sqrtl(err);
}
    
