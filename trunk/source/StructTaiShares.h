#ifndef __WSSTOCKSTRUCT_1000_H__
#define __WSSTOCKSTRUCT_1000_H__
// by ����¼
#define CALLOC(n,x)    ((x *) farcalloc((long)(n),sizeof(x)))
#define FREE(x)        farfree(x)

#define MaxRights 3
#define MaxStockTYpe 102
#define MAXJISHUCOUNT 10


typedef struct
{
		float 	Price;     
		float 	Volume;   
		float 	Amount;   
    
}Kdata1;
typedef struct
{
		float 	Price;     
		float 	Volume;    
		float 	Amount;    
        float   accb;      
        float   accs;     
	    float   bsspbas;  
		float   dif_accb;  
		float   dif_accs;   
}DpKdata1;
typedef struct 
{
	int   nFlags;
	int	  nTime;
	float Give;
	float Allocate;
	float AllocatePrice;
	float Bonus;
	BYTE Free[4];
}Split ,*PSplit;


typedef struct
{
	char Symbol[10];  //��Ʊ����
	int  NumSplit;   //�Ѿ���Ȩ����
	float zgb;     //�ܹɱ�(���)
	float gjg;     //���ҹ�(���)
	float fqrfrg;  //�����˷��˹�(���)
	float frg;     //���˹�(���)
	float zgg;     //ְ����(���)
	float gzAg;    //����A��(���)    5
	float ltAg;    //��ͨA��(���)
	float Hg;      //�ȹ�(���)
	float Bg;      //B��(���)
	float zpg;     //ת���(���)

	float zzc;     //���ʲ�(��Ԫ)    10
	float ldzc;    //�����ʲ�(��Ԫ)
	float cqtz;    //����Ͷ��(��Ԫ)
	float gdzc;    //�̶��ʲ�(��Ԫ)
	float wxzc;    //�����ʲ�(��Ԫ)
	float ldfz;    //������ծ(��Ԫ)   15
	float cqfz;    //���ڸ�ծ(��Ԫ)
	float ggqy;    //�ɶ�Ȩ��(��Ԫ)
	float zbgjj;   //�ʱ�������(��Ԫ)
	float yygjj;   //ӯ�๫����(��Ԫ)
	float mgjz;    //ÿ�ɾ�ֵ(Ԫ)    20
	float gdqybl;  //�ɶ�Ȩ�����(%)
	float mggjj;   //ÿ�ɹ�����(Ԫ)

	float zyywsr;  //��Ӫҵ������(��Ԫ)
	float zyywlr;  //��Ӫҵ������(��Ԫ)
	float qtywlr;  //����ҵ������(��Ԫ)25
	float lrze;    //�����ܶ�(��Ԫ)
	float jlr;     //������(��Ԫ)
	float wfplr;   //δ��������(��Ԫ)
	float mgsy;    //ÿ������(Ԫ)
	float jzcsyl;  //���ʲ�������(%)  30
	float mgwfplr; //ÿ��δ��������(Ԫ)

	float mgjzc;   //ÿ�ɾ��ʲ�(Ԫ)

	int m_iPos;
	BYTE  free[8];
	Split m_Split[80];
}BASEINFO;
typedef BASEINFO *PBASEINFO;
typedef struct
{
	char Symbol[8];  //��Ʊ����
	int  NumSplit;   //�Ѿ���Ȩ����
	float zgb;     //�ܹɱ�(���)
	float gjg;     //���ҹ�(���)
	float fqrfrg;  //�����˷��˹�(���)
	float frg;     //���˹�(���)
	float zgg;     //ְ����(���)
	float gzAg;    //����A��(���)
	float ltAg;    //��ͨA��(���)
	float Hg;      //�ȹ�(���)
	float Bg;      //B��(���)
	float zpg;     //ת���(���)

	float zzc;     //���ʲ�(��Ԫ)
	float ldzc;    //�����ʲ�(��Ԫ)
	float cqtz;    //����Ͷ��(��Ԫ)
	float gdzc;    //�̶��ʲ�(��Ԫ)
	float wxzc;    //�����ʲ�(��Ԫ)
	float ldfz;    //������ծ(��Ԫ)
	float cqfz;    //���ڸ�ծ(��Ԫ)
	float ggqy;    //�ɶ�Ȩ��(��Ԫ)
	float zbgjj;   //�ʱ�������(��Ԫ)
	float yygjj;   //ӯ�๫����(��Ԫ)
	float mgjz;    //ÿ�ɾ�ֵ(Ԫ)
	float gdqybl;  //�ɶ�Ȩ�����(%)
	float mggjj;   //ÿ�ɹ�����(Ԫ)

	float zyywsr;  //��Ӫҵ������(��Ԫ)
	float zyywlr;  //��Ӫҵ������(��Ԫ)
	float qtywlr;  //����ҵ������(��Ԫ)
	float lrze;    //�����ܶ�(��Ԫ)
	float jlr;     //������(��Ԫ)
	float wfplr;   //δ��������(��Ԫ)
	float mgsy;    //ÿ������(Ԫ)
	float jzcsyl;  //���ʲ�������(%)
	float mgwfplr; //ÿ��δ��������(Ԫ)

	float mgjzc;   //ÿ�ɾ��ʲ�(Ԫ)

	int m_iPos;
	BYTE  free[8];
	Split m_Split[80];
}BASEINFO_OLD;
typedef BASEINFO_OLD *PBASEINFO_OLD;
typedef struct
{
	int DayAddr;
	int Min5Addr;
	BASEINFO *pBaseInfo;
	int HsAddr;
	char Free[8];
}MapFileAddr;

typedef struct
{
	long m_lFileTitle;        
    long m_lFileExit;          
	long m_lStockTypeCount;   
    long m_lStockTypeMaxCount; 
    long m_lStockCount;      
    long m_lStockMaxCount;    
	long m_lLastTime;         

}STOCKTYPEHEAD;
typedef STOCKTYPEHEAD *PSTOCKTYPEHEAD;


typedef struct
{
    long m_lIsUse;        
	char m_szCode[7];     
    char m_szName[12];    
	long m_lStockCount;    
    float m_fTotalRight;   
	float m_fNewIndex;     
	float m_fYstIndex;    
	float m_fOpenIndex;
	float m_fHighIndex;   
	float m_fLowIndex;    
	float m_fTotP;      
	float m_fTotV;        
	float m_fTotRVol;   
	float m_fTotDVol;     
    int  m_iRightType;    
    BOOL m_bIsDelete;      
}STOCKTYPEINFO;
typedef STOCKTYPEINFO *PSTOCKTYPEINFO;
typedef struct
{
	char m_szSymbol[9];	
	BOOL m_bDeleted;
	int m_iPos;
	float m_ClosePrice;
    float m_fRight[MaxRights];    
    BYTE  m_btStockType[MaxStockTYpe];    
}STOCK_TYPE_INFO;
typedef STOCK_TYPE_INFO *PSTOCK_TYPE_INFO;
typedef struct
{
	STOCK_TYPE_INFO *pStockInfo;
}STOCK_POINT_INFO;

//======================
typedef struct
{
	char m_szSymbol[7];
	BOOL m_bDeleted;
	int m_iPos;
	float m_ClosePrice;
    float m_fRight[MaxRights];   
    BYTE  m_btStockType[MaxStockTYpe];    
}STOCK_TYPE_INFO_OLD;



typedef struct
{
	BYTE header[32];
	BYTE kind;
	BYTE rdp;			// ���ڼ������ǿ��ָ��
	WORD wMarket;		// ֤ȯ�г�
	char id[8];			// ֤ȯ����
	char name[10];		// ֤ȯ���� 
	char Gppyjc[6];		// ֤ȯ����ƴ�����
	int sel;
	float ystc;			// ��������
	float opnp;			// ���տ��� 
	float higp;			// �������
	float lowp;			// �������
	float nowp;			// ���¼۸�
	float nowv;			// ���³ɽ���
	float totv;			// �ܳɽ���
	float totp;			// �ܳɽ����
	float pbuy1;		// �����һ
	float vbuy1;		// ������һ
	float pbuy2;		// ����۶�
	float vbuy2;		// ��������
	float pbuy3;		// �������
	float vbuy3;		// ��������
	float pbuy4;
	float vbuy4;
	float pbuy5;
	float vbuy5;
	float psel1;		// ������һ
	float vsel1;		// ������һ
	float psel2;		// �����۶�
	float vsel2;		// ��������
	float psel3;		// ��������
	float vsel3;		// ��������
	float psel4;
	float vsel4;
	float psel5;
	float vsel5;
	float accb;
	float accs;
	float volume5;
	float rvol;
	float dvol;
	BYTE none[40];

	short lastclmin;
	short initdown;
	int InOut;
	BOOL IsDelete;
	BOOL IsMxTj;

	float Index[10];
	Kdata1 m_Kdata1[244];
	BASEINFO* pBaseInfo;
	STOCK_TYPE_INFO* pStockTypeInfo;

	int	m_serialNumber;
} CReportData;
typedef CReportData* PCdat1;


typedef struct _tagSTOCKDATASHOW
{
	CReportData* pItem;
	WORD wMarket;
	char StockId[7];
	float ItemData;
} STOCKDATASHOW;
typedef STOCKDATASHOW* PSTOCKDATASHOW;


typedef struct
{
 char name[9];          
 float ystc;
 float nowp;            
 float nowb;            
 float nows;           
 float nowv;            
 BOOL InOut;
 char kind;
}CUOHEDATA;


typedef struct
{
 float ystc;                
 float nowi;             
 float opni;             
 float higi;             
 float lowi;              
 float nowp;             
 float nowv;             
 float accb;             
 float accs;           
 float bsspbas;          
 float dif_accb;        
 float dif_accs;         
 float volume5;         

 float StartP;            
 float EndP;         


 float totp;            
 float totv;             
 float lastaccb;         
 float lastaccs;         
 float lasttotb;                        
 float lasttots;
 float lasttotp;                      
 float lasttotv;               

 DpKdata1 *m_DpKdate;           
} Aidx1;

typedef struct
{
 short rsn;       
 short dnn;
} Rsdn1;

typedef Rsdn1 **PRsdn1;



typedef struct
{
 short sec5;              
 short rp;              
 short dp;              
 short res;
} Tidxd;
typedef Tidxd **PTidxd;



typedef struct _tagREALDATA
{
	long filetitle;
	long Day;
	short OldANT[3];
	BOOL CloseWorkDone;
	long StockCount;
	long MaxStockCount;
	long FileExitDone;
	BYTE Res[12];
} REALDATA;
typedef REALDATA* PREALDATA;



typedef struct
{
	long filetitle;            
	long FileExitDone;
	long StockCount;
	long MaxStockCount;
    long FixedNumSplit;
	BYTE Res[20];
}BASEINFOHEAD;
typedef BASEINFOHEAD *PBASEINFOHEAD;

typedef struct _BIG_LIST
{
	char id[8];
	char name[10];
	int nKind;
	time_t ntime;
	int  ntype; 
	float nowv; 
	float nowp;  
	float rdr;
}BIG_LIST;
typedef BIG_LIST *PBIG_LIST;
typedef struct _BIG_LISTHEAD
{
	BOOL Done;
	BOOL IsGbjg;
	BOOL IsChange;
	float BigSet[4];
	float BigMaxSet[4];
	float BigBillSetType[10];
	float BigSetGB[4];
	float BigMaxSetGB[4];
	float BigBillSetTypeGB[10];
    long ItemCount ;
	long MaxItemCount;
	long totalBigCount[4];
	float totalBigVolumn[4];
	long totalCount[10];
	float totalVolumn[10];
    float totalV;
	BOOL IsCalc[4];
	BOOL IsSaveData;
}BIG_LISTHEAD;
typedef BIG_LISTHEAD *PBIG_LISTHEAD;
//
typedef struct _SHARES_DATA_ADD
{
	char name[10];
	int  StockType;
}SHARES_DATA_ADD;



typedef struct  NameSymbolStr 
{
        char   stocksymblo[7];
		char   stockname[9];
		char   stockhypy[5];
		char   group;
}NAMESYMBOL;


typedef struct  tagMIN_TOTAL_STRUCTEx 
{
	RCV_MINUTE_STRUCTEx *m_RcvMinute;    
	long Min_Count;                      

}MIN_TOTAL_STRUCTEx;


typedef struct  tagDAY_TOTAL_STRUCTEx 
{
	RCV_HISTORY_STRUCTEx *m_RcvDay;   
	long Day_Count;                      

}DAY_TOTAL_STRUCTEx;
typedef struct  tagPOWER_TOTAL_STRUCTEx 
{
	RCV_POWER_STRUCTEx *m_RcvPower;   
	long Power_Count;                   

}POWER_TOTAL_STRUCTEx;

/////////////////////////////////////////////////////////////

struct TAI_SHAN_DATA
{
		int	    nTime;
		float	fOpen;	
		float	fHigh;		
		float	fLow ;	
		float 	fClose;     
		float 	fVolume;   
		float	fAmount;    
		WORD    wAdvance;  
		WORD    wDecline;   
};

////////////////////////////////////////////////

struct KLINEHEAD
{
	int	NumChuQPerBlk;	   	
	int	numPerBlk	;		
	int	numKline_sh	;		
	int	numBlkAll_sh;		
	int numKline_sz	;	       
	int numBlkAll_sz;	     
};

struct KLINESMALLHEAD
{
	char    StockSign[8]; 
	short 	numChuQ	;	  
	long    numKln	;	
	short   symBlock[25]; 
	long    index;
};


struct MINUTEKLINEHEAD
{
	char    StockSign[8];
	long    numKln	;	  
	long    pPos;        
	long    symBlock;    
};

struct MKLINEHEAD
{
	int	numPerBlk	;		
	int	numKline_sh	;	
	int numKline_sz	;
};

typedef struct
{
  time_t day;
  float opn;
  float hig;
  float low;
  float clo;
  float vol;
  float amt;
  short adv;
  short dec;
} Misd;

typedef struct
{
  char  m_zqdm[7]; 
  float SortID;
} SORTSTRUCT;


typedef struct
{
	long day;
	Misd misd[48];
}MINUTEData;


typedef struct _ADD_DATA_DAY_LINE
{
	char DayLineName[10];
	int  DayLineType;
}ADDDAYLINEDATA;

typedef struct _tagIndex_Technique
{
       int  iKind;                   
       char sIndex_name[50];          
       int  iLine;                   
       int  iDataType;                 
       float fParam[8];               
       float fSubParam1;            
       float fSubParam2;              
       int  iSunIndex;               
	   char SubLineType[10];
}Index_Technique;

typedef struct _TECHNIQUE_COLUMN{ 
    UINT     nID ;      
	Index_Technique nIndex;
	BOOL IsUse;
} TECHNIQUE_COLUMN ,*PTECHNIQUE_COLUMN; 

typedef struct _NineViewData
{
	int minutecount;
	BOOL IsDay;
	UINT showtype;
}NineViewData;

typedef struct _TotalNineViewData
{
	int NineInitDone;
    NineViewData m_NineViewDate[9];
}TotalNineViewData;


typedef struct _SystemInitData
{
	int InitComplete;
    char StockTypeName[20];     
	char ScreenStockName[20];    
	int  ColumnIndex[30]; 
	int  ColumnType;               
	int  ColumnWidth[30];  
	TECHNIQUE_COLUMN TechniqueColumn[MAXJISHUCOUNT];     
    char NetAddr[255];               
	char KswtAddr[255];          
    int  RealTime;                
	int  BlockTime;                    
	TotalNineViewData m_TotalNineViewData;
}SYSTEMINITDATA;	 







#endif 
