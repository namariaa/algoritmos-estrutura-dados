#include <stdexcept>
#include <string>

class EDequeError : public std::runtime_error {
public:
    EDequeError(const std::string& mensagem)
        : std::runtime_error(mensagem) {}
};