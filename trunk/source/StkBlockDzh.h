
#if !defined(AFX_BLOCKTYPEMANAGER_H__88285B9B_F502_4982_8948_95BC91DDD7CC__INCLUDED_)
#define AFX_BLOCKTYPEMANAGER_H__88285B9B_F502_4982_8948_95BC91DDD7CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStkBlockDzh  
{
public:
	CStkBlockDzh();
	virtual ~CStkBlockDzh();

private:
	CString m_sNameFileType;

public:
	// ��ȡ�����еİ���б� ��ҵ => ���� ������
	void EnumBlockNames(CString sTypeName, CStringArray& sBlockNameArr);

	// ��ȡ����еĹ�Ʊ�б� ����.BLK => SH600000 ������
	void ReadSymbols(CString sBlockName, CStringArray& sSymbolsArr);

public:
	// ��ȡ���а����� ��ҵ ���� ������
	void EnumAllType(CStringArray& sTypeArr);
	int AddBlockType(CString sName);
	void DeleteBlockType(CString sName);

public:
	void DeleteSymbols(CString sBlockName, CStringArray &sSymbolsArr);
	void AddSymbols(CString sBlockName,CStringArray &sSymbolsArr);
	int ModifyBlockTypeName(CString sOldName,CString sNewName);

protected:
	void DeleteSymbols(CString sBlockName, CStringArray &sSymbolsArr,BOOL bAppend);
};

#endif // !defined(AFX_BLOCKTYPEMANAGER_H__88285B9B_F502_4982_8948_95BC91DDD7CC__INCLUDED_)
