#include <iostream>
#include <cstring>

class String
{
public:
    String() : str(nullptr), len(0)
    {
        std::cout << "Default const" << std::endl;
    }
    String(const char *ch)
    {
        len = strlen(ch);
        std::cout << "Len : " << len << std::endl;
        str = new char[len + 1];
        strcpy(str, ch);
        std::cout << "Parameter " << str << std::endl;
    }

    String(const String &Obj)
    {
        if (Obj.str)
        {
            len = Obj.len;
            str = new char[len + 1];
            strcpy(str, Obj.str);
        }
        else
        {
            len = 0;
            str = nullptr;
        }
        std::cout << "Len : " << len << std::endl;
        std::cout << "Copy " << (str ? str : "(null)") << std::endl;
    }

    String &operator=(const String &Obj)
    {
        std::cout << "THis : " << this << std::endl;
        std::cout << " &Obj : " << &Obj << std::endl;

        if (this != &Obj)
        {
            delete[] str;
            if (Obj.str)
            {
                len = Obj.len;
                str = new char[len + 1];
                strcpy(str, Obj.str);
            }
            else
            {
                len = 0;
                str = nullptr;
            }
            std::cout << "Len : " << len << std::endl;
            std::cout << "Assignment " << (str ? str : "(null)") << std::endl;
        }
        return *this;
    }
    int lenght()
    {
        return len;
    }

    ~String()
    {
        if (str)
        {
            delete[] str;
            len = 0;
            str = nullptr;
            std::cout << "destr" << std::endl;
        }
    }

    String(String&& obj)
    {
        str = obj.str;
        len = obj.len;
        obj.len = 0;
        obj.str = nullptr;
        std::cout << "Move constLen : " << len << std::endl;
        std::cout << "move Copy const" << str << std::endl;
    }
    String &operator=(String &&obj)
    {
        if (this != &obj)
        {
            delete[] str;  // for ensuring we will nt leak memory
            str = obj.str;
            len = obj.len;
            obj.len = 0;
            obj.str = nullptr;
            std::cout << "Move Assignment : " << len << std::endl;
            std::cout << "move Copy Assignment " << str << std::endl;
        }
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, String &obj);
    friend std::istream &operator>>(std::istream &os, String &obj);

private:
    char *str;
    int len;
};

std::ostream &operator<<(std::ostream &os, String &obj)
{
    if (obj.str)
    {
        os << obj.str;
    }

    else
    {
        os << "nullpt";
    }
    return os;
}
std::istream &operator>>(std::istream &is, String &obj)
{
    char b[100];
    is >> b;
    delete[] obj.str;
    obj.len = strlen(b);
    obj.str = new char[obj.len + 1];
    strcpy(obj.str, b);
    return is;
}

int main()
{
    String Str1;          // default constr
    String Str2 = "Rama"; // Parameterized constr , wokred bcz of implicite conversion
    String Str3 = Str2;   // Copy constructor

    // std::cout<<"Str1 : "<<Str1<<std::endl;
    // std::cout<<"Str2 : "<<Str2<<std::endl;
    Str1 = Str2; // Copy asignement

    int len = Str2.lenght();
    std::cout << "Lentht : " << len << std::endl;

    std::cout << Str2;
    std::cin >> Str1;

    String Str4(Str2); // copy constr
    // //copy and swap indiams CAS
    String Str5 = std::move(Str2); // str2 will get die after this
    Str2 = std::move(Str4);        // Str4 dead

    return 0;
}