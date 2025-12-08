#pragma once

#include <string>
#include <map>

std::map<wchar_t,std::wstring> load_trool_alphabet(const std::string &path);

std::wstring troll_the_char(std::map<wchar_t,std::wstring> &alphabet, const wchar_t &_char);

std::wstring troll_the_text(std::map<wchar_t,std::wstring> &replacement, const std::wstring &text);