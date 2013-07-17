#include "Stdafx.h"

namespace CefSharp
{
    namespace Internals
    {
        String^ StringUtils::ToClr(const cef_string_t& cefStr)
        {
            return gcnew String(cefStr.str);
        }

        String^ StringUtils::ToClr(const CefString& cefStr)
        {
            return gcnew String(cefStr.c_str());
        }

        CefString StringUtils::ToNative(String^ str)
        {
            pin_ptr<const wchar_t> pStr = PtrToStringChars(str);
            CefString cefStr(pStr);
            return cefStr;
        }

        void StringUtils::AssignNativeFromClr(cef_string_t& cefStr, String^ str)
        {
            cef_string_clear(&cefStr);

            if (str != nullptr)
            {
                pin_ptr<const wchar_t> pStr = PtrToStringChars(str);
                cef_string_copy(pStr, str->Length, &cefStr);
            }
        }
    }
}