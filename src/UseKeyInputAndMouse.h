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
L"Quick Starter - Use KeyInput And Mouse";
#else
"Quick Starter - Use KeyInput And Mouse";
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

    ChCpp::FPSController fps;
    fps.SetFPS(60);

    //DrawTextを参考//
    ChWin::TextDrawer().Init(windObject.GethWnd());
    ChWin::TextDrawer().SetFontColor(ChVec4(1.0f, 1.0f, 1.0f, 1.0f));
    ChWin::TextDrawer().SetFontData(32, 64, 64, false);

    //Mouseを初期化//
    ChWin::Mouse().Init(windObject);

    //KeyInputを管理するクラスを用意//
    ChWin::WinKeyInput keyInput;

    while (windObject.Update())
    {
        keyInput.Update();
        ChWin::Mouse().Update();
        if (!fps.Update(timeGetTime()))continue;

        //Escape Keyを入力すると終了メッセージが送られるようにする//
        if (keyInput.IsPushKey(VK_ESCAPE)) {
            PostQuitMessage(0);
            continue;
        }

        auto&& mousePos = ChWin::Mouse().GetNowPos();

        auto&& dc = windObject.DrawStart();

        //マウスの位置にTEXTを表示
        ChWin::TextDrawer().Draw(dc, TEXT, mousePos.x, mousePos.y);

        windObject.DrawEnd(dc);
    }

    ChWin::TextDrawer().Release();

    windObject.Release();
    classObject.Release();
    return 0;
}
