
#include <iostream>
#include <vector>

#include "Punycode.h"

int main([[maybe_unused]] int argc,
         [[maybe_unused]] char** argv)
{
    std::vector<std::pair<std::string, std::string>> values{
            {"https://привет.label.мир.com/", "https://xn--b1agh1afp.label.xn--h1ahn.com/"},
            {"點看", "xn--c1yn36f"},
            {"abæcdöef", "xn--abcdef-qua4k"},
            {"abcdef", "abcdef"},
            {"αβγ", "xn--mxacd"},
            {"ยจฆฟคฏข", "xn--22cdfh1b8fsa"},
            {"правда", "xn--80aafi6cg"},
            {"Bahnhof München-Ost", "xn--Bahnhof Mnchen-Ost-u6b"},
            {"-> $1.00 <-", "-> $1.00 <-"},
            {"ドメイン名例", "xn--eckwd4c7cu47r2wf"},
            {"MajiでKoiする5秒前", "xn--MajiKoi5-783gue6qz075azm5e"},
            {"「bücher」", "xn--bcher-kva8445foa"},
            {"https://google.com/", "https://google.com/"},
    };

    for (const auto & [nameExpected, encodedExpected]: values) {
        const std::string encodedString = Punycode::punycodeEncode(nameExpected);
        if (encodedString != encodedExpected) {
            std::cout << "ERROR! Expected: " << encodedExpected << ", Actual: " << encodedString << std::endl;
            continue;
        }
        // else std::cout << "OK:" << encodedExpected << std::endl;

        const std::string decodedString = Punycode::punycodeDecode(encodedString);
        if (decodedString != nameExpected) {
            std::cout << "ERROR! Expected: " << nameExpected << ", Actual: " << decodedString << std::endl;
            continue;
        }
        //else std::cout << "OK:" << nameExpected << std::endl;
    }
}
