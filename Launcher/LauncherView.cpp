
// LauncherView.cpp : implementation of the CLauncherView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Launcher.h"
#endif

#include "LauncherDoc.h"
#include "LauncherView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLauncherView

IMPLEMENT_DYNCREATE(CLauncherView, CView)

BEGIN_MESSAGE_MAP(CLauncherView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CLauncherView construction/destruction

CLauncherView::CLauncherView()
{
	// TODO: add construction code here

}

CLauncherView::~CLauncherView()
{
}

BOOL CLauncherView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CLauncherView drawing

void CLauncherView::OnDraw(CDC* /*pDC*/)
{
	CLauncherDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CLauncherView printing

BOOL CLauncherView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLauncherView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLauncherView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CLauncherView diagnostics

#ifdef _DEBUG
void CLauncherView::AssertValid() const
{
	CView::AssertValid();
}

void CLauncherView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLauncherDoc* CLauncherView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLauncherDoc)));
	return (CLauncherDoc*)m_pDocument;
}
#endif //_DEBUG


// CLauncherView message handlers
