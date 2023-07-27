#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

class Person
{
private:
    char* name;
    char* surname;
    long long pesel;

public:
    void SetName(const char* namein)
    {
        if (name != 0)
            delete[] name;
        int n = strlen(namein);
        char* name = new char[n + 1];
        strcpy(name, namein);
    }
    void SetSurname(const char* surnamein)
    {
        if (surname != 0)
            delete[] surname;
        int n = strlen(surnamein);
        char* surname = new char[n + 1];
        strcpy(surname, surnamein);
    }
    Person()
    {
        name = 0;
        SetName(" ");
        surname = 0;
        SetSurname(" ");
        pesel = 0;
    }
    Person(const char* namein, const char* surnamein, long long peselin)
    {
        name = 0;
        SetName(namein);
        surname = 0;
        SetSurname(surnamein);
        pesel = peselin;
    }
    ~Person()
    {
        delete[] name;
        delete[] surname;
    }
    void SetPesel(long long peselin) { pesel = peselin; }

    int GetYear()
    {
        int year = (pesel / 1000000000ll) + 1900;
        int century = ((pesel / 10000000ll) % 100) / 20;
        if (century <= 3)
            year += century * 100;
        if (century == 4)
            year -= 100;
        return year;
    }
    int GetMonth()
    {
        return (((pesel / 10000000) % 100) % 20);
    }
    int GetDay()
    {
        return (pesel / 100000) % 100;
    }
    bool IsMen()
    {
        int temp = (pesel % 100) / 10;
        return (temp % 2);
    }
    static int GetControlValue(long long peselin)
    {
        peselin /= 10;
        int sum = 3 * (peselin % 10);
        peselin /= 10;
        sum += 1 * (peselin % 10);
        peselin /= 10;
        for (int i = 0; i < 2; i++)
        {
            sum += 9 * (peselin % 10);
            peselin /= 10;
            sum += 7 * (peselin % 10);
            peselin /= 10;
            sum += 3 * (peselin % 10);
            peselin /= 10;
            sum += 1 * (peselin % 10);
            peselin /= 10;
        }
        return ((10 - (sum % 10)) % 10);
    }
    bool IsCorrect()
    {
        if (pesel % 10 == GetControlValue(pesel))
            return 1;
        return 0;
    }
    void ShowAll();
};

void Person::ShowAll()
{
    cout << "Name and Surname: " << name << " " << surname << endl;
    cout << "Pesel: " << pesel << " " << (IsCorrect() ? "Correct" : "Incorrect") << endl;
    cout << (IsMen() ? "Man" : "Woman") << endl;
    cout << GetYear() << "-" << GetMonth() << "-" << GetDay() << endl;
}

int main()
{
    cout << "Number of bits in int: " << (8 * sizeof(int)) - 1 << endl;
    cout << "Number of bits in long: " << (8 * sizeof(long)) - 1 << endl;
    cout << "Number of bits in long long: " << (8 * sizeof(long long)) - 1 << endl;
    cout << "Number of needed bits: " << log(1e11 - 1) / log(2) << endl;

    Person os1 = Person("Jan", "Kowalski", 44051401359);
    os1.ShowAll();
    Person* os2 = new Person();

    char tab[256];
    cout << "Name: ";
    cin >> tab;
    os2->SetName(tab);
    cout << endl;
    cout << "Surname: ";
    cin >> tab;
    os2->SetSurname(tab);
    cout << endl;
    long long peselin;
    cout << "Pesel: ";
    cin >> peselin;
    os2->SetPesel(peselin);

    os2->ShowAll();
    return 0;
}
