#include <iostream>
#include <cmath>
#include "numerical_algorithm.h"
#include "test.h"

double right_part(double x){
    return (25*sin(5*x)+9*cos(3*x));
}

double exact_solution(double x){
    return (sin(5*x) + cos(3*x));
}

int main()
{
    int N;
    std::cout<<"Число точек сетки: ";
    std::cin>>N;
    std::cout<<std::endl;

    double* num_right_part;
    num_right_part = new double[N-1];

    double h = 1.0/N;
    for(int i=1; i<N; i++)
        num_right_part[i-1] = right_part(i*h)/(N*N);

    num_right_part[0] += exact_solution(0);
    num_right_part[N-2] += exact_solution(1);

    double* num_sol;
    num_sol = new double[N+1];
    num_sol[0] = exact_solution(0);
    num_sol[N] = exact_solution(1);

    double *main_diag, *side_diag;
    main_diag = new double[N-1];
    side_diag = new double[N-1]; 
    for (int i=1; i<N; i++)
    {
        main_diag[i-1] = 2;
        side_diag[i-1] = -1;
    }

    numerical_solver(num_sol+1, N-1, side_diag, main_diag, side_diag, num_right_part);

    test_num_sol(N, num_sol);

    delete[] main_diag;
    delete[] side_diag;
    delete[] num_sol;
    delete[] num_right_part;

    return 0;
}
