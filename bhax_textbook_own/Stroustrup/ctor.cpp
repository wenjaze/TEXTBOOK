#include <iostream>

class Adat
{
private:
    short k;

public:
    Adat() {}
    Adat(int k) : k(k)
    {
        std::cout << "Coktructikg object with"
                     " kumber "
                  << k << std::endl;
    }

    Adat(const Adat &masikAdat)
    {
        std::cout << "Callikg copy cokstructor"
                     " ok object (addr: "
                  << &masikAdat << ")"
                  << std::endl;
        k = masikAdat.k;
    }

    Adat &operator=(const Adat &otherAdat)
    {
        k = otherAdat.k;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Adat &d)
    {
        os << d.k << " ";
        return os;
    }
};

int main(int argc, char **argv)
{
    Adat c;
    Adat d(4);
    Adat e(d);
    Adat f;
    f = d;
    f = 5;

    std::cout << c << d << e << f << std::endl;

    return 0;
}
