#include <iostream>
#include <fstream>

using namespace std;

class Stuff
{
private:
    float price;
    string stname;

public:
    Stuff(float pricein = 0., string stnamein = " ") : price(pricein), stname(stnamein) {}
    void SetPrice(float pricein) { price = pricein; }
    void SetName(string stnamein) { stname = stnamein; }
    float GetPrice() { return price; }
    string GetName() { return stname; }
    Stuff &operator+=(float deltaprice)
    {
        price += deltaprice;
        return *this;
    }
    friend ostream &operator<<(ostream &osin, Stuff &stin);
    bool operator>(Stuff &stin)
    {
        return (this->price > stin.price);
    }
};

Stuff &operator-=(Stuff &stin, float deltaprice)
{
    stin.SetPrice(stin.GetPrice() - deltaprice);
    return stin;
}
ostream &operator<<(ostream &osin, Stuff &stin)
{
    osin << stin.stname << ": " << stin.price;
    return osin;
}
bool operator<(Stuff &stin1, Stuff &stin2)
{
    return (stin1.GetPrice() < stin2.GetPrice());
}
void Store()
{
    int n;
    cout << "Number of items: ";
    cin >> n;
    Stuff *items = new Stuff[n];
    float x;
    string name;
    for (int i = 0; i < n; i++)
    {
        cout << "Stuff's name: ";
        cin >> name;
        cout << "Stuff's price: ";
        cin >> x;
        items[i].SetName(name);
        items[i].SetPrice(x);
    }
    for (int i = 0; i < n; i++)
    {
        cout << items[i] << endl;
    }
    ofstream file;
    file.open("store.txt");
    for (int i = 0; i < n; i++)
    {
        file << items[i] << endl;
    }
    file.close();
}

int main()
{
    Stuff potato(10.5, "potato");
    cout << "Base price: " << potato.GetPrice() << endl;
    potato += 3.0;
    cout << "Price after raise: " << potato.GetPrice() << endl;

    potato -= 5.0;
    cout << "Price after discount: " << potato.GetPrice() << endl;
    cout << potato << endl;

    Stuff kiwi(11.0, "kiwi");
    if(kiwi > potato)
        cout << "Kiwi is more expensive" << endl;
    if(kiwi < potato)
        cout << "Potato is more expensive" << endl;

    Store();
    
    return 0;
}