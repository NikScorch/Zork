#ifndef OUTOFBOUNDSEXCEPTION_H
#define OUTOFBOUNDSEXCEPTION_H

#include <stdexcept>
#include <string>

class OutOfBoundsException : public std::runtime_error {

public:
    OutOfBoundsException(const std::string& message)
        : std::runtime_error(message) {}
};

#endif // OUTOFBOUNDSEXCEPTION_H
