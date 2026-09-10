#include <stdexcept>
#include <string>

class EPilhaVazia : public std::runtime_error {
public:
    EPilhaVazia(const std::string& mensagem)
        : std::runtime_error(mensagem) {}
};