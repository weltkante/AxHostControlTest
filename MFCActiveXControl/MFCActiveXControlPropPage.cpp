// MFCActiveXControlPropPage.cpp : Implementation of the CMFCActiveXControlPropPage property page class.

#include "pch.h"
#include "framework.h"
#include "MFCActiveXControl.h"
#include "MFCActiveXControlPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMFCActiveXControlPropPage, COlePropertyPage)

// Message map

BEGIN_MESSAGE_MAP(CMFCActiveXControlPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CMFCActiveXControlPropPage, "MFCACTIVEXCONT.MFCActiveXControlPropPage.1",
	0x6bd9d9fa,0x063e,0x4d3a,0x9e,0x82,0xcf,0xd2,0x3c,0x29,0x06,0xa8)

// CMFCActiveXControlPropPage::CMFCActiveXControlPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CMFCActiveXControlPropPage

BOOL CMFCActiveXControlPropPage::CMFCActiveXControlPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MFCACTIVEXCONTROL_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, nullptr);
}

// CMFCActiveXControlPropPage::CMFCActiveXControlPropPage - Constructor

CMFCActiveXControlPropPage::CMFCActiveXControlPropPage() :
	COlePropertyPage(IDD, IDS_MFCACTIVEXCONTROL_PPG_CAPTION)
{
}

// CMFCActiveXControlPropPage::DoDataExchange - Moves data between page and properties

void CMFCActiveXControlPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CMFCActiveXControlPropPage message handlers
