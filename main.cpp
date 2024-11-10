#include <iostream>
#include <string>

bool IsKPeriodic(const std::string& str, int K)
{
    int n = str.size(); // Получаем размер строки для проверки

    // Проверка на 0 и деление без остатка
    if(K <= 0 || n % K != 0)
    {
        std::cerr << "Error: K cannot be zero" << std::endl;
        return false;
    }

    // Получение первой подстроки
    std::string podstr = str.substr(0, K);

    for (int i = K; i < n; i += K)
    {
        // Проверяем подстроку с шаблоном
        if (str.substr(i, K) != podstr)
        {
            return false;
        }
    }

    // Если все совпадает, то значит строка кратна K
    return true;
}

int main()
{
    std::string test = "abcabcabc";
    IsKPeriodic(test, 3);
    if (IsKPeriodic(test, 3))
    {
        std::cout << "True" << std::endl;
    }
    else{
        std::cout << "False" << std::endl;
    }
    
}