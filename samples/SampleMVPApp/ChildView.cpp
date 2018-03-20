
// ChildView.cpp : implementation of the ChildView class
//

#include "stdafx.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

struct Size
{
	bool operator==(const Size& rhs) const
	{
		return width == rhs.width && height == rhs.height;
	}
	bool operator!=(const Size& rhs) const
	{
		return !(*this == rhs);
	}
	int width = 0;
	int height = 0;
};

class Widget
{
public:
	using SizeSignal = Signal<void(const Size& size)>;

	Connection DoOnSizeChange(const SignallingValue<Size>::Slot1& handler)
	{
		return m_size.Connect(handler);
	}
	Size GetSize() const { return m_size; }
	void Resize(const Size& newSize)
	{
		m_size = newSize;
	}

private:
	SignallingValue<Size> m_size;
};

class Presenter
{
public:
	Presenter(Widget& widget1, Widget& widget2)
	{
		m_widget1Conn = widget1.DoOnSizeChange([this](auto&& s) {
			/* handle resize */
		});
		m_widget2Conn = widget2.DoOnSizeChange([this](auto&& s) {
			/* handle resize */
		});
	}

private:
	ScopedConnection m_widget1Conn;
	ScopedConnection m_widget2Conn;
};

class Presenter1
{
public:
	Presenter1(Widget& widget1, Widget& widget2)
	{
		m_connections = {
			widget1.DoOnSizeChange([this](auto&& s) {
				/* handle resize */
			}),
			widget1.DoOnSizeChange([this](auto&& s) {
				/* handle resize */
			})
		};
	}

private:
	ScopedConnections m_connections;
};

// ChildView

ChildView::ChildView()
{
}

BEGIN_MESSAGE_MAP(ChildView, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// ChildView message handlers

BOOL ChildView::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), NULL);

	return TRUE;
}

void ChildView::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	// TODO: Add your message handler code here

	// Do not call CWnd::OnPaint() for painting messages
}
