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
#define SAVEFILE  "save"
#define INITFILE    "init"
#define STORYFILE "story"
#define EVENTFILE "event"
#define GIFTFILE "gift"
#define ACTIONEYEFILE "actioneye"
#define ACTIONBODYFILE "actionbody"
#elif defined(VS)
#include <windows.h>
#include <string>
#define SAVEFILE "save"
#define INITFILE    "init"
std::wstring UTF8ToUnicode(const std::string& str);
std::string UnicodeToANSI(const std::wstring& str);
#endif
#define TEXT_SIZE 255
#define MSG_LEISUREENTER "leisureenter"
#define MSG_LEISUREUPDATE "leisureupdate"
#define MSG_LEISUREEXIT "leisureexit"
#define MSG_SLEEPENTER "sleepenter"
#define MSG_SLEEPUPDATE "sleepupdate"
#define MSG_SLEEPEXIT "sleepexit"
#define MSG_WORKENTER "workenter"
#define MSG_WORKUPDATE "workupdate"
#define MSG_WORKEXIT "workexit"

#endif /* defined(__Core__Constant__) */
