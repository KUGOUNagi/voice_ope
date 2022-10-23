#include "DxLib.h"
#include "ScoreClass.h"
#include <iostream>
using namespace std;

// 
void Score::print1()
{
	a = 2;
	b = a * a * c;
	DrawFormatString(500, 0, GetColor(255, 255, 255), "%d", b);

}