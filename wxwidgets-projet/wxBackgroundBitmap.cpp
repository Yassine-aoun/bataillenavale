//---------------------------------------------------------------------------
//
// Name:        wxBackgroundBitmap.cpp
// Author:      Sof.T
// Created:     20/01/2008 16:36:20
// Description: An implementation of the bitmap painting event created by
//              Paulsen found here http://wxforum.shadonet.com/viewtopic.php?t=10019
//
//---------------------------------------------------------------------------

#include "wxBackgroundBitmap.h"
#include <wx/dcbuffer.h>

/*bool wxBackgroundBitmap::ProcessEvent(wxEvent &Event) 
{ 
    if (Event.GetEventType() == wxEVT_ERASE_BACKGROUND)
    { 
        wxEraseEvent *EraseEvent = wxDynamicCast(&Event,wxEraseEvent);
        if(EraseEvent)
        { 
            wxDC *DC = EraseEvent->GetDC();
            
            
            wxMemoryDC MemDC;
            MemDC.DrawBitmap(Bitmap, 0, 0, false);
            
            wxCoord w, h;
            DC->GetSize(&w, &h);
            // We know the graphic size. 
            float maxX = Bitmap.GetWidth(); 
            float maxY = Bitmap.GetHeight();
            
            
            // Calculate a suitable scaling factor 
            float scaleX=(float)(w/maxX); 
            float scaleY=(float)(h/maxY); 

            // Set the scale and origin 
            MemDC.SetUserScale(scaleX, scaleY);
    
            DC->Blit(0,0,w,h,&MemDC,0,0);
            //Event.Skip();
            return true;
        }
        else
            return Inherited::ProcessEvent(Event);
    }
    else
        return Inherited::ProcessEvent(Event); 
}*/

bool wxBackgroundBitmap::ProcessEvent(wxEvent &Event)
{
    if(Event.GetEventType() == wxEVT_ERASE_BACKGROUND)
    {
        if(Bitmap.IsOk())
        {
        }
        else
            Event.Skip();
    }
    else if(Event.GetEventType() == wxEVT_PAINT)
    {
        bool TransactionIsOk = false;
        if(Bitmap.IsOk())
        {
            wxWindow * TempWindow = wxDynamicCast(Event.GetEventObject(),wxWindow);
            if(TempWindow)
            {
                wxBufferedPaintDC DC(TempWindow);
                int w, h;
                TempWindow->GetClientSize(&w, &h);
                wxImage TempImage = Bitmap.ConvertToImage();
                TempImage.Rescale(w,h);
                DC.DrawBitmap(wxBitmap(TempImage), 0, 0, false);
                TransactionIsOk = true;
            }
        }
        if(TransactionIsOk == false)
            Event.Skip();
    }
    else if(Event.GetEventType() ==  wxEVT_SIZE)
    {
        wxWindow * TempWindow = wxDynamicCast(Event.GetEventObject(),wxWindow);
        if(TempWindow)
        {
            TempWindow->Refresh();
        }
        Event.Skip();
    }
    else
        return Inherited::ProcessEvent(Event);
    return true;
}
