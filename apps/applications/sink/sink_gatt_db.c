/*
 * THIS FILE IS AUTOGENERATED, DO NOT EDIT!
 *
 * generated by gattdbgen from sink_gatt_db.db_
 */

#include <panic.h>
#include <string.h>
#include "sink_gatt_db.h"

/* Static GATT database */
const uint16 gattDatabase[] = {
    /* 0001: Primary Service 1801 */
    0x0002, 0x0118,
    /* 0002: Characteristic Declaration 2a05 */
    0x3005, 0x2003, 0x0005, 0x2a00,
    /* 0003:  */
    0xd000,
    /* 0004: Client Characteristic Configuration */
    0x6402, 0x0000,
    /* 0005: Primary Service 1800 */
    0x0002, 0x0018,
    /* 0006: Characteristic Declaration 2a00 */
    0x3005, 0x0207, 0x0000, 0x2a00,
    /* 0007:  */
    0xd400,
    /* 0008: Characteristic Declaration 2a01 */
    0x3005, 0x0209, 0x0001, 0x2a00,
    /* 0009:  */
    0xd400,
    /* 000a: Primary Service 1804 */
    0x0002, 0x0418,
    /* 000b: Characteristic Declaration 2a07 */
    0x3045, 0x020c, 0x0007, 0x2a00,
    /* 000c: . */
    0xd401, 0x0000,
    /* 000d: Primary Service 1802 */
    0x0002, 0x0218,
    /* 000e: Characteristic Declaration 2a06 */
    0x3005, 0x040f, 0x0006, 0x2a00,
    /* 000f: . */
    0xd501, 0x0000,
    /* 0010: Primary Service 1803 */
    0x0002, 0x0318,
    /* 0011: Characteristic Declaration 2a06 */
    0x3045, 0x0a12, 0x0006, 0x2a00,
    /* 0012: . */
    0xd501, 0x0000,
    /* 0013: Primary Service 00001100-d102-11e1-9b23-00025b00a5a5 */
    0x0010, 0xa5a5, 0x005b, 0x0200, 0x239b, 0xe111, 0x02d1, 0x0011, 0x0000,
    /* 0014: Characteristic Declaration 00001101-d102-11e1-9b23-00025b00a5a5 */
    0x3013, 0x0815, 0x00a5, 0xa500, 0x5b02, 0x0023, 0x9be1, 0x1102, 0xd101, 0x1100, 0x0000,
    /* 0015: . */
    0xcd01, 0x0000,
    /* 0016: Characteristic Declaration 00001102-d102-11e1-9b23-00025b00a5a5 */
    0x3013, 0x1217, 0x00a5, 0xa500, 0x5b02, 0x0023, 0x9be1, 0x1102, 0xd102, 0x1100, 0x0000,
    /* 0017: . */
    0xcc01, 0x0000,
    /* 0018: Client Characteristic Configuration */
    0x6c00,
    /* 0019: Characteristic Declaration 00001103-d102-11e1-9b23-00025b00a5a5 */
    0x3053, 0x161a, 0x00a5, 0xa500, 0x5b02, 0x0023, 0x9be1, 0x1102, 0xd103, 0x1100, 0x0000,
    /* 001a: . */
    0xcd01, 0x0000,
    /* 001b: Client Characteristic Configuration */
    0x6c00,
    /* 001c: Primary Service 180f */
    0x0002, 0x0f18,
    /* 001d: Characteristic Declaration 2a19 */
    0x3005, 0x121e, 0x0019, 0x2a00,
    /* 001e: . */
    0xd401, 0x0000,
    /* 001f: Characteristic Presentation Format, rfu, 0 */
    0x8c07, 0x0000, 0x0000, 0x0000, 0x0000,
    /* 0020: Client Characteristic Configuration */
    0x6c00,
    /* 0021: Primary Service 180f */
    0x0002, 0x0f18,
    /* 0022: Characteristic Declaration 2a19 */
    0x3005, 0x1223, 0x0019, 0x2a00,
    /* 0023: . */
    0xd401, 0x0000,
    /* 0024: Characteristic Presentation Format, rfu, 0 */
    0x8c07, 0x0000, 0x0000, 0x0000, 0x0000,
    /* 0025: Client Characteristic Configuration */
    0x6c00,
};

/* SDP service snippets */
const uint8 gatt_sdp_class[] = {
    /* UINT16: ServiceClassIDList 0x0001 */
    0x09, 0x00, 0x01, 0x35, /* add length + type + UUID */
};

const uint8 gatt_sdp_prot[] = {
    /* UINT16: ProtocolDescriptorList 0x0004 */
    0x09, 0x00, 0x04,
    /* Segment: 19 bytes */
    0x35, 0x13,
    /** Segment: 6 bytes */
    /**/ 0x35, 0x06,
    /**** UUID16: L2CAP */
    /****/ 0x19, 0x01, 0x00,
    /**** UINT16: ATT PSM */
    /****/ 0x09, 0x00, 0x1f,
    /** Segment: 9 bytes */
    /**/ 0x35, 0x09,
    /**** UUID16: ATT */
    /****/ 0x19, 0x00, 0x07,
    /**** UINT16: start handle, to be filled later */
    /****/ 0x09, 0x00, 0x00,
    /**** UINT16: end handle, to be filled later */
    /****/ 0x09, 0x00, 0x00,

    /* UINT16: BrowseGroupList 0x0005 */
    0x09, 0x00, 0x05,
    /* Segment: 3 bytes */
    0x35, 0x03,
    /** UUID16: PublicBroseGroup */
    /**/ 0x19, 0x10, 0x02  
};

#define OFFS_START      0x0013  /* offset to starting handle */
#define OFFS_END        0x0016  /* offset to ending handle */

#define UUID_IS_16      0x0000  /* flag indicating 16-bit UUID */
#define UUID_IS_32      0x4000  /* flag indicating 32-bit UUID */
#define UUID_IS_128     0x8000  /* flag indicating 128-bit UUID */

/* DataElement Header for UUID16 (Type:0b00011 Size:0b001)
 * See Core V4.0 SDP Specification P221 Sec 3.2 & 3.3 */
#define SDP_UUID16      0x19
/* DataElement Header for UUID32 (Type:0b00011 Size:0b010)
 * See Core V4.0 SDP Specification P221 Sec 3.2 & 3.3 */
#define SDP_UUID32      0x1A
/* DataElement Header for UUID128 (Type:0b00011 Size:0b100)
 * See Core V4.0 SDP Specification P221 Sec 3.2 & 3.3 */
#define SDP_UUID128     0x1c

const struct 
{
    uint16      offs;
    uint16      start;
    uint16      end;
} sdp_data[] = {
    { UUID_IS_16  | 0x000a, 0x0005, 0x0009 },     /* GAP_SERVICE */
    { UUID_IS_16  | 0x0060, 0x001c, 0x0020 },     /* BATTERY_SERVICE1 */
    { UUID_IS_16  | 0x006e, 0x0021, 0xffff },     /* BATTERY_SERVICE2 */
};

uint8 *GattGetServiceRecord(gatt_sdp service, uint16 *len)
{
    uint8 *sdp;
    uint8 *p_sdp;
    uint16 uuidlen;
    uint16 offs;

    if (service == gatt_sdp_last)
    {
        *len = 0U;
        return NULL;
    }

    if (sdp_data[service].offs & UUID_IS_128)
        /* 128-bit UUID */
    {
        /* 16 octets */
        uuidlen = 16U;
    }
    else if (sdp_data[service].offs & UUID_IS_32)
        /* 32-bit UUID */
    {
        /* 4 octets */
        uuidlen = 4U;
    }
    else
        /* 16-bit UUID */
    {
        /* 2 octets */
        uuidlen = 2U;
    }
    
    /* allocate memory */
    *len = sizeof(gatt_sdp_class) + sizeof(gatt_sdp_prot) + 2 + uuidlen ;
    sdp = PanicUnlessMalloc(*len);

    memmove(sdp, gatt_sdp_class, sizeof(gatt_sdp_class));
    p_sdp = &sdp[sizeof(gatt_sdp_class)];
    *p_sdp++ = uuidlen + 1;
    if ( sdp_data[service].offs & UUID_IS_128 )
    {
        *p_sdp++ = SDP_UUID128;
    }
    else if ( sdp_data[service].offs & UUID_IS_32 )
    {
        *p_sdp++ = SDP_UUID32;
    }
    else
    {
        *p_sdp++ = SDP_UUID16;
    }

    /* extract the UUID from the ATT database data */
    for (offs = ( sdp_data[service].offs
            & ~( UUID_IS_128 | UUID_IS_32 | UUID_IS_16 ) ); uuidlen; offs--)
    {
	/* The values below are explictly converted to 8-bits by zeroing of higher bytes, 
	 * as on bluecore uint8 is not necessarily 8-bits */	    
        *p_sdp++ = ( gattDatabase[offs] & 0xFF );
        *p_sdp++ = ( gattDatabase[offs] >> 8 ) & 0xFF;
        uuidlen -= 2;
    }

    memmove(p_sdp, gatt_sdp_prot, sizeof(gatt_sdp_prot));
    p_sdp[OFFS_START] = sdp_data[service].start >> 8;
    p_sdp[OFFS_START + 1] = sdp_data[service].start;
    p_sdp[OFFS_END] = sdp_data[service].end >> 8;
    p_sdp[OFFS_END + 1] = sdp_data[service].end;

    return sdp;
}

uint16 *GattGetDatabase(uint16 *len)
{
    uint16 *rc = PanicUnlessMalloc(sizeof(gattDatabase));
    *len = sizeof(gattDatabase);
    memmove(rc, gattDatabase, sizeof(gattDatabase));
    return rc;
}

uint16 GattGetDatabaseSize(void)
{
    return sizeof(gattDatabase);
}

/* End-of-File */