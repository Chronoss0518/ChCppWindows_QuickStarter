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
L"Quick Starter - Draw Text";
#else
"Quick Starter - Draw Text";
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
    //"CreateWindow.h"���Q�l�ɂ��Ă�������//
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

    //TextDrawer��������//
    ChWin::TextDrawer().Init(windObject.GethWnd());
    //�t�H���g�̐F�w��//
    ChWin::TextDrawer().SetFontColor(ChVec4(1.0f, 1.0f, 1.0f, 1.0f));
    //�t�H���g�T�C�Y�̒���(�Ō��false�̓A���_�[���C�������邩�̎w��)//
    ChWin::TextDrawer().SetFontData(32, 64, 64, false);

    while (windObject.Update())
    {
        auto&& dc = windObject.DrawStart();

        //Text��`��//
        ChWin::TextDrawer().Draw(dc, TEXT, 0, 0);

        windObject.DrawEnd(dc);
    }

    //TextDrawer�����//
    ChWin::TextDrawer().Release();

    windObject.Release();
    classObject.Release();
    return 0;
}
