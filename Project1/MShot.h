#pragma once

#include "DVPCamera.h"

#ifdef _M_X64 // ���� 64 λ LIB ��
#pragma comment(lib, "DVPCamera64.lib")
#else // ���� 32 λ LIB ��
#pragma comment(lib, "DVPCamera.lib")
#endif

class MShot
{

};