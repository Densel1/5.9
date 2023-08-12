
#include <iostream>
#include <vector>

template<typename T>
void move_vec(std::vector<T> v1, std::vector<T> &v2)
{
    std::vector<T> tmp(v1);
    std::swap(tmp, v1);
    v2.insert(v2.end(), tmp.begin(), tmp.end());
}


int main()
{
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;
    move_vec(one, two);
    for (auto& c : two)
    {
        std::cout << c << " ";
    }
};
