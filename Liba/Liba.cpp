#include <string>

extern "C" __declspec(dllexport) bool find_symbols(const std::string & str, const std::string & symbols) {
    for (char symbol : symbols) {
        if (str.find(symbol) == std::string::npos) {
            return false;
        }
    }
    return true;
}