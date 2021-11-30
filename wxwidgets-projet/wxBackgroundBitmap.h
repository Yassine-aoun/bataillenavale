//---------------------------------------------------------------------------
//
// Name:        wxBackgroundBitmap.h
// Author:      Sof.T
// Created:     20/01/2008 16:36:20
// Description: An implementation of the bitmap painting event created by
//              Paulsen found here http://wxforum.shadonet.com/viewtopic.php?t=10019
//
//---------------------------------------------------------------------------

#ifndef __WX_BACKGROUND_BITMAP_H__
#define __WX_BACKGROUND_BITMAP_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
	#include <wx/bitmap.h>
	#include <wx/event.h>
#else
	#include <wx/wxprec.h>
#endif

class wxBackgroundBitmap : public wxEvtHandler
{ 
    typedef wxEvtHandler Inherited; 
public: 
    wxBackgroundBitmap(const wxBitmap &B) : Bitmap(B), wxEvtHandler() { } 
    virtual bool ProcessEvent(wxEvent &Event); 
protected: 
    wxBitmap Bitmap; 
};
#endif
