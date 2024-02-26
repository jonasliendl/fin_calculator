//
// Created by Jonas Liendl on 26.02.24.
//
#include "Exception.h"

const char *Exception::what() const noexcept {
    return message.c_str();
}

