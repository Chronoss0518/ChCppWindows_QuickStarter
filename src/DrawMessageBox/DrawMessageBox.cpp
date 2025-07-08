
#include"../BaseIncluder.h"
#include"../CreateWindow/CreateWindow.h"

#include"DrawMessageBox.h"

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

void DrawMessageBox::Init(HINSTANCE _hIns)
{
	applicationBase.Init(_hIns, APPLICATION_TITLE);

	ChWin::MsgBox messageBox;
	messageBox.AddDisplayButtonType(ChWin::MsgBox::DisplayButtonType::OkCancel);

	messageBox.Display(applicationBase.GetWindObject().GethWnd(),TITLE,TEXT);
}

void DrawMessageBox::Update(){}

void DrawMessageBox::Release()
{
	applicationBase.Release();
}