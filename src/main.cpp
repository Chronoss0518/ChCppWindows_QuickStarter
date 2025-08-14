#include"main.h"

//挙動を確認したい項目のコメントアウトを外してください//

//// Windowの作り方//
//#include"CreateWindow/CreateWindow.h"

//// Bitmap画像のロード及び表示//
//#include"DrawImage/DrawImage.h"

//// MessageBoxの表示//
//#include"DrawMessageBox/DrawMessageBox.h"

//// Buttonの作成および表示//
//#include"DrawButton/DrawButton.h"

//// FileDialogの表示//
#include"DrawFileDialog/DrawFileDialog.h"

int WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    int       nShowCmd)
{
    return mainFunction(hInstance);
}