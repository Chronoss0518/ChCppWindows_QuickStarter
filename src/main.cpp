#include"BaseIncluder.h"
#include"CreateWindow/CreateWindow.h"

#include"DrawImage/DrawImage.h"
#include"DrawMessageBox/DrawMessageBox.h"
#include"DrawButton/DrawButton.h"
#include"DrawFileDialog/DrawFileDialog.h"


//�������m�F���������ڂ�#if�܂���#elif�̒l�݂̂�1�ɕύX���Ă�������//

int WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    int       nShowCmd)
{
#if 0
    // Window�̍���
    CreateApplicationWindow
#elif 0
    // Bitmap�摜�̃��[�h�y�ѕ\��
    DrawImage
#elif 0
    // MessageBox�̕\��
    DrawMessageBox
#elif 0
    // Button�̍쐬����ѕ\��
    DrawButton
#elif 1
    // FileDialog�̕\��
    DrawFileDialog
#endif

    application;

    application.Init(hInstance);

    application.Update();

    application.Release();

    return 0;
}