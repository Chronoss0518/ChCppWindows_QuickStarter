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
L"Quick Starter - Draw Text Box";
#else
"Quick Starter - Draw Text Box";
#endif

static constexpr
#ifdef _UNICODE
wchar_t
#else
char
#endif
const* INIT_TEXT_BOX_TEXT =
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
const* BUTTON_TITLE_NAME =
#ifdef _UNICODE
L"Draw TextBox Text";
#else
"Draw TextBox Text";
#endif

static constexpr
#ifdef _UNICODE
wchar_t
#else
char
#endif
const* TITLE =
#ifdef _UNICODE
L"Draw TextBox Text";
#else
"Draw TextBox Text";
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

    //TextBoxのオブジェクトを作成//
    ChWin::TextBox textBox;
    textBox.Create(INIT_TEXT_BOX_TEXT, 0, 0, 180, 100, windObject);

#ifdef _UNICODE
    std::wstring
#else
    std::string
#endif
        text = INIT_TEXT_BOX_TEXT;

    //DrawButtonを参照//
    ChWin::Button button;
    button.Create(BUTTON_TITLE_NAME, ChINTPOINT(180, 0), ChINTPOINT(400, 100), windObject);
    button.SetClickFunction([&](HWND _wnd, UINT _uMsg) {
        ChWin::MsgBox messageBox;
        messageBox.AddDisplayButtonType(ChWin::MsgBox::DisplayButtonType::OkCancel);

        messageBox.Display(windObject.GethWnd(), TITLE, text.c_str());
        });

    while (windObject.Update())
    {
        button.Update();
        textBox.Update();
        //TextBoxからtextを取得//
        text = textBox.GetText();
    }

    button.Release();
    textBox.Release();

    windObject.Release();
    classObject.Release();
    return 0;
};