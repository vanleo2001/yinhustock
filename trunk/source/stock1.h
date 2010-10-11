
#pragma once

#include <boost/date_time/gregorian/gregorian.hpp>
using namespace boost;

#include "config.h"
#include "TdxStructDef.h"
#include "stockdrv.h"

namespace StockMarket
{
	typedef vector<string> StringSet;

	struct MarketInfo
	{
		enum MarketType // tdxBlock
		{
			MARKET_SHANGHAI_A	= 0x00,			// ��֤A��  60xxxx (600...601...)
			MARKET_SHANGHAI_B	= 0x01,			// ��֤B��  90xxxx (900...)
			MARKET_SHENZHEN_A	= 0x02,			// ��֤A��  00xxxx 30xxxx (000...002...300...)
			MARKET_SHENZHEN_B	= 0x03,			// ��֤B��  20xxxx (200...)
			MARKET_SHANGHAI_Z	= 0x04,			// ��֤ծȯ 01...09xxxx 10...19xxxx 20xxxx 70...79xxxx 939xxx
			MARKET_SHENZHEN_Z	= 0x05,			// ��֤ծȯ 10...13xxxx 369xxx
			MARKET_STOCK_A		= 0x06,			// ����A��  
			MARKET_STOCK_B		= 0x07,			// ����B��  
			MARKET_STOCK_Z		= 0x08,			// ����ծȯ 
			MARKET_STOCK_J		= 0x09,			// ������� 15.16.18xxxx 50.51.52xxx
			MARKET_STOCK_ALL	= 0x0A,			// ������Ʒ 
			MARKET_INDEX		= 0x0B,			// ����ָ�� 39xxxx 00xxxx 88xx (395...399...000...888...)
			MARKET_ZHONGXIAO	= 0x0C,			// ��С��ҵ 
			MARKET_WARRANT		= 0x0D,			// ����Ȩ֤ 58xxxx (580...)
			MARKET_CUANGYE		= 0x0E,			// ��ҵ��
			MARKET_UNKNOWN,
		};

		static unsigned int stocks_count[16];
		static StringSet stocks_set[16];
		static StringSet stocks_set_all;

		const static int StocksCodeLen = 6;		// 100  ��һ��
		const static int StocksPerHand = 100;	// 100  ��һ��.
		const static float tax;					// 0.3 %

		static short get_market_type_from_code(const char* pCode)
		{
			//if (pCode[0] == '0')
			//{
				//if (pCode[1] == '0')
				//{
				//	return MARKET_SHENZHEN_A;	// ����A��  00xxxx 30xxxx (000...002...300...)
				//}
				//else if (pCode[1] == '1')
				//{
				//	return m1;		// �Ϻ�ծȯ
				//}
			//}
			//else if (pCode[0] == '2')
			//{
			//	return MARKET_SHENZHEN_B;		// ����B��  20xxxx (200...)
			//}
			//else if (pCode[0] == '3')
			//{
			//	if (pCode[1] == '0')
			//	{
			//		return MARKET_SHENZHEN_A;	// ����A��  00xxxx 30xxxx (000...002...300...)
			//	}
			//	else if (pCode[1] == '9')
			//	{
			//		return MARKET_INDEX;		// ����ָ�� 39xxxx 00xxxx 88xx (395...399...000...888...)
			//	}
			//}
			//else if (pCode[0] == '6')
			//{
			//	return MARKET_SHANGHAI_A;		// �Ϻ�A��  60xxxx (600...601...)
			//}
			//else if (pCode[0] == '9')
			//{
			//	if (pCode[1] == '0')
			//	{
			//		return MARKET_SHANGHAI_B;	// �Ϻ�B��  90xxxx (900...)
			//	}
			//	else
			//	{
			//		return MARKET_INDEX;		// 99xxxx
			//	}
			//}
			//else if (pCode[0] == '1' || (pCode[0] == '3' && pCode[1] == '6'))
			//{
			//	return m2;						// ����ծȯ 10...13xxxxxx,36xxxxxx
			//}
			//else if (pCode[0] == '5')
			//{
			//	return MARKET_WARRANT;			// ����Ȩ֤ 580xxx
			//}
			//else
			//{
			//	return m1;
			//}

			return 0;
		}

		static short get_market_type(const char* pCode)
		{
			return get_market_type_from_code(pCode);
		}

		static short get_market_type(const string& stock_code)
		{
			const char* pCode = stock_code.c_str();
			return get_market_type_from_code(pCode);
		}

		static char get_market_location_from_code(const char* pCode)
		{
			if(pCode[0] <= '4')
				return 0;					// ���� 00xxxx, 03xxxx, 02xxxx, 3xxxxx(����ָ��)
			else
				return 1;					//�Ϻ� 60xxxxx, 58xxxx, 99xxxx (�Ϻ�ָ��)
		}

		static char get_market_location(const char* pCode)
		{
			return get_market_location_from_code(pCode);
		}

		static char get_market_location(const string& stock_code)
		{
			const char* pCode = stock_code.c_str();
			return get_market_location_from_code(pCode);
		}

		static string get_first_stock();
		static string find_next_stock(const string& stock_code);
	};



	struct StockTransact
	{
		short		minute;
		int			price;
		int 			vol;
		int 			count;	// �˱ʳɽ����ĳɽ������� 0: ��ʾδ֪
		uchar		bs;		// ��ʾ��ɽ����������ɽ���0:buy, 1:sell
		bool operator == (const StockTransact& t);
	};
	typedef vector<StockTransact> DailyTransact;
	typedef map<string, DailyTransact> DateTransact;

	extern DateTransact		today_transact;

	struct StockBid			// �̿�
	{
		int			minute;
		int			act;				// ��Ծ�� active rate

		int			price;			// �ּ�
		int			y_close;			// ����
		int			open;			// ����
		int			high;			// ���
		int			low;				// ���
		int			buy;			// ����
		int			sell;			// ����

		int			total_vol;		// ���֣��Թ�������
		int			avail_vol;		// ���֣��Թ�������
		int			inner_vol;		// ����
		int			outer_vol;		// ����

		int			updown;			// ��������

		int			buy_price1;	// ���1
		int			sell_price1;
		int			buy_vol1;	// ����1
		int			sell_vol1;
		int			buy_price2;
		int			sell_price2;
		int			buy_vol2;
		int			sell_vol2;
		int			buy_price3;
		int			sell_price3;
		int			buy_vol3;
		int			sell_vol3;
		int			buy_price4;
		int			sell_price4;
		int			buy_vol4;
		int			sell_vol4;
		int			buy_price5;
		int			sell_price5;
		int			buy_vol5;
		int			sell_vol5;
	};
	typedef vector<StockBid> DailyBid;




	extern uint date_to_uint(gregorian::date);
	extern gregorian::date uint_to_date(uint);




	struct BaseInfo
	{
		string		stock_code;				// ����
		uint		update_time;			// ����ʱ��
		double		ttl_amount;				// �ܹɱ�
		double		state_own_amount;		// ���ҹ�
		double		init_amount;			// ����ɱ�
		double		corp_amount;			// ���˹ɱ�
		double		b_amount;				// B �ɱ�
		double		h_amount;				// H �ɱ�
		double		cir_amount;				// ��ͨ �ɱ�
		double		empl_amount;			// ְ�� �ɱ�
		double		unknown1;				// 
		double		ttl_asset;				// ���ʲ�
		double		varible_asset;			// ���� �ʲ�
		double		firm_asset;				// �̶� �ʲ�
		double		invisible_asset;		// ���� �ʲ�
		double		long_term_invest;		// ����Ͷ��
		double		varible_debt;			// ������ծ
		double		long_term_debt;			// ���ڸ�ծ
		double		accu_fund;				// ������
		double		net_asset;				// ���ʲ�
		double		major_income;			// ��Ӫ����
		double		major_profit;			// ��Ӫ����
		double		unknown2;				// 
		double		bussiness_income;		// Ӫҵ����
		double		invest_income;			// Ӫҵ����
		double		allowance;				// ��������
		double		non_bussiness_income;	// ҵ������
		double		income_adjustment;		// �������
		double		ttl_profit;				// �����ܶ�
		double		unknown3;				// 
		double		net_profit;				// ˰������
		double		undist_profit;			// δ��������
		double		per_net_assert2;		// ÿ�ɾ��ʲ�2

		static const int record_len;
	};

	typedef map<string, BaseInfo> StockBaseInfoMap;

	extern fstream& operator >> (fstream& fs, BaseInfo& bs);

	typedef vector<string> StringVector;
	typedef map<string, StringVector> StockGroupMap;

	class StockBasicInfo
	{
	public:
		StockBaseInfoMap stock_base_info;
		StockGroupMap stock_block_info;

	public:
		// ���ػ�������
		bool load_basic_info();
		bool load_block_info();

		void clear_gbbq_info();
		bool is_gbbq_file_exist(uint tr_date);
		GBBQMap			stock_gbbq_info;
	};




	const int stockocde_len = 0xFA;

	extern uint16 g_marketcount[2];
	extern uint16 g_marketinit[2];
	extern StockCodeMap g_stocklist[2];

	extern TDX_REQFILE g_stockfile;

	extern TdxRequestMap g_stockrequest;

	// ����֤ȯ�����
	int load_stock_code(TDXMarket market);

	extern void AddStockListRequest(bool bAll);
	extern void AddGBBQRequest();

	typedef deque<RCV_DATA*> sendlistd;
	extern sendlistd g_sendlist;

	void communication();
}
