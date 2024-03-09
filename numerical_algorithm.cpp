#include <vector>

void numerical_solver(double* num_sol, int N, double* a,
                      double* b, double* c,
                      double* d)
//a, b, c - lower, middle, upper diagonals; d - right part; num_sol - numerical solution
{
    double *alpha, *beta;
    
    alpha = new double[N-1];
    beta = new double[N];

    alpha[0] = -c[0]/b[0];
    beta[0] = d[0]/b[0];

    for (int i=1; i<N-1; i++)
    {
        double y = b[i] + a[i]*alpha[i-1];
        alpha[i] = -c[i]/y;
        beta[i] = (d[i] - a[i]*beta[i-1])/y;
    }

    beta[N-1] = (d[N-1]-a[N-1]*beta[N-2])/(b[N-1] + a[N-1]*alpha[N-2]);

    num_sol[N-1] = beta[N-1];
    for (int i=N-2; i>=0; i--)
    {
        num_sol[i] = alpha[i]*num_sol[i+1] + beta[i];
    }

    delete[] alpha;
    delete[] beta;

    return;    
}
