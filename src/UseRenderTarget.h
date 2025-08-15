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
L"Quick Starter - Use Render Target";
#else
"Quick Starter - Use Render Target";
#endif

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

    auto&& windSize = ChWin::GetScreenSize();
    ChWin::WindObject windObject;
    {
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

    //DrawImage���Q��//
    ChWin::Texture texture;

    texture.CreateTexture(_hIns, TEXTURE_FILE_NAME);

    //DrawText���Q��//
    ChWin::TextDrawer().Init(windObject.GethWnd());
    ChWin::TextDrawer().SetFontColor(ChVec4(1.0f, 1.0f, 1.0f, 1.0f));
    ChWin::TextDrawer().SetFontData(32,64,64,false);

    //�_�u���o�b�t�@�̊�{�̃����_�[�^�[�Q�b�g���쐬//
    ChWin::RenderTarget renderTarget;

    renderTarget.SetBKColor(WHITE_BRUSH);


    while (windObject.Update())
    {

        auto&& dc = windObject.DrawStart();


        auto&& size = texture.GetTextureSize();

        renderTarget.CreateRenderTarget(dc, ChINTPOINT(size.w * 2, size.h * 2));

        //HDC��RenderTarget�̕ێ�����HDC�ɐݒ�//
        texture.Draw(renderTarget.GetRenderTarget(), 0, 0, size.w, size.h);
        texture.Draw(renderTarget.GetRenderTarget(), size.w, size.h, size.w, size.h);

        //HDC��RenderTarget�̕ێ�����HDC�ɐݒ�//
        ChWin::TextDrawer().Draw(renderTarget.GetRenderTarget(), TEXT, size.w, 0);

        //�摜����ʃT�C�Y�ɂ��ĕ`��//
        renderTarget.DrawStretch(dc, ChINTPOINT(0, 0), windSize, ChINTPOINT(0, 0), ChINTPOINT(size.w * 2, size.h * 2));

        windObject.DrawEnd(dc);
    }

    texture.Release();

    windObject.Release();
    classObject.Release();
    return 0;
}
