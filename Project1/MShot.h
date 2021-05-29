#pragma once

#include "DVPCamera.h"

#ifdef _M_X64 // 加载 64 位 LIB 库
#pragma comment(lib, "DVPCamera64.lib")
#else // 加载 32 位 LIB 库
#pragma comment(lib, "DVPCamera.lib")
#endif

class MShot
{

};