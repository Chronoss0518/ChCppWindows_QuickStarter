
#include"../BaseIncluder.h"
#include"../CreateWindow/CreateWindow.h"

#include"DrawImage.h"

static constexpr
#ifdef _UNICODE
wchar_t
#else
char
#endif
const* TEXTURE_FILE_NAME =
#ifdef _UNICODE
L"Test.bmp";
#else
"Test.bmp";
#endif

static constexpr
#ifdef _UNICODE
wchar_t
#else
char
#endif
const* APPLICATION_TITLE =
#ifdef _UNICODE
L"Quick Starter - DrawTexture";
#else
"Quick Starter - DrawTexture";
#endif

void DrawImage::Init(HINSTANCE _hIns)
{
	applicationBase.Init(_hIns, "DrawTexture");

	texture.CreateTexture(_hIns, TEXTURE_FILE_NAME);
}

void DrawImage::Update()
{
	while (applicationBase.IsUpdate())
	{
		auto&& dc = applicationBase.GetWindObject().DrawStart();

		auto&& size = texture.GetTextureSize();
		texture.Draw(dc, 0, 0, size.w, size.h);

		applicationBase.GetWindObject().DrawEnd(dc);
	}
}

void DrawImage::Release()
{
	texture.Release();

	applicationBase.Release();
}