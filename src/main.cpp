#include"main.h"

//�������m�F���������ڂ̃R�����g�A�E�g���O���Ă�������//

//// Window�̍���//
//#include"CreateWindow/CreateWindow.h"

//// Bitmap�摜�̃��[�h�y�ѕ\��//
//#include"DrawImage/DrawImage.h"

//// MessageBox�̕\��//
//#include"DrawMessageBox/DrawMessageBox.h"

//// Button�̍쐬����ѕ\��//
//#include"DrawButton/DrawButton.h"

//// FileDialog�̕\��//
#include"DrawFileDialog/DrawFileDialog.h"

int WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    int       nShowCmd)
{
    return mainFunction(hInstance);
}