#include <fstream>
#include <string>
#include <locale>
#include <codecvt>
#include <map>
#include <vector>
#include <sstream>

std::map<wchar_t,std::wstring> load_trool_alphabet(const std::string &path){

    std::wifstream file(path);

    file.imbue(std::locale(file.getloc(),new std::codecvt_utf8<wchar_t>));

    if (!file.is_open()){return {};}

    std::vector<std::wstring> tokens = {};
    std::wstring token;
    std::wstring line;

    while(std::getline(file, line)){
        std::wstringstream streamer(line);
        while(std::getline(streamer, token,L' ')){

            tokens.push_back(token);
        }
    }

    std::map<wchar_t,std::wstring> ret = {};

    if (tokens.size() % 2 == 0){
        for(unsigned int i = 0 ; i < tokens.size() ; i+=2){
            ret.insert(std::pair<wchar_t,std::wstring>(tokens[i][0],tokens[i+1]));
        }
    }

    return ret;
}

std::wstring troll_the_char(std::map<wchar_t,std::wstring> &alphabet, const wchar_t &_char) {
    if (alphabet.find(_char) != alphabet.end()){
        return alphabet[_char];
    }
    std::wstring ret = L"";
    ret += _char;
    return ret;
}

std::wstring troll_the_text(std::map<wchar_t,std::wstring> &alphabet, const std::wstring &text) {
    std::wstring ret = L"";
    for (wchar_t c : text){
        ret += troll_the_char(alphabet,c);
    }
    return ret;
}
