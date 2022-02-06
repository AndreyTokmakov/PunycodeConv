#pragma once

#include <string>

namespace Punycode
{
    [[nodiscard]]
    std::string punycodeDecode(const std::string & input);

    [[nodiscard]]
    std::string punycodeEncode(const std::string & input);
}
