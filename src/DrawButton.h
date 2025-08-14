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
L"Quick Starter - DrawButton";
#else
"Quick Starter - DrawButton";
#endif

static constexpr
#ifdef _UNICODE
wchar_t
#else
char
#endif
const* BUTTON_TITLE_NAME =
#ifdef _UNICODE
L"Test";
#else
"Test";
#endif

static constexpr
#ifdef _UNICODE
wchar_t
#else
char
#endif
const* TITLE =
#ifdef _UNICODE
L"Test";
#else
"Test";
#endif

static constexpr
#ifdef _UNICODE
wchar_t
#else
char
#endif
const* TEXT =
#ifdef _UNICODE
L"Open Message Box";
#else
"Open Message Box";
#endif


int mainFunction(HINSTANCE _hIns)
{
    //"CreateWindow.h"を参考にしてください//
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

    //Buttonオブジェクトの作成//
    ChWin::Button button;
    button.Create(BUTTON_TITLE_NAME, ChINTPOINT(0, 0), ChINTPOINT(100, 100), windObject);
    //Buttonオブジェクトのクリック時動作の作成//
    button.SetClickFunction([&](HWND _wnd, UINT _uMsg) {
        ChWin::MsgBox messageBox;
        messageBox.AddDisplayButtonType(ChWin::MsgBox::DisplayButtonType::OkCancel);

        messageBox.Display(windObject.GethWnd(), TITLE, TEXT);
        });

    while (windObject.Update())
    {
        button.Update();
    }

    button.Release();

    windObject.Release();
    classObject.Release();
    return 0;
};