#include"BaseIncluder.h"
#include"CreateWindow/CreateWindow.h"

#include"DrawImage/DrawImage.h"

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
#elif 1
    // MessageBox�̕\��
    DrawImage
#elif 1
    // Button�̍쐬����ѕ\��
    DrawImage
#elif 1
    // FileDialog�̕\��
    DrawImage
#endif

    application;

    application.Init(hInstance);

    application.Update();

    application.Release();

    return 0;
}