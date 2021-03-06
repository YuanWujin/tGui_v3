#include "TWidget/TSwitch.h"


TSwitch::TSwitch(int32 x, int32 y, int32 w, int32 h, const char* name, TWidget* obj)
	:TAbstractButton(x, y, w, h, false,name, obj)
{
	next = this; 
	selected = false; 

	TBufPainter p(getBuffer()->getBufAddr(),getRect());
	p.drawCheck(0,0, width(), height(), getName(), selected, state, getBackColor());
}



TSwitch::TSwitch(int32 x, int32 y,TImage* norImg,TImage* selImg, const char* name, TWidget* obj)
	:TAbstractButton( x,  y,norImg->imgW(),norImg->imgH(), true,name, obj)
{
	next = this; 
	selected = false; 

	this->norImg = norImg;
	this->selImg = selImg;

	imgLoadInterface(0,0,norImg);
	TBufPainter p(getBuffer()->getBufAddr(),getRect());
	p.drawAlignText(0,0, getName(),ALIGN_MID_LEFT);

}

TSwitch::~TSwitch() 
{
	
};

void TSwitch::sig_depress(int32 d1, int32 d2)
{
	if(haveImg)
	{
	}
	else
	{
		//TPainter p(getInvalidList(),getPaintInvaild());
		TBufPainter p(getBuffer()->getBufAddr(),getRect());
		p.drawCheck(0, 0, width(), height(), getName(),selected, true, getBackColor());
		refresh();
	}
	state = true;
	callSlot((func)&TSwitch::sig_depress,d1,d2);
}


void TSwitch::sig_release(int32 d1, int32 d2)
{
	changeSelected();
	if(haveImg)
	{
		if(selected)
		{
			imgLoadInterface(0,0,selImg);
			TBufPainter p(getBuffer()->getBufAddr(),getRect());
			p.drawAlignText(0,0, getName(),ALIGN_MID_LEFT);
		}
		else
		{
			imgLoadInterface(0,0,norImg);
			TBufPainter p(getBuffer()->getBufAddr(),getRect());
			p.drawAlignText(0,0, getName(),ALIGN_MID_LEFT);
		}
	}
	else
	{
		//TPainter p(getInvalidList(),getPaintInvaild());
		TBufPainter p(getBuffer()->getBufAddr(),getRect());
		p.drawCheck(0, 0, width(), height(), getName(), selected, false, getBackColor());
	}
	refresh();
	state = false;
	callSlot((func)&TSwitch::sig_release,d1,d2);
}

void TSwitch::release()
{
	changeSelected();
	if(haveImg)
	{
		if(selected)
		{
			imgLoadInterface(0,0,selImg);
			TBufPainter p(getBuffer()->getBufAddr(),getRect());
			p.drawAlignText(0,0, getName(),ALIGN_MID_LEFT);
		}
		else
		{
			imgLoadInterface(0,0,norImg);
			TBufPainter p(getBuffer()->getBufAddr(),getRect());
			p.drawAlignText(0,0, getName(),ALIGN_MID_LEFT);
		}
	}
	else
	{
		TBufPainter p(getBuffer()->getBufAddr(),getRect());
		p.drawCheck(0, 0, width(), height(), getName(), selected, false, getBackColor());
	}
	refresh();
	state = false;
}

void TSwitch::show()
{
	refresh();
}
