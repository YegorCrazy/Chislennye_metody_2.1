long double func_6 (long double x, long double y);
long double real_y_6 (long double x);

long double next_val_2 (long double xi, long double yi, long double h, 
                        long double (*f) (long double, long double));
long double next_val_4 (long double xi, long double yi, long double h, 
                        long double (*f) (long double, long double));
                        
long double q_err (long double *res, long double x0, long long n, long double h, 
                    long double (*real) (long double));
