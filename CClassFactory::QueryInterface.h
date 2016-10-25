//
// CClassFactory::QueryInterface
//
STDMETHODIMP CClassFactory::QueryInterface( REFIID riid, LPVOID *ppReturn )
{
	*ppReturn = NULL;

	if( IsEqualIID(riid, IID_IUnknown) )
	    *ppReturn = this;
	else 
	    if( IsEqualIID(riid, IID_IClassFactory) )
		*ppReturn = (IClassFactory*)this;


	if( *ppReturn )
	{
		LPUNKNOWN pUnk = (LPUNKNOWN)(*ppReturn);
		pUnk->AddRef();
		return S_OK;
	}

	return E_NOINTERFACE;
} 
