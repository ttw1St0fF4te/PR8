#include <iostream>
#include <string>
#include <windows.h>



int main()
{
    std::string str, symbols;
    std::cout << "Enter the string: ";
    std::cin >> str;
    std::cout << "Enter the symbols to find: ";
    std::cin >> symbols;

    HMODULE library = LoadLibrary(L"Liba.dll");

    typedef bool (*func) (std::string& str, std::string& symbols);
    func Func;

    Func = (func)GetProcAddress(library, "find_symbols");

    bool result = Func(str, symbols);
    std::cout << (result ? "All symbols are found in the string." : "Not all symbols are found in the string.") << std::endl;

    FreeLibrary(library);
    return 0;
}
