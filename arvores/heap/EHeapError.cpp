#include <stdexcept>
#include <string>

class EHeapError : public std::runtime_error {
public:
    EHeapError(const std::string& mensagem)
        : std::runtime_error(mensagem) {}
};