
#include"../BaseIncluder.h"
#include"../CreateWindow/CreateWindow.h"

#include"DrawFileDialog.h"

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

void DrawFileDialog::Init(HINSTANCE _hIns)
{
	applicationBase.Init(_hIns, APPLICATION_TITLE);

	ChWin::FileDialog fileDialog;
	fileDialog.Init(applicationBase.GetWindObject().GethWnd());
	fileDialog.AddFilter("all", ".*");
	fileDialog.SetTitle(FILE_DIALOG_TITLE);
	fileDialog.OpenFileDialog();
	auto&& tmp = fileDialog.GetFileNameFullPath();

	ChWin::MsgBox messageBox;
	messageBox.AddDisplayButtonType(ChWin::MsgBox::DisplayButtonType::OkCancel);

	messageBox.Display(applicationBase.GetWindObject().GethWnd(), MESSAGE_BOX_TITLE, tmp.c_str());
}

void DrawFileDialog::Update() {}

void DrawFileDialog::Release()
{
	applicationBase.Release();
}