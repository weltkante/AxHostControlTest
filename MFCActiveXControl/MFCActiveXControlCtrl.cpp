// MFCActiveXControlCtrl.cpp : Implementation of the CMFCActiveXControlCtrl ActiveX Control class.

#include "pch.h"
#include "framework.h"
#include "MFCActiveXControl.h"
#include "MFCActiveXControlCtrl.h"
#include "MFCActiveXControlPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMFCActiveXControlCtrl, COleControl)

// Message map

BEGIN_MESSAGE_MAP(CMFCActiveXControlCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// Dispatch map

BEGIN_DISPATCH_MAP(CMFCActiveXControlCtrl, COleControl)
	DISP_FUNCTION_ID(CMFCActiveXControlCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

// Event map

BEGIN_EVENT_MAP(CMFCActiveXControlCtrl, COleControl)
END_EVENT_MAP()

// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CMFCActiveXControlCtrl, 1)
	PROPPAGEID(CMFCActiveXControlPropPage::guid)
END_PROPPAGEIDS(CMFCActiveXControlCtrl)

// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CMFCActiveXControlCtrl, "MFCACTIVEXCONTRO.MFCActiveXControlCtrl.1",
	0xec408006,0x9af7,0x48ea,0xaf,0x51,0x97,0x43,0xe2,0xef,0xde,0x6f)

// Type library ID and version

IMPLEMENT_OLETYPELIB(CMFCActiveXControlCtrl, _tlid, _wVerMajor, _wVerMinor)

// Interface IDs

const IID IID_DMFCActiveXControl = {0xc4d314b3,0x31da,0x445c,{0xad,0xb3,0xac,0xc1,0x0a,0x87,0xd1,0xfb}};
const IID IID_DMFCActiveXControlEvents = {0xc8144181,0xbfe5,0x4616,{0x8d,0xb0,0x23,0xac,0x08,0xc3,0x5f,0xa2}};

// Control type information

static const DWORD _dwMFCActiveXControlOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMFCActiveXControlCtrl, IDS_MFCACTIVEXCONTROL, _dwMFCActiveXControlOleMisc)

// CMFCActiveXControlCtrl::CMFCActiveXControlCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CMFCActiveXControlCtrl

BOOL CMFCActiveXControlCtrl::CMFCActiveXControlCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_MFCACTIVEXCONTROL,
			IDB_MFCACTIVEXCONTROL,
			afxRegApartmentThreading,
			_dwMFCActiveXControlOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CMFCActiveXControlCtrl::CMFCActiveXControlCtrl - Constructor

CMFCActiveXControlCtrl::CMFCActiveXControlCtrl()
{
	InitializeIIDs(&IID_DMFCActiveXControl, &IID_DMFCActiveXControlEvents);
	// TODO: Initialize your control's instance data here.
}

// CMFCActiveXControlCtrl::~CMFCActiveXControlCtrl - Destructor

CMFCActiveXControlCtrl::~CMFCActiveXControlCtrl()
{
	// TODO: Cleanup your control's instance data here.
}

// CMFCActiveXControlCtrl::OnDraw - Drawing function

void CMFCActiveXControlCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CMFCActiveXControlCtrl::DoPropExchange - Persistence support

void CMFCActiveXControlCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.
}


// CMFCActiveXControlCtrl::OnResetState - Reset control to default state

void CMFCActiveXControlCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


// CMFCActiveXControlCtrl::AboutBox - Display an "About" box to the user

void CMFCActiveXControlCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_MFCACTIVEXCONTROL);
	dlgAbout.DoModal();
}


// CMFCActiveXControlCtrl message handlers
