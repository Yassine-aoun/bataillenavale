#pragma once
#include "wx/wx.h"
#include "cFill.h"
#include "cMenu.h"

class cApp : public wxApp
{
private:
	cMenu* m_frame1 = nullptr;
public:
	virtual bool OnInit();
};

