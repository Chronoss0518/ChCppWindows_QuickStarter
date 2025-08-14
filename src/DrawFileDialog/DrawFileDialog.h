#pragma once

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
L"Quick Starter - Draw Message Box";
#else
"Quick Starter - Draw Message Box";
#endif

static constexpr
#ifdef _UNICODE
wchar_t
#else
char
#endif
const* FILE_DIALOG_TITLE =
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
const* MESSAGE_BOX_TITLE =
#ifdef _UNICODE
L"Test";
#else
"Test";
#endif


int mainFunction(HINSTANCE _hIns)
{
    //"CreateWindow.h"ÇéQçlÇ…ÇµÇƒÇ≠ÇæÇ≥Ç¢//
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

    //âÊëúÇçÏê¨//
    ChWin::FileDialog fileDialog;
    fileDialog.Init(windObject.GethWnd());
    fileDialog.AddFilter("all", ".*");
    fileDialog.SetTitle(FILE_DIALOG_TITLE);
    fileDialog.OpenFileDialog();
    auto&& tmp = fileDialog.GetFileNameFullPath();

    ChWin::MsgBox messageBox;
    messageBox.AddDisplayButtonType(ChWin::MsgBox::DisplayButtonType::OkCancel);
    messageBox.Display(windObject.GethWnd(), MESSAGE_BOX_TITLE, tmp.c_str());

    windObject.Release();
    classObject.Release();
}
