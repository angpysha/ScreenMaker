
// LauncherView.h : interface of the CLauncherView class
//

#pragma once


class CLauncherView : public CView
{
protected: // create from serialization only
	CLauncherView();
	DECLARE_DYNCREATE(CLauncherView)

// Attributes
public:
	CLauncherDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CLauncherView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in LauncherView.cpp
inline CLauncherDoc* CLauncherView::GetDocument() const
   { return reinterpret_cast<CLauncherDoc*>(m_pDocument); }
#endif

