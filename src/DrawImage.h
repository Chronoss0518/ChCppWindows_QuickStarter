#pragma once
#include"main.h"

static constexpr
#ifdef _UNICODE
wchar_t
#else
char
#endif
const* WIND_CLASS_NAME =
#ifdef _UNICODE
L"SampleApplication";
#else
"SampleApplication";
#endif

static constexpr
#ifdef _UNICODE
wchar_t
#else
char
#endif
const* APPLICATION_TITLE =
#ifdef _UNICODE
L"Quick Starter - DrawTexture";
#else
"Quick Starter - DrawTexture";
#endif

static constexpr
#ifdef _UNICODE
wchar_t
#else
char
#endif
const* TEXTURE_FILE_NAME =
#ifdef _UNICODE
L"Test.bmp";
#else
"Test.bmp";
#endif

int mainFunction(HINSTANCE _hIns)
{
    //"CreateWindow.h"‚ğQl‚É‚µ‚Ä‚­‚¾‚³‚¢//
    ChWin::WindClassObject classObject;

    classObject.Init();
    classObject.SetInstance(_hIns);
    classObject.RegistClass(WIND_CLASS_NAME);

    ChWin::WindObject windObject;
    {
        auto&& windSize = ChWin::GetScreenSize();
        ChWin::WindCreater creater = ChWin::WindCreater(_hIns);
        creater.SetInitSize(windSize);
        ChWin::WindStyle style;
        style.AddOverlappedWindow();
        creater.SetWindStyle(&style);


        creater.Create(windObject, APPLICATION_TITLE, classObject.GetWindClassName());

        windObject.SetWindProcedure(WM_DESTROY, [&](HWND _hWnd, UINT _uMsg, WPARAM _wParam, LPARAM _lParam)->LRESULT {
            PostQuitMessage(0);
            windObject.Release();
            return 0;
            });
    }

    //‰æ‘œ‚ğì¬//
    ChWin::Texture texture;

    texture.CreateTexture(_hIns, TEXTURE_FILE_NAME);

    while (windObject.Update())
    {
        auto&& dc = windObject.DrawStart();

        auto&& size = texture.GetTextureSize();
        //‰æ‘œ‚ğ0,0ˆÊ’u‚É•`‰æ//
        texture.Draw(dc, 0, 0, size.w, size.h);

        windObject.DrawEnd(dc);
    }

    texture.Release();

    windObject.Release();
    classObject.Release();
    return 0;
}
