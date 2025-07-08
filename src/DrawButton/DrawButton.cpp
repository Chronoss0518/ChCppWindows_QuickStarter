
#include"../BaseIncluder.h"
#include"../CreateWindow/CreateWindow.h"

#include"DrawButton.h"

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

void DrawButton::Init(HINSTANCE _hIns)
{
	applicationBase.Init(_hIns, APPLICATION_TITLE);

	button.Create(BUTTON_TITLE_NAME,ChINTPOINT(0,0),ChINTPOINT(100,100),applicationBase.GetWindObject());

	button.SetClickFunction([&](HWND _wnd, UINT _uMsg) {

		ChWin::MsgBox messageBox;
		messageBox.AddDisplayButtonType(ChWin::MsgBox::DisplayButtonType::OkCancel);

		messageBox.Display(applicationBase.GetWindObject().GethWnd(), TITLE, TEXT);
	});
}

void DrawButton::Update()
{
	while (applicationBase.IsUpdate())
	{
		button.Update();
	}
}

void DrawButton::Release()
{
	button.Release();

	applicationBase.Release();
}