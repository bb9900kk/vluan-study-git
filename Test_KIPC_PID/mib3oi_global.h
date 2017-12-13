#ifndef __MIB3OI_GLOBAL_H__
#define __MIB3OI_GLOBAL_H__

#ifdef __cplusplus
extern "C" {
#endif

#if defined(MIB3_MQB)
	#define MIB3OI_VERSION_PREFIX	"X"
#elif defined(MIB3_MQB37)
	#define MIB3OI_VERSION_PREFIX	"Y"
#else
	#error "unkown platform define"
#endif

#define MIB3OI_VERSION_NUMBER		"513"
#define MIB3OI_VERSION_NUMBER_MINOR	".00"

// for external usage && official version display
#define MIB3OI_VERSION_SHORT		MIB3OI_VERSION_PREFIX MIB3OI_VERSION_NUMBER		// ex) "X510" 

// for internal usage
#define MIB3OI_VERSION_FULL		MIB3OI_VERSION_SHORT MIB3OI_VERSION_NUMBER_MINOR	// ex) "X510.00"

typedef enum _E_PLATFORM_DEF 
{
	E_PLATFORM_MQB 		= 0x00,		// mqb platform
	E_PLATFORM_MQB37	= 0x01,		// mqb37 platform
	
	E_PLATFORM_DEF_MAX
} E_PLATFORM_DEF;

typedef enum _E_VARIANT_DEF
{
	E_VARIANT_LOW		= 0x00,		// low variant, RAM 4GB, eMMC 32GB
	E_VARIANT_HIGH		= 0x01,		// high variant, RAM 6GB, eMMC 64GB

	E_VARIANT_DEF_MAX
} E_VARIANT_DEF;

typedef enum _E_SPEAKER_CONF
{
	E_SPEAKER_CH4		= 0x04,		// 4 channel speaker
	E_SPEAKER_CH6		= 0x06,		// 6 channel speaker

	E_SPEAKER_CONF_MAX
} E_SPEAKER_CONF;

typedef enum _E_MARKET_DEF
{
	E_MARKET_EU		= 0x00,		// eu market
	E_MARKET_NAR		= 0x01,		// nar market
	E_MARKET_RDW1		= 0x02,		// rdw1 market(rest of world) -> without gnss module
	E_MARKET_RDW2		= 0x03,		// rdw2 market(rest of world) -> with gnss module
	E_MARKET_CHINA		= 0x04,		// china market, not offered
	E_MARKET_KOREA		= 0x05,		// korea market, not offered
	E_MARKET_JAPEN		= 0x06,		// japen market, not offered
	E_MARKET_TAIWAN		= 0x07,		// taiwan market, not offered
	E_MARKET_RUSSIA		= 0x08,		// russia market

	E_MARKET_DEF_MAX
} E_MARKET_DEF;

typedef enum _E_BRAND_DEF
{
	E_BRAND_VW		= 0x00,		// vw
	E_BRAND_SK		= 0x01,		// skoda
	E_BRAND_SE		= 0x02,		// seat
	E_BRAND_AUDI		= 0x03,		// audi
	E_BRAND_PAG		= 0x04,		// pag
	E_BRAND_MAN		= 0x05,		// man, truck
	E_BRAND_SCANIA		= 0x06,		// scania, truck

	E_BRAND_DEF_MAX
} E_BRAND_DEF;

typedef enum _E_GNSS_DEF
{
	E_GNSS_WITHOUT		= 0x00,		// without gnss => rdw1 market
	E_GNSS_WITH		= 0x01,		// with gnss => rdw2 market

	E_GNSS_DEF_MAX
} E_GNSS_DEF;

typedef enum _E_TUNER_CONF
{
	E_TUNER_TITAN		= 0x01,		// with titan
	E_TUNER_MERCURY		= 0x02,		// with mercury
	E_TUNER_MERLIN		= 0x04,		// with merlin
	E_TUNER_SDARS		= 0x08,		// with sdars
	E_TUNER_HD15		= 0x10,		// with hd 1.5 
	E_TUNER_HD25		= 0x20,		// with hd 2.5
	E_TUNER_DAB15		= 0x40,		// with dab 1.5
	E_TUNER_DAB25		= 0x80,		// with dab 2.5

	E_TUNER_CONF_MAX
} E_TUNER_CONF;

typedef enum _E_RESOLUTION_DEF 
{
	E_RESOLUTION_800X480	= 0x01,		// 8" ABT, 800x480 
	E_RESOLUTION_1280X640	= 0x02,		// 9.2" ABT, 1280x640
	E_RESOLUTION_1560X700	= 0x03,		// 10" ABT, 1560x700
	
	E_RESOLUTION_DEF_MAX
} E_RESOLUTION_DEF;

#if defined (MIB3_MQB)
typedef enum _E_VARIANT_MQB_DEF
{
// VW
	VW_ZR_PKW_RADIO_R4N_4CH_EU		= 1,	// P/N = 3G5 035 819, vw low variant
	VW_ZR_PKW_RADIO_R4N_4CH_DAB_EU		= 4,	// P/N = 3G5 035 820
	VW_ZR_PKW_RADIO_R4N_4CH_RDW1		= 7,	// P/N = 3G5 035 824
	VW_ZR_PKW_RADIO_R4N_4CH_RDW2		= 10,	// P/N = 3G5 035 832
	VW_ZR_PKW_RADIO_R4N_4CH_SIRIUS_NAR	= 13,	// P/N = 3G5 035 842
	VW_ZR_PKW_NAV_4CH_DAB_EU		= 33, 	// P/N = 3G5 035 816, vw high variant
	VW_ZR_PKW_NAV_4CH_RDW1			= 36,	// P/N = 3G5 035 874
	VW_ZR_PKW_NAV_4CH_RDW2			= 38, 	// P/N = 3G5 035 876
	VW_ZR_PKW_NAV_4CH_SIRIUS_NAR		= 39,	// P/N = 3G5 035 877
// SEAT	
	SE_ZR_PKW_RADIO_R4N_4CH_EU	= 3,	// P/N = 6F0 035 819, se low variant
	SE_ZR_PKW_RADIO_R4N_4CH_DAB_EU	= 6,	// P/N = 6F0 035 820
	SE_ZR_PKW_RADIO_R4N_4CH_RDW1	= 9,	// P/N = 6F0 035 824
	SE_ZR_PKW_RADIO_R4N_4CH_RDW2	= 12,	// P/N = 6F0 035 832
	SE_ZR_PKW_RADIO_R4N_6CH_EU	= 21,	// P/N = 575 035 834
	SE_ZR_PKW_RADIO_R4N_6CH_DAB_EU	= 23,	// P/N = 575 035 858
	SE_ZR_PKW_RADIO_R4N_6CH_RDW1	= 24,	// P/N = 575 035 848
	SE_ZR_PKW_RADIO_R4N_6CH_RDW2	= 26,	// P/N = 575 035 838
	SE_ZR_PKW_NAV_6CH_EU		= 47,	// P/N = 575 035 814, se high variant
	SE_ZR_PKW_NAV_6CH_DAB_EU	= 49,	// P/N = 575 035 862
	SE_ZR_PKW_NAV_6CH_RDW1		= 50,	// P/N = 575 035 867
	SE_ZR_PKW_NAV_6CH_RDW2		= 52,	// P/N = 575 035 868

	E_VARIANT_MQB_DEF_MAX
} E_VARIANT_MQB_DEF;

#elif defined (MIB3_MQB37)

typedef enum _E_VARIANT_MQB37_DEF
{
// VW
	VW_ZR_PKW_NAV_KLEIN_4CH_AMFM_EU		= 1,	// P/N = 5H0 035 819, vw low variant
	VW_ZR_PKW_NAV_KLEIN_4CH_DAB_EU		= 4,	// P/N = 5H0 035 820
	VW_ZR_PKW_NAV_KLEIN_4CH_AMFM_RDW1	= 7,	// P/N = 5H0 035 824
	VW_ZR_PKW_NAV_KLEIN_4CH_AMFM_RDW2	= 10,	// P/N = 5H0 035 832
	VW_ZR_PKW_NAV_KLEIN_4CH_HD15_RDW2	= 14,	// P/N = 5H0 035 812
	VW_ZR_PKW_NAV_KLEIN_4CH_SIRIUS_NAR	= 13,	// P/N = 5H0 035 842
	VW_ZR_PKW_NAV_GROB_4CH_AMFM_DAB_EU	= 26,	// P/N = 5H0 035 816, vw high variant
	VW_ZR_PKW_NAV_GROB_4CH_AMFM_RDW1	= 29,	// P/N = 5H0 035 874
	VW_ZR_PKW_NAV_GROB_4CH_AMFM_RDW2	= 31,	// P/N = 5H0 035 876
	VW_ZR_PKW_NAV_GROB_4CH_HD15_RDW2	= 33,	// P/N = 5H0 035 875
	VW_ZR_PKW_NAV_GROB_4CH_SIRIUS_NAR	= 32,	// P/N = 5H0 035 877
// SEAT
	SE_ZR_PKW_NAV_KLEIN_4CH_AMFM_EU		= 3, 	// P/N = 5FA 035 819, se low variant
	SE_ZR_PKW_NAV_KLEIN_4CH_DAB_EU		= 6, 	// P/N = 5FA 035 820
        SE_ZR_PKW_NAV_KLEIN_4CH_AMFM_RDW1       = 9,	// P/N = 5FA 035 824
        SE_ZR_PKW_NAV_KLEIN_4CH_AMFM_RDW2       = 12,	// P/N = 5FA 035 832
        SE_ZR_PKW_NAV_KLEIN_6CH_AMFM_EU       	= 22,	// P/N = 5FA 035 834
        SE_ZR_PKW_NAV_KLEIN_6CH_DAB_EU      	= 23,	// P/N = 5FA 035 858
        SE_ZR_PKW_NAV_KLEIN_6CH_AMFM_RDW1      	= 24,   // P/N = 5FA 035 848
        SE_ZR_PKW_NAV_KLEIN_6CH_AMFM_RDW2       = 25,	// P/N = 5FA 035 838
        SE_ZR_PKW_NAV_GROB_6CH_AMFM_DAB_EU      = 41,	// P/N = 5FA 035 862, se high variant
        SE_ZR_PKW_NAV_GROB_6CH_AMFM_RDW1        = 42,	// P/N = 5FA 035 867
        SE_ZR_PKW_NAV_GROB_6CH_AMFM_RDW2        = 43,	// P/N = 5FA 035 868

	E_VARIANT_MQB37_DEF_MAX
} E_VARIANT_MQB37_DEF;

#else
#error "unknown platform define"
#endif

#ifdef __cplusplus
}
#endif

#endif 




