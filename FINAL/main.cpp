#include <wx/wx.h>
#include <wx/sizer.h>




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
    
    wxButton spaceButton00(wxWindow parent,
    wxWindowID wxID_HELP, 
    wxString label, 
    wxPoint pos, 
    wxSize size, 
    long style, 
    wxValidator validator, 
    wxString name);


    DECLARE_EVENT_TABLE()
};

class MyApp: public wxApp
{
    bool OnInit();



    BasicDrawPane *drawPane;
public:
        
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
            } else if (Cells[i][j] == 0) {
                dc.DrawLine(75+(j*100), 75+(i*100), 125+(j*100), 125+(i*100));
                dc.DrawLine(125+(j*100), 75+(i*100), 75+(j*100), 125+(i*100));
            } else if(Cells[i][j] == 1) {
                dc.DrawCircle(100+(j*100), 100+(i*100), 30);
            }
        }
    }
    
    

}
