//
// Created by maxim on 31.10.19.
//

#include "math.h"

namespace mylib
{

    unsigned int pow(unsigned int a, unsigned int x)
    {
        if(x == 2)
        {
            return x * x;
        }

        else if(x == 3)
        {
            return x*x*x;
        }

        unsigned int (*f)(unsigned int a, unsigned int x) = [](unsigned int a, unsigned int x) -> decltype(x)
        {
            unsigned int sum = a;

            for(unsigned int i = 0; i < x; i+=2)
            {
                sum *= sum;
            }

            return sum;
        };

        if(x%2 == 0 && x > 2)
        {
            return f(a, x);
        }

        else if(x%2 != 0 && x > 3)
        {
            return f(a, x-1) * a;
        }
    }

    unsigned long long pow(unsigned long long a, unsigned long long x)
    {
        if(x == 0)
        {
            return 1;
        }
        else if(x == 1)
        {
            return a;
        }
        else if(x == 2)
        {
            return a * a;
        }

        else if(x == 3)
        {
            return a*a*a;
        }


        unsigned long long (*f)(unsigned long long a, unsigned long long x) = [](unsigned long long a, unsigned long long x) -> decltype(x)
        {

            for(unsigned long long i = 0; i < x; i+=2)
            {
                a *= a;
            }

            return a;
        };

        if(x%2 == 0 && x > 2)
        {
            return f(a, x);
        }

        else if(x%2 != 0 && x > 3)
        {
            return f(a, x-1) * a;
        }
    }

    int pow(int a, int x)
    {
        if(x == 0)
        {
            return 1;
        }

        if(x < 0)
        {
            return 1/pow(a, x * (-1));
        }
        else {


            if (x == 2) {
                return a * a;
            } else if (x == 3) {
                return a * a * a;
            }

            int (*f)(int a, int x) = [](int a,int x) -> decltype(x) {
                int sum = a;

                for (int i = 0; i < x; i += 2) {
                    sum *= sum;
                }

                return sum;
            };

            if (x % 2 == 0 && x > 2) {
                return f(a, x);
            } else if (x % 2 != 0 && x > 3) {
                return f(a, x - 1) * a;
            }
        }
    }

    long long pow(long long a, long long x)
    {
        if(x == 0)
        {
            return 1;
        }

        if(x < 0)
        {
            return 1/pow(a, x * (-1));
        }
        else {


            if (x == 2) {
                return a * a;
            } else if (x == 3) {
                return a * a * a;
            }

            long long (*f)(long long a, long long x) = [](long long a,long long x) -> decltype(x) {
                long long sum = a;

                for (long long i = 0; i < x; i += 2) {
                    sum *= sum;
                }

                return sum;
            };

            if (x % 2 == 0 && x > 2) {
                return f(a, x);
            } else if (x % 2 != 0 && x > 3) {
                return f(a, x - 1) * a;
            }
        }
    }

    double pow(double a, double x)
    {
        return e(x * ln(a));
    }

    double sin(double x)
    {
        double sum = 0;
        short n = 100;
        double (*pow)(double a, int x) = [](double a, int x) -> decltype(a)
        {
            for (int i = 0; i < x; i += 2) {
                a *= a;
            }

            return a;

        };

        int val;

        for(int i = 0; i < n; i++)
        {
            val = 2*i+1;
            sum += (pow(-1, val)/(double)factorial(val)) * pow(x, val);
        }

        return sum;
    }

    double cos(double x)
    {
        double sum = 0;
        short n = 100;

        double (*pow)(double a, int x) = [](double a, int x) -> decltype(a)
        {
            for (int i = 0; i < x; i += 2) {
                a *= a;
            }

            return a;

        };

        int val;

        for(int i = 0; i < n; i++)
        {
            val = 2*i;
            sum += (pow(-1, i)/(double)factorial(val)) * pow(x, val);
        }

        return sum;
    }

    double ln(double x)
    {
        x--;
        double sum = 0;
        short n = 100;

        double (*pow)(double a, int x) = [](double a, int x) -> decltype(a)
        {
            for (int i = 0; i < x; i += 2) {
                a *= a;
            }

            return a;

        };

        for(int i = 0; i < n; i++)
        {
            sum += (pow(-1, i+1)/(double)factorial(i)) * pow(x, i);
        }

        return sum;
    }

    double e(double x)
    {
        double sum = 0;
        const short n = 100;

        double (*pow)(double a, int x) = [](double a, int x) -> decltype(a)
        {
            for (int i = 0; i < x; i += 2) {
                a *= a;
            }

            return a;

        };

        for(int i = 0; i < n; i++)
        {
            sum += pow(x, i)/(double)factorial(i);
        }

        return sum;
    }

    double lg(double x)
    {
        return ln(x)/ln(10);
    }

    double log2(double x)
    {
        return ln(x)/ln(2);
    }

    long long factorial(long long x)
    {
        if(x == 0 || x == 1)
        {
            return 1;
        }

        long long sum = 1;

        for (long long i = x; i > 1; i--)
        {
            sum *= x;
        }

        return sum;
    }

}