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
L"Quick Starter - CreateWindow";
#else
"Quick Starter - CreateWindow";
#endif

inline int mainFunction(HINSTANCE _hIns)
{
    ChWin::WindClassObject classObject;

    classObject.Init();
    //default��WindProcedure��ChWin::WndProcA�܂���ChWin::WndProcW�ɂȂ�܂�//
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

        //default��WindProcedure�𗘗p����ƁA�ȉ��̂悤�ɕK�v��WindProcedure��ǉ����邱�Ƃ��\�ł�//
        windObject.SetWindProcedure(WM_DESTROY, [&](HWND _hWnd, UINT _uMsg, WPARAM _wParam, LPARAM _lParam)->LRESULT {
            PostQuitMessage(0);
            windObject.Release();
            return 0;
            });
    }

    while (windObject.Update()) {}

    windObject.Release();
    classObject.Release();

    return 0;
}