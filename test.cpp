#include <cmath>
#include <iostream>

void test_num_sol(int N, double *num_sol)
{
    double val, l2_norm = 0, c_norm = 0;

    for (int i=1; i<=N; i++)
    {
        val = abs(num_sol[i] - (sin(5.0*i/N) + cos(3.0*i/N)));
        l2_norm += val*val;

        if (val > c_norm)
        {
            c_norm = val;
        }
    }
    std::cout<<"l2_norm: "<<sqrt(l2_norm)/N<<std::endl;
    std::cout<<"c_norm: "<<c_norm<<std::endl;
}
