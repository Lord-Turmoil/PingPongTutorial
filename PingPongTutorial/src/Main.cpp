#include <Windows.h>
#include <easyx.h>

int APIENTRY WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd)
{
    initgraph(640, 480);    // ������ͼ���ڣ���СΪ 640x480 ����
    circle(200, 200, 100);  // ��Բ��Բ��(200, 200)���뾶 100

    // _getch();            // ���ڳ����޷�ʹ�ÿ���̨�������
    Sleep(5000);            // ��ʱ 5000 ���루������ Windows.h �У�

    closegraph();           // �رջ�ͼ����
    return 0;
}