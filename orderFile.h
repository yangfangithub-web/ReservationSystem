#pragma once

#include <map>
#include <iostream>
#include "globalFile.h"
using namespace std;

class OrderFile {
public:
	OrderFile();
	void updateOrder();

	map<int, map<string, string>> m_orderData;

	int m_Size;
};