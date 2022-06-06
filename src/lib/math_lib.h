/**
 * @file math_lib.h
 * @authors xdolez0c, xvecer30, xpolia05, xloren16
 * @brief Mathematical library for the calculator functions.
 * @version 1.0
 * @date 2022-04-28
 */

#include <cmath>
#include <iostream>
#include <stdexcept>

/**
 *   @brief You must create this class and all of the math function is method in
 *  this class
 *   @class math_lib_t Contain all function for our calculator
 */

class math_lib_t {
   private:
   public:
    /**
     *   @brief Make total of the entered numbers
     *   @param  x1 - real numbers
     *   @param  x2 - real numbers
     *   @return returns the total of the entered numbers
     **/
    static double add(double x1, double x2) { return x1 + x2; }

    /**
     *   @brief Make difference of the entered numbers
     *   @param  x1 - real numbers
     *   @param  x2 - real numbers
     *   @return returns the difference of the entered numbers
     **/
    static double sub(double x1, double x2) { return x1 - x2; }

    /**
     *   @brief Make multiplication of the entered numbers
     *   @param  x1 - real numbers
     *   @param  x2 - real numbers
     *   @return returns the multiplication of the entered numbers
     **/
    static double mult(double x1, double x2) { return x1 * x2; }

    /**
     *   @brief Make divided of the entered numbers
     *   @param  x1 - real numbers
     *   @param  x2 - real numbers
     *   @return returns the divided of the entered number
     **/
    static double div(double x1, double x2) {
        if (!x2)
            throw std::runtime_error("Divide by zero");

        return x1 / x2;
    }

    /**
     *   @brief Make factorial of the entered number
     *   @param  x1 - natural numbers only
     *   @return returns the factorial of the entered number
     **/
    static int fact(int x1) {
        if (x1 > 12 || x1 < 0)
            throw std::runtime_error("Operation error");

        if (x1 == 0 || x1 == 1)
            return 1;

        int result = x1;
        x1--;

        while (x1 > 1) {
            result *= x1;
            x1--;
        }

        return result;
    }

    /**
     *   @brief Make nth power of the entered number
     *   @param  x1 - base, real numbers
     *   @param  n - power, onl natural numbers
     *   @return returns the nth power of x1
     **/
    static double exp(double x1, int n) {
        if (x1 == 0 && n < 0)
            throw std::runtime_error("Operation error");

        if (n == 0)
            return 1;

        if (n < 0) {
            n = -1 * n;
            x1 = 1 / x1;
        }
        double result = 1;
        for (int i = 0; i < n; i++) {
            result *= x1;
        }

        return result;
    }

    /**
     *   @brief Make nth square root of the entered number
     *   @param  x1 - base, real numbers
     *   @param  n - power, onl natural numbers
     *   @return returns the nth square root x1
     **/
    static double my_sqrt(double x1, int n) {
        if (x1 < 0 && (n % 2 == 0))
            throw std::runtime_error("Operation error");

        if (n < -1 && x1 <= 0)
            throw std::runtime_error("Operation error");

        if (n == -1) {
            if (x1 == 0) {
                throw std::runtime_error("Operation error");
            }
            return (double)1 / x1;
        }

        if (x1 == 0)
            return 0;

        if (n == 1)
            return x1;

        double left;
        double right;
        bool zapor = false;
        bool zapExp = false;

        if (n < 0) {
            n = -1 * n;
            zapExp = true;
        }

        if (x1 < 0) {
            x1 = -1 * x1;
            zapor = true;
        }

        left = 0;
        if (x1 < 1)
            right = 1;
        else
            right = x1;

        double mid = left + (right - left) / 2;

        for (int i = 0; i < 30; i++) {
            double result = exp(mid, n);

            if (result > x1) {
                right = mid;
            } else {
                left = mid;
            }

            mid = left + (right - left) / 2;
        }

        if (zapor)
            mid = -1 * mid;

        if (zapExp)
            mid = (double)1 / mid;

        return mid;
    }

    /**
     *   @brief Make remainder after dividing of the entered numbers
     *   @param  x1 - real numbers
     *   @param  x2 - real numbers
     *   @return returns the remainder after dividing x1 and x2
     **/
    static double modulo(double x1, double x2) {
        if (!x2)
            throw std::runtime_error("Divide by zero");

        bool zapor = false;

        if (x1 < 0) {
            zapor = !zapor;
            x1 = -1.0 * x1;
        }

        if (x2 < 0) {
            zapor = !zapor;
            x2 = -1.0 * x2;
        }

        while (x1 >= x2)
            x1 -= x2;

        if (zapor)
            return -1 * x1;
        else
            return x1;
    }

    /**
     *   @brief Make result without remainder after dividing of the entered
     *  numbers
     *   @param  x1 - real numbers
     *   @param  x2 - real numbers
     *   @return returns the result without remainder after dividing x1 and x2
     **/
    static double divisionWithoutRemainder(double x1, double x2) {
        if (!x2)
            throw std::runtime_error("Divide by zero");

        bool zapor = false;

        if (x1 < 0) {
            zapor = !zapor;
            x1 = -1.0 * x1;
        }

        if (x2 < 0) {
            zapor = !zapor;
            x2 = -1.0 * x2;
        }

        int result = 0;
        while (x1 >= x2) {
            x1 -= x2;
            result++;
        }

        if (zapor)
            return -1 * result;
        else
            return result;
    }
};

/** END OF FILE */