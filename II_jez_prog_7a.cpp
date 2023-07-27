#include <iostream>
using namespace std;

class Mother
{
private:
    float x;

protected:
    float y;

public:
    Mother() { cout << "Mother's constructor" << endl; }
    ~Mother() { cout << "Mother's destructor" << endl; }
    float z;
    int GetX() { return x; }
    int GetY() { return y; }
    void ShowM() { cout << "x: " << x << " y: " << y << " z: " << z << endl; }
};

class Daughter : public Mother
{
public:
    float t;
    Daughter() { cout << "Daughter's constructor" << endl; }
    ~Daughter() { cout << "Daughter's destructor" << endl; }
    void ShowD() { cout << "x: " << GetX() << " y: " << y << " z: " << z << " t: " << t << endl; }
};

int main()
{
    Mother m;
    m.ShowM();
    cout << "x: " << m.GetX() << " y: " << m.GetY() << " z: " << m.z << endl;
    Daughter *d = new Daughter();
    d->ShowM();
    d->ShowD();

    delete d;
}