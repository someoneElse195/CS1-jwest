#include <wx/wx.h>
#include <wx/sizer.h>

enum
{
    BUTTONID00 = wxID_HIGHEST + 1,
    BUTTONID01 = wxID_HIGHEST + 2,
    BUTTONID02 = wxID_HIGHEST + 3,
    BUTTONID10 = wxID_HIGHEST + 4,
    BUTTONID11 = wxID_HIGHEST + 5,
    BUTTONID12 = wxID_HIGHEST + 6,
    BUTTONID20 = wxID_HIGHEST + 7,
    BUTTONID21 = wxID_HIGHEST + 8,
    BUTTONID22 = wxID_HIGHEST + 9

};



class BasicDrawPane : public wxPanel
{
    
public:
    BasicDrawPane(wxFrame* parent);
    
    void paintEvent(wxPaintEvent & evt);
    void paintNow();


    void render(wxDC& dc);

    int Cells[3][3] = {
        {-1,-1,-1},
        {-1,-1,-1},
        {-1,-1,-1}
    };



    DECLARE_EVENT_TABLE()
};

class MyApp: public wxApp
{
    bool OnInit();


    BasicDrawPane *drawPane;
public:
    wxButton spaceButton00;
    wxButton spaceButton01;
    wxButton spaceButton02;
    wxButton spaceButton10;
    wxButton spaceButton11;
    wxButton spaceButton12;
    wxButton spaceButton20;
    wxButton spaceButton21;
    wxButton spaceButton22;        
};

IMPLEMENT_APP(MyApp)

class MyFrame : public wxFrame
{
public:
    MyFrame();

    
 
private:

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};




bool MyApp::OnInit()
{   
    MyFrame *frame = new MyFrame();
    drawPane = new BasicDrawPane( (wxFrame*) frame );
    frame->Show(true);   

    


    spaceButton00.Create 
    (
        frame,
        BUTTONID00, 
        wxString(""), 
        wxPoint(75,75), 
        wxSize(50,50), 
        0,  
        wxDefaultValidator, 
        wxString("BUTTON00")
    );
    spaceButton01.Create
    (
        frame,
        BUTTONID01, 
        wxString(""), 
        wxPoint(175,75), 
        wxSize(50,50), 
        0,  
        wxDefaultValidator, 
        wxString("BUTTON01")
    );
    spaceButton02.Create
    (
        frame,
        BUTTONID02, 
        wxString(""), 
        wxPoint(275,75), 
        wxSize(50,50), 
        0,  
        wxDefaultValidator, 
        wxString("BUTTON02")
    );
    spaceButton10.Create
    (
        frame,
        BUTTONID10, 
        wxString(""), 
        wxPoint(75,175), 
        wxSize(50,50), 
        0,  
        wxDefaultValidator, 
        wxString("BUTTON10")
    );
    spaceButton11.Create
    (
        frame,
        BUTTONID11, 
        wxString(""), 
        wxPoint(175,175), 
        wxSize(50,50), 
        0,  
        wxDefaultValidator, 
        wxString("BUTTON11")
    );
    spaceButton12.Create
    (
        frame,
        BUTTONID12, 
        wxString(""), 
        wxPoint(275,175), 
        wxSize(50,50), 
        0,  
        wxDefaultValidator, 
        wxString("BUTTON12")
    );
    spaceButton20.Create
    (
        frame,
        BUTTONID20, 
        wxString(""), 
        wxPoint(75,275), 
        wxSize(50,50), 
        0,  
        wxDefaultValidator, 
        wxString("BUTTON20")
    );
    spaceButton21.Create
    (
        frame,
        BUTTONID21, 
        wxString(""), 
        wxPoint(175,275), 
        wxSize(50,50), 
        0,  
        wxDefaultValidator, 
        wxString("BUTTON21")
    );
    spaceButton22.Create
    (
        frame,
        BUTTONID22, 
        wxString(""), 
        wxPoint(275,275), 
        wxSize(50,50), 
        0,  
        wxDefaultValidator, 
        wxString("BUTTON22")
    );
    

    return true;
    
} 


void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
 
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is an application that runs the game 'Tic-Tac-Toe' and was made as a final for my CS-1 Class. \n While using a GUI builder is not required, I thought it would be fun...",
                 "About Application");
}

MyFrame::MyFrame()
    : wxFrame(nullptr, wxID_ANY, "Tic-Tac-Toe")
{
    SetMinSize(wxSize(400, 400));
    SetMaxSize(wxSize(400, 400));

    SetBackgroundColour(wxColor(255,255,255));

    wxMenu *menuFile = new wxMenu;
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
 
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
 
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar( menuBar );
 
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);

    Bind(wxEVT_BUTTON, &MyFrame::OnExit, this, BUTTONID00);
    Bind(wxEVT_BUTTON, &MyFrame::OnExit, this, BUTTONID01);
    Bind(wxEVT_BUTTON, &MyFrame::OnExit, this, BUTTONID02);
    Bind(wxEVT_BUTTON, &MyFrame::OnExit, this, BUTTONID10);
    Bind(wxEVT_BUTTON, &MyFrame::OnExit, this, BUTTONID11);
    Bind(wxEVT_BUTTON, &MyFrame::OnExit, this, BUTTONID12);
    Bind(wxEVT_BUTTON, &MyFrame::OnExit, this, BUTTONID20);
    Bind(wxEVT_BUTTON, &MyFrame::OnExit, this, BUTTONID21);
    Bind(wxEVT_BUTTON, &MyFrame::OnExit, this, BUTTONID22);
    

}


BEGIN_EVENT_TABLE(BasicDrawPane, wxPanel)

// catch paint events
EVT_PAINT(BasicDrawPane::paintEvent)


END_EVENT_TABLE()

BasicDrawPane::BasicDrawPane(wxFrame* parent) :
wxPanel(parent)
{
}


void BasicDrawPane::paintEvent(wxPaintEvent & evt)
{
    wxPaintDC dc(this);
    render(dc);
}

void BasicDrawPane::paintNow()
{
    wxClientDC dc(this);
    render(dc);
}

void BasicDrawPane::render(wxDC&  dc)
{
    // draw a line
    dc.SetPen( wxPen( wxColor(0,0,0), 10 ) ); 
    dc.DrawLine( 50, 150, 350, 150 ); 
    dc.DrawLine(150, 50, 150, 350);
    dc.DrawLine(250, 50, 250, 350);
    dc.DrawLine(50, 250, 350, 250);

    // dc.DrawRectangle(75,75,50,50);
    // dc.DrawRectangle(175,75, 50,50);
    // dc.DrawLine(75, 75, 125, 125);
    // dc.DrawLine(125, 75, 75, 125);

    dc.SetPen( wxPen(wxColor(65,65,65), 3));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (Cells[i][j] == -1) {
                dc.DrawRectangle(75+(j*100),75+(i*100),50,50);
                //MyApp::spaceButton00.SetPosition(wxPoint(75,75));
            } else if (Cells[i][j] == 0) {
                //MyApp::spaceButton00.Disable();
                dc.DrawLine(75+(j*100), 75+(i*100), 125+(j*100), 125+(i*100));
                dc.DrawLine(125+(j*100), 75+(i*100), 75+(j*100), 125+(i*100));
            } else if(Cells[i][j] == 1) {
                //MyApp::spaceButton00.Disable();
                dc.DrawCircle(100+(j*100), 100+(i*100), 30);
            }
        }
    }
    
    
    

}
