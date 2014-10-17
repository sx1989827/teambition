//
//  Constant.h
//  Core
//
//  Created by 孙昕 on 14-10-13.
//
//

#ifndef __Core__Constant__
#define __Core__Constant__
#ifdef XCODE
#define SAVEFILE  "data.txt"
#elif defined(VS)
#include <windows.h>
#include <string>
#define SAVEFILE "data.txt"
std::wstring UTF8ToUnicode(const std::string& str);
std::string UnicodeToANSI(const std::wstring& str);
#endif
#define TEXT_SIZE 255

#endif /* defined(__Core__Constant__) */
