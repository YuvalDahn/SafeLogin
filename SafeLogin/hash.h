#pragma once

#include <openssl/sha.h>
#include <iostream>
#include <iomanip>
#include <sstream>

std::string sha256(const std::string str);
