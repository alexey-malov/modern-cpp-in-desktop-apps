
// ChildView.h : interface of the ChildView class
//

#pragma once

#include "SignallingValue.h"

// ChildView window

class ChildView : public CWnd
{
public:
	ChildView();

private:
	BOOL PreCreateWindow(CREATESTRUCT& cs) override;

	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};
