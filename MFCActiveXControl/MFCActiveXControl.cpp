// MFCActiveXControl.cpp : Implementation of CMFCActiveXControlApp and DLL registration.

#include "pch.h"
#include "framework.h"
#include "MFCActiveXControl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CMFCActiveXControlApp theApp;

const GUID CDECL _tlid = {0xaa969a64,0x7344,0x44b6,{0xb6,0xf1,0x2d,0x8e,0x82,0x46,0xa7,0xe5}};
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CMFCActiveXControlApp::InitInstance - DLL initialization

BOOL CMFCActiveXControlApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Add your own module initialization code here.
	}

	return bInit;
}



// CMFCActiveXControlApp::ExitInstance - DLL termination

int CMFCActiveXControlApp::ExitInstance()
{
	// TODO: Add your own module termination code here.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
