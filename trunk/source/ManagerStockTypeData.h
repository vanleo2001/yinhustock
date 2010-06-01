
#if !defined(AFX_MANAGERSTOCKTYPEDATA_H__520245A1_5257_11D4_8829_00400552E583__INCLUDED_)
#define AFX_MANAGERSTOCKTYPEDATA_H__520245A1_5257_11D4_8829_00400552E583__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "StkFile.h"
#include <afxcmn.h>

#define ADDSIZES	50
#define CHOOSEPOS	251

class CSuperviseSharesBlockData : public CStkFile
{
public:
	CSuperviseSharesBlockData();
	virtual ~CSuperviseSharesBlockData();
	enum {ZGB=0,LTG=1,OTHER=2	 };     

private:
	CTaiShanDoc   *m_pDoc;      

protected:
	STOCKTYPEHEAD* m_pStockTypeHead;		// 
	STOCKTYPEINFO* m_pStockTypeInfo;		// 
	STOCK_TYPE_INFO* m_pStockInfo;			// 
	STOCK_POINT_INFO* m_pStockPoint;		// 

protected:
	BOOL InitStockTypeDataEmpty(CString strPath);       
	BOOL InitStockTypeDataExist(CString strPath);    
	BOOL AddStockTypeDataSize(int AddSize = ADDSIZES);
	BOOL SetMemroyALLOCSize(unsigned int nSize);  
	BOOL InsertItemPoint(STOCK_TYPE_INFO* m_pStk);  
	BOOL SavePosToFile();                             
	void SaveDataToFile(LPCVOID lpBaseAddress, DWORD dwNumberOfBytesToFlush);

public:
	BOOL InitStockTypeData(CString strPath);
	void GetStockTypeHeadPoint(PSTOCKTYPEHEAD& pStockTypeHead) { pStockTypeHead = m_pStockTypeHead; }

	// ����Ʊ���ӵ� Report->pStockTypeInfo
	BOOL InitStockPoint();

	// ������ָ���� Report (STKTYPE)
	BOOL InitStockTypePoint();

	void CalcAllStockTypeData();           
	void CalcRealTimeStockTypeIndex();      
	void CalcMinuteRealTimeIndex();    



public:
	// ��ָ��λ�ò�����
	BOOL InsertStockType(PSTOCKTYPEINFO& m_pStktype, int m_iPos);
	BOOL DeleteStockType(char* m_pszStockTypeCode);

	// ��ȡָ������֤ȯ�б�
	BOOL GetStockFromStockType(SymbolKindArr& m_StockCodeArray, char* m_pszStockTypeCode);
	BOOL GetStockFromStockTypeName(SymbolKindArr& m_StockCodeArray, char* m_pszStockTypeName);

	// ��ȡָ������֤ȯ��
	int GetStockCountFromType(char* m_pszCode);

	// ȡ����Ч������
	int GetStockTypeCounts();

	// �ڰ���в���ɾ����Ʊ
	BOOL InsertStockToType(PCdat1& m_pCdat, char* m_szStockTypeCode);       
	BOOL DeleteStockFromType(char* m_pszStockCode, int nKind, char* m_szStockTypeCode);    
	BYTE GetStockTypeNumber(char* m_szStockTypeCode);

	// ��������ʹ����Ƿ��ظ�
	BOOL CheckBlockName(char* BlockName, char* BlockCode);

	// ��ȡ���հײ���λ��
	int GetInsertStockTypePos();

	// ��ȡ���а�����ƺʹ���
	void GetAllStockTypeCode(CStringArray& m_StockTypeCodeArray);
	void GetAllStockTypeName(CStringArray& m_StockTypeNameArray);

	// ��ȡ�����Ϣ
	BOOL GetStockTypePoint(PSTOCKTYPEINFO& m_pStktype, char* m_pszStockTypeCode);
	BOOL GetStockTypePointFromName(PSTOCKTYPEINFO& m_pStktype, char* m_pszStockTypeName);

	// �����Ʊ���
	BOOL ImportStockTypeData(CString m_szPathStr, CString m_szStockNameStr, PSTOCKTYPEINFO& m_pStktype, int nRightType = LTG);

public:
	static bool CheckKind(int i);
	void  CheckStockCount(int AddStockCount);


	void RefreshHistoryDayLineData(char *pszStockTypeCode, CProgressCtrl *p=NULL);
	BOOL GetStockTypeStartDate(char * pszStockTypeCode,SymbolKindArr &StockCodeArray,time_t &t);

	BOOL InsertStockItemCorrect(char *m_szStockId ,PSTOCK_TYPE_INFO m_pStock) ;     
	long CorrectKline(Kline *pKline,long LineCount);
	float GetStockBlockRight(char *StockTypeCode);

public:
	BOOL InsertStockItem(char* m_szStockId, int nKind, PSTOCK_TYPE_INFO& m_pStock);
	BOOL DeleteStockItem(char* m_szStockId, int nKind);  
	BOOL RemoveDeletedStock();
	BOOL Lookup(char* m_szStockId, int nKind, PSTOCK_TYPE_INFO& m_pStock);

public:
	BOOL GetChooseStockCode(SymbolKindArr& m_StockCodeArray);
	int GetChooseStockCounts();
	BOOL InsertStockToChoose(char* m_szStockId, int nKind);
	BOOL DeleteStockFromChoose(char* m_szStockId, int nKind);
};

inline void CSuperviseSharesBlockData::SaveDataToFile(LPCVOID lpBaseAddress, DWORD dwNumberOfBytesToFlush)
{
	FlushViewOfFile(lpBaseAddress, dwNumberOfBytesToFlush);
}

inline BYTE CSuperviseSharesBlockData::GetStockTypeNumber(char* m_szStockTypeCode)
{
	char mtemp[3];
	memcpy(mtemp, m_szStockTypeCode + 4, 2);
	mtemp[2] = '\0';
	return (BYTE)atoi(mtemp);
}

#endif // !defined(AFX_MANAGERSTOCKTYPEDATA_H__520245A1_5257_11D4_8829_00400552E583__INCLUDED_)