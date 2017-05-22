#include "coder.h"
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdint.h>
int encode(uint32_t code_point, CodeUnits *code_units){
if(code_units == NULL){
	return -1;
}
if(code_point < 128){
    code_units->length = 1;
   		code_units->code[0] = 127 & code_point;
   		return 0;
   		
}

if((code_point < 2048)&&(code_point > 127)){
	code_units->length = 2;
		code_units->code[0] = 192 | (code_point >> 6);
		code_units->code[1] = 128 | ( code_point & 63 );
		return 0;
}

if((code_point < 65536)&&(code_point > 2047)){
	code_units->length = 3;
		code_units->code[0] = 224 | (code_point >> 12);
		code_units->code[1] = 128 | ((code_point >> 6 ) & 63);
		code_units->code[2] = 128 | (code_point & 63 );
		return 0;
}

if((code_point < 2097152)&&(code_point > 65535)){
	code_units->length = 4;
		code_units->code[0] = 240 | (code_point >> 18 ) ;
		code_units->code[1] = 128 | ((code_point >> 12 ) & 63);
		code_units->code[2] = 128 | ((code_point >> 6 ) & 63);
		code_units->code[3] = 128 | (code_point & 63);
		return 0;
	
}
printf("Wrong number\n");
return -1;
}

uint32_t decode(const CodeUnits *code_unit){
	if((code_unit->code[0] & 128) == 0){
		uint32_t dec = code_unit->code[0];
			return dec;
	}
	
	if((code_unit->code[0] & 224) == 192){
		uint32_t dec = code_unit->code[0] & 31;
		dec = dec << 6;
		uint8_t dec1 =  code_unit->code[1] & 63;
		return dec = dec | dec1;
	}
	
	if((code_unit->code[0] & 240) == 224){
		uint32_t dec = code_unit->code[0] & 15;
		dec = dec << 6;
		uint8_t dec1 = code_unit->code[1] & 63;
		dec = dec | dec1;
		dec = dec << 6;
		dec1 = code_unit->code[2] & 63;
		return dec = dec | dec1;
	}

	if((code_unit->code[0] & 248) == 240){
		uint32_t dec = code_unit->code[0] & 7;
		dec = dec << 6;
		uint8_t dec1 = code_unit->code[1] & 63;
		dec = dec | dec1;
		dec = dec << 6;
		dec1 = code_unit->code[2] & 63;
		dec = dec | dec1;
		dec = dec << 6;
		dec1 = code_unit->code[3] & 63;
		return dec = dec| dec1;	
	}
	
	return -1;
}
