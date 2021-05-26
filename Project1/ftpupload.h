#pragma once
#include <windows.h>
#include <vector>
#include<io.h>
#include <wininet.h>
#include <iostream>
using namespace std;

class ftpup
{
public:
	int connect(string IP, string uesrname, string key);

};

