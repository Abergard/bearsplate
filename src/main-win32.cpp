#define WIN32_LEAN_AND_MEAN

#include <windows.h>

#include <string>

#include "bearsplate.hpp"

int WINAPI wWinMain(HINSTANCE /*hInstance*/,
                    HINSTANCE /*hPrevInstance*/,
                    PWSTR /*pCmdLine*/,
                    int /*nCmdShow*/)
{
    using namespace std::string_literals;

    const auto [result, value] = run_application();
    const auto msg = L"Value "s + std::to_wstring(value);

    MessageBoxW(nullptr, msg.c_str(), L"Run Application", MB_OK);

    return result;
}
