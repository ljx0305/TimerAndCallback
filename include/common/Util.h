#ifndef UTIL_H
#define UTIL_H

////#include <iostream>
#include <string>
#include <cstring>
#include <arpa/inet.h>
#include <string.h>
#include <sstream>
#include <iostream>
#include <string>
#include "Types.h"

#define UINT32_MSB(x) (((x) >> 16) & 0x0000FFFF) 
#define UINT32_LSB(x) ((x) & 0x0000FFFF)
#define UINT32_LSB_OF_MSB(x) (((x) >> 16) & 0x000000FF)
#define UINT24_TO_UINT32(lsbOfMsb, lsb) (((lsbOfMsb) << 16) | (lsb))

#define MAX_HOSTNAME_LEN 60
#define MAX_PROCESS_NAME_LEN 15
/**
   Methods for serializing and deserializing
*/

void serializeString (const std::string&, OutputStream&);
void serializePadding (const UINT32& padLen, OutputStream&);
void deserializeString (std::string&, InputStream&, UINT32);
void deserializePadding (const UINT32& padLen, InputStream&);
void serializeUINT64 (const UINT64& value, OutputStream& os);
void deserializeUINT64 (UINT64& value, InputStream& in);
void serializeUINT64ToCharBuf (const UINT64& value, CHAR* buf);
void deserializeUINT64FromCharBuf (UINT64& value, const CHAR* buf);
void serializeUINT32ToCharBuf (const UINT32& value, CHAR* buf);
void deserializeUINT32FromCharBuf (UINT32& value, const CHAR* buf);
void serializeUINT32 (const UINT32& value, OutputStream& os);
void deserializeUINT32 (UINT32& value, InputStream& in);
void serializeSINT32 (const SINT32& value, OutputStream& os);
void deserializeSINT32 (SINT32& value, InputStream& in);
void serializeSINT64 (const SINT64& value, OutputStream& os);
void deserializeSINT64 (SINT64& value, InputStream& in);
void serializeFLT32 (const FLT32& value, OutputStream& os);
void deserializeFLT32 (FLT32& value, InputStream& in);
void serializeFLT64 (const FLT64& value, OutputStream& os);
void deserializeFLT64 (FLT64& value, InputStream& in);
void serialize3ByteUnsignedChar (const UINT8 threeByteInteger[], OutputStream& os);
void deserializeTo3ByteUnsignedChar (UINT8 threeByteInteger[], InputStream& in);
void serializeUINT8 (const UINT8& value, OutputStream& os);
void deserializeUINT8 (UINT8& value, InputStream& in);
void splitUINT32To3ByteUINT8Array (const UINT32& value, UINT8 bytes[]);
void unsplit3ByteUINT8ArrayToUINT32 (UINT32& value, const UINT8 bytes[]);
UINT32 getUINT32From3ByteUINT8Array (const UINT8 bytes[]);

/**
   Miscellaneous helper methods
*/
BasicString getNewUUIDString();
UINT32 get32BitRandomNumber ();

bool uint64LT (UINT64& _value1, UINT64& _value2);
bool uint64LEQ (UINT64& _value1, UINT64& _value2);
bool uint64EQ (UINT64& _value1, UINT64& _value2);
bool uint64GEQ (UINT64& _value1, UINT64& _value2);

BasicString getMyHostname ();
BasicString getMyIPAddress ();
UINT32 getIPAddressFromName (const CHAR* name);
const CHAR* getNameFromIPAddress (const CHAR* ipAddressBuf);

void dumpBinaryToFile (const CHAR* filepath, std::ostringstream& os);

#endif

