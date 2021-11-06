long double func_6 (long double x, long double y);
long double real_y_6 (long double x);

long double func_17_1 (long double x, long double u, long double v);
long double func_17_2 (long double x, long double u, long double v);

long double next_val_2 (long double xi, long double yi, long double h, 
                        long double (*f) (long double, long double));
long double next_val_4 (long double xi, long double yi, long double h, 
                        long double (*f) (long double, long double));
void next_val_2_4 (long double xi, long double ui, long double vi, long double h,
                    long double (*f) (long double, long double, long double),
                    long double (*g) (long double, long double, long double),
                    long double *newu, long double *newv);
                        
long double q_err (long double *res, long double x0, long long n, long double h, 
                    long double (*real) (long double));
