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
