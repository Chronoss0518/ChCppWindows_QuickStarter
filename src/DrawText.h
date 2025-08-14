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
const* TEXT =
#ifdef _UNICODE
L"TestText";
#else
"TestText";
#endif

int mainFunction(HINSTANCE _hIns)
{
    //"CreateWindow.h"‚ğQl‚É‚µ‚Ä‚­‚¾‚³‚¢//
    ChWin::WindClassObject classObject;

    classObject.Init();
    classObject.SetInstance(_hIns);
    classObject.SetBackgroundColor((HBRUSH)GetStockObject(BLACK_BRUSH));
    classObject.SetCursol(LoadCursor(NULL, IDC_ARROW));
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

    //TextDrawer‚ğ‰Šú‰»//
    ChWin::TextDrawer().Init(windObject.GethWnd());
    ChWin::TextDrawer().SetFontColor(ChVec4(1.0f, 1.0f, 1.0f, 1.0f));

    while (windObject.Update())
    {
        auto&& dc = windObject.DrawStart();

        //Text‚ğ•`‰æ//
        ChWin::TextDrawer().Draw(dc, TEXT, 0, 0);

        windObject.DrawEnd(dc);
    }

    //TextDrawer‚ğ‰ğ•ú//
    ChWin::TextDrawer().Release();

    windObject.Release();
    classObject.Release();
    return 0;
}
