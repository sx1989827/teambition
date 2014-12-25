//
//  Constant.cpp
//  Core
//
//  Created by 孙昕 on 14-10-13.
//
//

#include "Constant.h"

#if XCODE
#import <UIKit/UIKit.h>
std::string GetCurrentDataDir()
{
    NSString *imgPath=[[NSBundle mainBundle] pathForResource:@"Data" ofType:@"bundle"];
    std::string strPath=[imgPath UTF8String];
    strPath+="/";
    return strPath;
}
#elif deined(VS)
void StringReplace(std::string&s1, const std::string&s2, const std::string&s3)
{
	std::string::size_type pos = 0;
	std::string::size_type a = s2.size();
	std::string::size_type b = s3.size();
	while ((pos = s1.find(s2, pos)) != std::string::npos)
	{
		s1.replace(pos, a, s3);
		pos += b;
	}
}
std::wstring UTF8ToUnicode(const std::string& str)
{
//	StringReplace((std::string&)str, "\x3f", "\x20");
	int len = str.length();
	int unicodeLen = ::MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
	wchar_t * pUnicode;
	pUnicode = new wchar_t[unicodeLen + 1];
	memset(pUnicode, 0, (unicodeLen + 1)*sizeof(wchar_t));
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, (LPWSTR)pUnicode, unicodeLen);
	std::wstring rt = (wchar_t*)pUnicode;
	delete[] pUnicode;
	return rt;
}

std::string UnicodeToANSI(const std::wstring& str)
{
	char* pElementText;
	int iTextLen;
	iTextLen = WideCharToMultiByte(CP_ACP, 0, str.c_str(), -1, NULL, 0, NULL, NULL);
	pElementText = new char[iTextLen + 1];
	memset((void*)pElementText, 0, sizeof(char) * (iTextLen + 1));
	WideCharToMultiByte(CP_ACP, 0, str.c_str(), -1, pElementText, iTextLen, NULL, NULL);
	std::string strText = pElementText;
	delete[] pElementText;
	return strText;
}
#endif