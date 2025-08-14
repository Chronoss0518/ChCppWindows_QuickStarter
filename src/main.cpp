#include"main.h"

//挙動を確認したい項目のコメントアウトを外してください//

//// Windowの作り方//
//#include"CreateWindow.h"

//// Textを描画//
//#include"DrawText.h"

//// Bitmap画像のロード及び表示//
//#include"DrawImage.h"

//// RenderTargetを用いた描画//
//#include"UseRenderTarget.h"

//// MessageBoxの表示//
//#include"DrawMessageBox.h"

//// Buttonの作成および表示//
//#include"DrawButton.h"

//// TextBoxの作成および表示//
//#include"DrawTextBox.h"

//// FileDialogの表示//
//#include"DrawFileDialog.h"

int WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    int       nShowCmd)
{
    return mainFunction(hInstance);
}