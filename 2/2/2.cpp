
#include <string>
#include <iostream>
#include <algorithm>

class big_integer {
public:


    big_integer(const std::string s) :str(s) {
        std::cout << "Init" << std::endl;
    }

    // конструктор копирования
    big_integer(const big_integer& s) : str(s.str)
    {
        std::cout << "Копирование" << std::endl;

    }

    big_integer(big_integer&& s) noexcept
    {
        std::cout << "Оператор перемещения" << std::endl;

        str = std::move(s.str);
    }

    //операатор перемещения с присвоением.
    big_integer& operator=(big_integer&& other) noexcept
    {
        if (this == &other) return *this;
        str = std::move(other.str);
        return *this;
    }

    big_integer& operator=(const big_integer& other)
    {
        if (this == &other) return *this;
 //       delete[] & str;
        for (int i = 0; i < other.str.size(); ++i)
        {
            this->str.at(i) = other.str.at(i);
        }
        return *this;
    }
 

    big_integer operator*(const big_integer& bigInt) const {
        if (str == "0" || bigInt.str == "0")
            return *this; 

        std::string value2 = bigInt.str; 

        size_t len1 = str.length(); 
        size_t len2 = value2.length(); 
        size_t length = len1 + len2 + 1; 

        if (length < 10) { 
            long res = stol(str) * stol(value2);
            return *this;
        }
    }


    big_integer operator+(const big_integer& a) {
        int temp = 0;
        std::string num2 = a.str;
        size_t len1 = str.length();
        size_t len2 = num2.length();
        size_t length = std::max(len1, len2);
        char* res = new char[length+1];
        res[length] = res[length - 1] = '\0';
        for (size_t i = 0; i < length; ++i)
        {
            int j = length -1 - i;
            res[j] += 
                ((i < len2) ? 
                (num2[len2 -1 - i] - '0'):
                 0) 
                    +
                ((i < len1) ? 
                    (str[len1 -1 - i] - '0') :
                 0); 
            res[j -1] = res[j] / 10; 
            res[j] = res[j] % 10 + '0'; 
        }
        res[0] += 0;
        str = std::string(res);
        return *this;
    }
    
    ~big_integer()
    {

    }

    friend std::ostream& operator<< (std::ostream& out, const big_integer& point);
private:
    std::string str;
    const long base = 1000000000;
};

std::ostream& operator<< (std::ostream& out, const big_integer& point)
{

    out << "Result = " << point.str;

    return out;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    std::cout << result<< std::endl;
    return  0;
}

