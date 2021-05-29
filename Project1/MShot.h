#pragma once

#include "DVPCamera.h"
#ifdef _M_X64 // 加载 64 位 LIB 库
#pragma comment(lib, "DVPCamera64.lib")
#else // 加载 32 位 LIB 库
#pragma comment(lib, "DVPCamera.lib")
#endif
#include <string>
#include <sstream>
using namespace std;

class MShot
{
public:
	dvpUint32 count;
	dvpStatus status;
	dvpCameraInfo info;
	dvpHandle pHandle;
	void* buffer;
	dvpFrame frame;
	string strImageInfo;

	bool OpenCam();
	bool CloseCam();

	bool SetExposure(double Etime);
	bool SetGain(float  Gain);

	bool OpenStream();
	bool CloseStream();
	bool GrabImage(int ImageIndex, string captureImageFolder);
};