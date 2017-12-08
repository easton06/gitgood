#pragma once

#include "Dude.h"
#include "Graphics.h"
#include "Poo.h"

class Goal
{
public:
	void ProcessConsumption(const Dude& dude, int set_x, int set_y);
	void Draw( Graphics& gfx ) const;
	void ProgressBarDraw( Graphics& gfx ) const;
	void ColorSwitch();
private:
	int x = 300;
	int y = 400;
	int r = 255;
	int p = 2;
	int gPeriod = 300;
	static constexpr int width = 20;
	static constexpr int height = 20;
	bool colorFlag = false;
};