#include <stdexcept>
#include <string>

class EFilaError : public std::runtime_error {
public:
    EFilaError(const std::string& mensagem)
        : std::runtime_error(mensagem) {}
};