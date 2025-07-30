#include"../BaseIncluder.h"

#include"CreateWindow.h"

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

void CreateApplicationWindow::Init(HINSTANCE _hIns, const std::string& _appName)
{
    classObject.Init();
    //default��WindProcedure��ChWin::WndProcA�܂���ChWin::WndProcW�ɂȂ�܂�//
    classObject.SetInstance(_hIns);
    classObject.SetBackgroundColor((HBRUSH)GetStockObject(BLACK_BRUSH));
    classObject.SetCursol(LoadCursor(NULL, IDC_ARROW));
    classObject.RegistClass(WIND_CLASS_NAME);

    auto&& windSize = ChWin::GetScreenSize();
    ChWin::WindCreater creater = ChWin::WindCreater(_hIns);
    creater.SetInitSize(windSize);
    ChWin::WindStyle style;
    style.AddOverlappedWindow();
    creater.SetWindStyle(&style);

    creater.Create(windObject, _appName.c_str(), classObject.GetWindClassName());

    //default��WindProcedure�𗘗p����ƁA�ȉ��̂悤�ɕK�v��WindProcedure��ǉ����邱�Ƃ��\�ł�//
    windObject.SetWindProcedure(WM_DESTROY, [&](HWND _hWnd,UINT _uMsg,WPARAM _wParam,LPARAM _lParam)->LRESULT {
        PostQuitMessage(0);
        windObject.Release();
        return 0;
    });
}


void CreateApplicationWindow::Init(HINSTANCE _hIns)
{
    Init(_hIns, APPLICATION_TITLE);
}

void CreateApplicationWindow::Update()
{
    while (windObject.Update()) {}
}

bool CreateApplicationWindow::IsUpdate()
{
    return windObject.Update();
}

void CreateApplicationWindow::Release()
{
    windObject.Release();
    classObject.Release();
}
