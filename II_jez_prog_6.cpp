#include <iostream>
#include <string.h>
using namespace std;

class mystring
{
private:
    char *ch;
    int n;

public:
    mystring()
    {
        ch = 0;
        n = 0;
    }
    mystring(const char *chin);
    ~mystring()
    {
        if (ch != 0)
            delete[] ch;
    }
    void Set(const char *chin);
    int GetN() { return n; }
    friend ostream &operator<<(ostream &osin, mystring &strin);
    char &operator[](int i) { return ch[i]; }

    mystring &operator=(mystring &strin);
    mystring &operator+=(mystring &strin);
    mystring &operator+(mystring &strin);
    mystring(mystring &strin);
};

void mystring::Set(const char *chin)
{
    if (ch)
    {
        delete[] ch;
    }
    int l = strlen(chin);
    n = l;
    ch = new char[l + 1];
    strcpy(ch, chin);
}

mystring::mystring(const char *chin)
{
    ch = 0;
    Set(chin);
}

mystring &mystring::operator+=(mystring &strin)
{
    char *chtmp = new char[n + strin.n + 1];
    for (int i = 0; i < n; i++)
        chtmp[i] = ch[i];
    for (int i = 0; i < strin.n; i++)
        chtmp[i + n] = strin.ch[i];
    chtmp[n + strin.n] = 0;

    delete[] chtmp;
    ch = chtmp;
    n += strin.n;

    return *this;
}

mystring &mystring::operator=(mystring &strin)
{
    if (&strin == this)
        return *this;

    Set(strin.ch);
    // n = strin.n;
    return *this;
}

mystring &mystring::operator+(mystring &strin)
{
    mystring *newstr = new mystring(ch);
    (*newstr) += strin;
    return *newstr;
}

ostream &operator<<(ostream &osin, mystring &strin)
{
    osin << strin.ch;
    return osin;
}
istream &operator>>(istream &isin, mystring &strin)
{
    char tab[256];
    isin.getline(tab, 256);
    strin.Set(tab);
    return isin;
}

mystring::mystring(mystring &strin)
{
    ch = 0;
    Set(strin.ch);
}

int count_ch(mystring strin, char chin)
{
    int k = 0;
    for (int i = 0; i < strin.GetN(); i++)
    {
        if (strin[i] == chin)
            k++;
    }
    return k;
}

int main()
{
    mystring str1;
    str1.Set("Ala ma");
    mystring str2("kota");
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    str1 += str2;
    cout << "str1 += str2: " << str1 << endl;
    cout << "str1[0]: " << str1[0] << endl;
    str1[0] = 'E';
    cout << "A ==> E: " << str1 << endl;
    cout << "str1 + str2: " << str1 + str2 << endl;

    mystring str3 = str1 + str2;
    cout << str3 << endl;
    mystring *str4 = new mystring("Kasia");
    mystring str5 = (*str4);
    str5[0] = 'B';
    cout << "str4: " << *str4 << endl;
    cout << "str5: " << str5 << endl;

    int ilea = count_ch(str5, 'a');
    cout << "How many a's in str5: " << ilea << endl;

    mystring str6;
    cout << "str6: ";
    cin >> str6;
    cout << str6;
    
    return 0;
}