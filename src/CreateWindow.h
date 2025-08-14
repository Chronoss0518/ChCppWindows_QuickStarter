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
    //WindClass�̍쐬���ɕK�v�ȃp�����[�^���Z�b�g//
    classObject.SetBackgroundColor((HBRUSH)GetStockObject(BLACK_BRUSH));
    classObject.SetCursol(LoadCursor(NULL, IDC_ARROW));
    //WindClass��o�^//
    classObject.RegistClass(WIND_CLASS_NAME);

    ChWin::WindObject windObject;
    {
        //��ʃT�C�Y���擾//
        auto&& windSize = ChWin::GetScreenSize();

        //Wind���쐬����N���X��p��//
        ChWin::WindCreater creater = ChWin::WindCreater(_hIns);
        creater.SetInitSize(windSize);
        //WindStyle���\�z���邽�߂̃N���X������//
        ChWin::WindStyle style;
        //�����ł�WS_OVERLAPPEDWINDOW��ǉ�//
        style.AddOverlappedWindow();

        //�p�ӂ���WindStyle���Z�b�g//
        creater.SetWindStyle(&style);

        //Wind���쐬//
        creater.Create(windObject, APPLICATION_TITLE, classObject.GetWindClassName());

        //default��WindProcedure�𗘗p����ƁA�ȉ��̂悤�ɕK�v��WindProcedure��ǉ����邱�Ƃ��\//
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