// CheckData.cpp: implementation of the CCheckData class.
// by ����¼
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CTaiShanApp.h"
#include "CheckData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


#define DLINEHEAD  24
#define DLINESMALLHEAD 4096 * 64
#define DLINECHUQ   32 * 6


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCheckData::CCheckData()
{

}

CCheckData::~CCheckData()
{

}


BOOL CCheckData::OverlapBlock_SH() //�Ϻ����
{

	return 1;

}

BOOL CCheckData::OverlapBlock_SZ() //���ڰ��
{

	return 1;
}

BOOL CCheckData::OverlapSymbol_SH() //�Ϻ�				
{

	ASSERT(FALSE);
	
	
	return 1;
	
}

BOOL CCheckData::OverlapSymbol_SZ() //����			
{


	return 1;
}


BOOL CCheckData::MaxBlock_SH() 
{
	////////////////////////////////////////////////
	return 0;
	
}

BOOL CCheckData::MaxBlock_SZ() 
{
	////////////////////////////////////////////////
	return 0;
	
}
