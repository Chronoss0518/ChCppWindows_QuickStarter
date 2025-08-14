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
    //defaultのWindProcedureはChWin::WndProcAまたはChWin::WndProcWになります//
    classObject.SetInstance(_hIns);
    //WindClassの作成時に必要なパラメータをセット//
    classObject.SetBackgroundColor((HBRUSH)GetStockObject(BLACK_BRUSH));
    classObject.SetCursol(LoadCursor(NULL, IDC_ARROW));
    //WindClassを登録//
    classObject.RegistClass(WIND_CLASS_NAME);

    ChWin::WindObject windObject;
    {
        //画面サイズを取得//
        auto&& windSize = ChWin::GetScreenSize();

        //Windを作成するクラスを用意//
        ChWin::WindCreater creater = ChWin::WindCreater(_hIns);
        creater.SetInitSize(windSize);
        //WindStyleを構築するためのクラスを準備//
        ChWin::WindStyle style;
        //ここではWS_OVERLAPPEDWINDOWを追加//
        style.AddOverlappedWindow();

        //用意したWindStyleをセット//
        creater.SetWindStyle(&style);

        //Windを作成//
        creater.Create(windObject, APPLICATION_TITLE, classObject.GetWindClassName());

        //defaultのWindProcedureを利用すると、以下のように必要なWindProcedureを追加することが可能//
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