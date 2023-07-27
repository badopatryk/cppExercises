#include <iostream>
#include <fstream>

using namespace std;

class Vector
{
private:
    int size;
    double* val;

public:
    Vector(int s)
    {
        size = s;
        val = new double[s];
    }
    ~Vector() { delete[] val; }
    void Show();
    void Write(char* nameout);
    void ReadIn(char* namein);
    bool Set(int i, double v)
    {
        if ((i >= 0) && (i <= size))
            val[i] = v;
        else
            return 0;
        return 1;
    }
    double Get(int i) { return val[i]; }
};
void Vector::Show()
{
    cout << "(";

    for (int i = 0; i < size; i++)

    {

        if (i != size - 1)

            cout << val[i] << ", ";

        else

            cout << val[i] << ")";
    }

    cout << endl;
}
void Vector::Write(char* nameout)
{
    ofstream file(nameout);

    file << size << endl;

    for (int i = 0; i < size; i++)

        file << val[i] << " ";

    file << endl;

    file.close();
}
void Vector::ReadIn(char* namein)
{

    if (val)
        delete[] val;

    ifstream file(namein);

    file >> size;

    val = new double[size];

    for (int i = 0; i < size; i++)

        file >> val[i];

    file.close();
}
int main()
{
    Vector w1(5);
    for (int i = 0; i < 5; i++)
        w1.Set(i, i * 0.2);
    w1.Show();

    Vector* w2 = new Vector(3);
    for (int i = 0; i < 3; i++)
        w2->Set(i, i * i);
    w2->Show();

    w1.Write("w1.txt");
    w2->ReadIn("w1.txt");
    w2->Show();

    return 0;
}