#include <iostream>
using namespace std;

enum color_t
{
    red = 1,
    blue = 2,
    green = 3,
    color_unknown = 0
};

ostream &operator<<(ostream &osin, color_t colorin)
{
    string scolor = "color_unknown";
    switch (colorin)
    {
    case red:
        scolor = "red";
        break;
    case blue:
        scolor = "blue";
        break;
    case green:
        scolor = "green";
        break;
    }
    osin << scolor;
    return osin;
}

class Vehicle
{
private:
    int nwhls;

protected:
    color_t color;

public:
    Vehicle(int nwhlsin, color_t colorin)
    {
        nwhls = nwhlsin;
        color = colorin;
        cout << "New vehicle was created" << endl;
    }
    /*virtual*/ ~Vehicle() { cout << "The vehicle was destroyed" << endl; }

    /*virtual*/ void Drive() { cout << "???" << endl; }
    /*virtual*/ void Start() { cout << "????" << endl; }
    /*virtual*/ void Stop() { cout << "?????" << endl; }

    void Repaint(color_t colorin) { color = colorin; }
    void Journey()
    {
        Start();
        Drive();
        Stop();
    }
    friend ostream &operator<<(ostream &osin, Vehicle &vehiclein);
};
class Auto : public Vehicle

{

public:
    Auto(color_t colorin) : Vehicle(4, colorin)

    {

        cout << "New auto was created." << endl;
    }

    ~Auto() { cout << "The auto was destroyed." << endl; }

    void Drive() { cout << "Wruuum" << endl; }

    void Start() { cout << "Bziuuuuu" << endl; }

    void Stop() { cout << "Piiiiiiiiiiisk" << endl; }
};

ostream &operator<<(ostream &osin, Vehicle &vehiclein)

{
    osin << "The Vehicle with " << vehiclein.nwhls << " wheels, color: " << vehiclein.color;
    return osin;
}
class Van : public Auto
{
public:
    Van(color_t colorin) : Auto(colorin) { cout << " New Van was created." << endl; }
    ~Van() { cout << "Van was destoyed." << endl; }
    void Drive() { cout << "WRUUUM" << endl; }
};
void Journey(Vehicle *v)
{
    v->Start();
    v->Drive();
    v->Stop();
}
int main()
{
    Vehicle *volvo = new Auto(red);
    Journey(volvo);
    volvo->Journey();
    cout << *volvo << endl;
    delete volvo;
    Auto *van=new Van(green); 
    cout << *van << endl;
    van->Repaint(blue);
    cout << *van << endl;
    van->Drive();
    delete van;

    return 0;
}