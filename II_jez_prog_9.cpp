#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
class Error
{
public:
    enum errors_t
    {
        error_unknown = 0,
        error_zero = 1,
        error_negative = 2
    };

private:
    errors_t err;

public:
    Error(errors_t err_in) { err = err_in; }
    errors_t ErrNum() { return err; }
    string What()
    {
        switch (err)
        {
        case error_zero:
            return "The number is 0";
        case error_negative:
            return "The number is negative";
        }
    }
};

class Math
{
public:
    float MySqrt(float x)
    {
        if (x < 0.0)
            throw Error(Error::error_negative);
        return sqrt(x);
    }
    float MyInverse(float x)
    {
        if (x == 0.0)
            throw Error(Error::error_zero);
        return 1.0 / x;
    }
    static float MyLog(float x)
    {
        if (x == 0.0)
            throw Error(Error::error_zero);
        if (x < 0.0)
            throw Error(Error::error_negative);
        return log(x);
    }
};

int main()
{
    Math math;
    int option = -1;
    float x, y;

    while (option != 0)
    {
        cout << "Choose one of the options: " << endl;
        cout << "0) quit" << endl;
        cout << "1) square root" << endl;
        cout << "2) invertion" << endl;
        cout << "3) logarithm" << endl;
        cin >> option;
        cout << "You choose " << option << endl;

        try
        {
            switch (option)
            {
            case 1:
                cin >> x;
                y = math.MySqrt(x);
                cout << "sqrt(" << x << ") = " << y << endl;
                break;
            case 2:
                cin >> x;
                y = math.MyInverse(x);
                cout << "1/" << x << " = " << y << endl;
                break;
            case 3:
                cin >> x;
                y = math.MyLog(x);
                cout << "log(" << x << ") = " << y << endl;
                break;
            }
        }
        catch (Error errorin)
        {
            cout << "Error: " << errorin.ErrNum() << " has occured" << endl;
            cout << errorin.What() << endl;
        }
    }

    return 0;
}