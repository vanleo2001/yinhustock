
#pragma once

//#include "Stockdrv.h"
#include "config.h"

enum TDXMarket
{
	tdxMarketShenZhen = 0,
	tdxMarketShangHai = 1,
};


enum TDX_COMMAND
{
	CMD_TEST				= 0x0526,

	CMD_HEART_BEAT			= 0x0523,
	CMD_KLINE				= 0x052C,
	CMD_HIS_TRANS			= 0x0FB5,		// ��ʷ�طţ���ʷ�ֱ�
	CMD_INSTANT_TRANS		= 0x0FC5,		// 0x0fc5, 0x0faf

	CMD_0D					= 0x000D,		// ��Ϣ
	CMD_LOGIN				= 0x001E,		// ��¼


	CMD_STOCK_LIST			= 0x0524,		// ��Ʊ�б���֤ȯ����ѯ
	CMD_CURRENT_PRICE		= 0x0531,

	CMD_HISREALTIME			= 0x0FB4,		// ��ʷ��ʱ



	CMD_STOCKHOLD_CHANGE	= 0x000F,		// �ɱ���Ȩ�ṹ
	CMD_STOCKPRICE			= 0x0010,		// �б�۸�

	CMD_FILEINFO			= 0x02C5,		// �ļ���Ϣ
	CMD_FILEDOWN			= 0x06B9,		// �����ļ�

	CMD_CODELIST			= 0x044E,		// ����������
	CMD_CODETABLE			= 0x0450,		// ��ʼ�������
};


#define TDX_FILEINFOLENGHT	0x28			// �����ļ���Ϣ�ĳ���
#define TDX_FILEDOWNLENGHT	0x64			// ���������ļ��ĳ���

struct TDX_REQFILE
{
	bool open;
	string filename;
	uint filesize;
	uint current;
	string filemd5;
};


struct TDX_REQKLINE
{
	ushort stock_market;
	char stock_code[6];
	ushort base_period;
	ushort period_count;
	ushort offset_start;
	ushort request_count;
};


struct TDX_REQUESTCMD
{
	uint seq_id;		// ���� seq_id
	ushort cmd;			// ����
	TDXMarket market;	// �г�
	char stock[10];		// ����
};
typedef map<uint, TDX_REQUESTCMD> TdxRequestMap;


typedef struct TDX_STOCKCODE
{
	string	stock_code;				// ֤ȯ���� 000001 600000
	string	stock_name;				// ֤ȯ���� �չ �ַ�����
	string	stock_short;			// ƴ����� SFZ PFYH
	uint16	stock_unit;				// ÿ�ֹ��� 100
	uint8	stock_digit;			// С��λ 
	float	stock_close;			// ǰ���̼� 
};
typedef map<string, TDX_STOCKCODE> StockCodeMap;


struct TDX_GBBQ
{
	TDXMarket	market;
	string		code;
	long		date;
	uchar		chg_type;
	// �������
	// 1: ����
	// 2: ��1��صĳ�Ȩ��Ϣ�չɱ��仯
	// 3: �ɱ����ʱ仯(����ְ��������)
	// 6: ����
	// 8: ��������
	union
	{
		struct 
		{
			float	old_cir;			// ����ͨ��
			float	old_ttl;			// ���ܹɱ�
			float	new_cir;			// ����ͨ��
			float	new_ttl;			// ���ܹɱ�
		} gb;
		struct
		{
			float	cash;				// ÿ10 �ֺ�
			float	sell_price;			// ÿ�����ۼ۸�
			float	give_count;			// ÿ10 ���͹���
			float	sell_count;			// ÿ10 ��������
		} bonus;
	} data;
};
typedef vector<TDX_GBBQ> DateGBBQ;
typedef map<uint, DateGBBQ> GBBQMap;
