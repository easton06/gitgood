#include "Goal.h"

void Goal::ProcessConsumption( const Dude & dude, int set_x, int set_y )
{
	if( gPeriod > 0 )
	{
		gPeriod -= 1;
	}

	const int duderight = dude.GetX() + dude.GetWidth();
	const int dudebottom = dude.GetY() + dude.GetHeight();
	const int pooright = x + width;
	const int poobottom = y + height;

	if (duderight >= x &&
		dude.GetX() <= pooright &&
		dudebottom >= y &&
		dude.GetY() <= poobottom)
	{
		x = set_x;
		y = set_y;
		p += 8;
	}
}

void Goal::Draw(Graphics & gfx) const
{
	for ( int ty = y; ty < y + height; ++ty )
	{
		for ( int tx = x; tx < x + width; ++tx)
		{
			gfx.PutPixel( tx,ty,255,r,r );
		}
	}
}

void Goal::ProgressBarDraw(Graphics & gfx ) const
{
	if (gPeriod == 0)
	{
		for (int ty = 5; ty < 32; ++ty)
		{
			for (int tx = 15; tx < 5 + p * 2 + width; ++tx)
			{
				gfx.PutPixel(tx, ty, Colors::Blue);
			}
		} 
	}
	else {

		for (int ty = 5; ty < 32; ++ty)
		{
			for (int tx = 15; tx < 5 + p * 2 + width; ++tx)
			{
				gfx.PutPixel(tx, ty, 255, 206, 91 );
			}
		}
	}
}

void Goal::ColorSwitch()
{
	if ( r == 255 )
	{
		colorFlag = true;
	}

	if( r == 0 )
	{
		colorFlag = false;
	}

	if( colorFlag )
	{
		r -= 1;
	}
	else {
		r += 1;
	}

}


