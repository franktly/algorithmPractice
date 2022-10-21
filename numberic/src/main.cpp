#include <iostream>
#include <iomanip>
/*
 *        -------|
 *    ----  |    |
 * ---|  |  |    | 
 * |  |  |  |    |
 * |S0|Si|..|Sn-1|
 * |-------------|
 * a xi xi+1     b 
 *
 * xi =  a +  (b - a) / n  * i  (i = 0... n);
 * x0 = a, xn = b;
 *
 * 1). Trapezoid Integral:
 *
 * Si =  (f(xi) + f(xi+1)) * (b-a)/2n 
 *
 * Integral of f(x) =  S0 + S1 + ...  + Sn-1
 *
 * = (b-a)/(2n) * (f(a) + 2 * (f(x1) + ... f(xn-1)) + f(b))
 *
 *
 * 2). Simpson Integral:
 *
 * Si =  Integral of  A * pow(x, 2) + B * x + C in range [xi, xi+1]
 *
 * S  =  S0 + S1 + ... + Sn-1 = Integral of  A * pow(x, 2) + B * x + C in range [a, b]
 *
 *  = (A/3 * pow(x, 3) + B/2 * pow(x, 2) +  C * x) | (b,a)
 *
 *  = (b-a)/(6n) * (f(a) + 4 * (fx(1/2) + fx(1+1/2) ... + fx(n-1 + 1/2)) + 2  * (f(x1) + f(x2) + ... f(xn-1)) + f(b));
 *
 * Integral of f(x) =  S0 + S1 + ... Sn-1
 *
 * = (b-a)/(2n) * (f(a) + 2 * (f(x1) + ... f(xn-1)) + f(b))
 *
 * */

/*
 * f(x) = pow(x,2) + x + 1
 */
double func1(double i)
{
    return  i * i + i + 1;
}

double trapezoidIntegralImpl()
{
    constexpr int N = 1000;
    int a = 0, b = 1;

    double k  = (b - a)/(2.0f * N);
    double fa = func1(a);
    double fb = func1(b);
    double S  = fa + fb;

    for(int i = 0; i < N; i++)
    {
        auto xi =  a +  (double)(b - a) / N  * i;
        S += 2 * (func1(xi)); 
    }

    return k * S;
}

double simpsonIntegralImpl()
{
    constexpr int N = 1000;
    int a = 0, b = 1;

    double k  = (b - a)/(6.0f * N);
    double fa = func1(a);
    double fb = func1(b);
    double S  = fa + 4 * func1(a + (double)(b - a) / N * 1.0f/2) + fb;

    for(int i = 1; i < N; i++)
    {
        auto xi1 =  a +  (double)(b - a) / N  * (i + 1.0f/2);
        auto xi2 =  a +  (double)(b - a) / N  * i;
        S += 4 * (func1(xi1)); 
        S += 2 * (func1(xi2)); 
    }

    return k * S;
}

int main(int argv, char** argc)
{
    auto v1 =  trapezoidIntegralImpl();
    auto v2 =  simpsonIntegralImpl();
    std::cout << "trapezoid integral result of pow(x,2) + x + 1 in range of [0, 1]: " <<  std::setprecision(33) << v1 << std::endl;
    std::cout << "simpson integral result of pow(x,2) + x + 1 in range of [0, 1]:   " <<  std::setprecision(33) << v2 << std::endl;
    return 0;
}

