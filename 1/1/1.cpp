
#include <iostream>
#include <vector>

template<typename T>
void move_vec(std::vector<T> &v1, std::vector<T> &v2)
{
      v2 = std::move(v1);
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
