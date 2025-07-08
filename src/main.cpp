#include"BaseIncluder.h"
#include"CreateWindow/CreateWindow.h"

#include"DrawImage/DrawImage.h"

//挙動を確認したい項目の#ifまたは#elifの値のみを1に変更してください//

int WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    int       nShowCmd)
{
#if 0
    // Windowの作り方
    CreateApplicationWindow
#elif 0
    // Bitmap画像のロード及び表示
    DrawImage
#elif 1
    // MessageBoxの表示
    DrawImage
#elif 1
    // Buttonの作成および表示
    DrawImage
#elif 1
    // FileDialogの表示
    DrawImage
#endif

    application;

    application.Init(hInstance);

    application.Update();

    application.Release();

    return 0;
}