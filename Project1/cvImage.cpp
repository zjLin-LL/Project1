#include "cvImage.h"

bool cvImage::exist(const char* path)
{
	if (!_access(path, 0))
		return true;
	else
		return false;

}