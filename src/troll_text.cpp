#include <iostream>
#include <locale>
#include <codecvt>
#include "troll_the_text.h"

int main(int argc, char *argv[])
{

    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> wstring_convert;

    std::wstring text = L"";

    std::map<wchar_t, std::wstring> custom_dictionary = {};

    if (argc > 2)
    {

        custom_dictionary = load_trool_alphabet(argv[1]);

        std::string s(argv[2]);
        text = wstring_convert.from_bytes(s);

        std::wstring trolled = troll_the_text(custom_dictionary, text);
        printf("%s\n", wstring_convert.to_bytes(trolled).c_str());
        return 0;
    }

    printf("how use:\n");
    printf("    arg 1 is for the key replacement file\n");
    printf("    arg 2 is for the text\n");
    printf("example:\n");
    printf("    ./troll_text './example.txt' 'hello world'\n");

    return 0;
}