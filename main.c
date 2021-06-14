#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

int bcd(int bcd_value);

int main(int argc, char *argv[]) {
	int arg;
    for (arg = 1; arg < argc; arg++) {
        long l = strtol(argv[arg], NULL, 0);
        assert(l >= 0 && l <= 0x0909);
        int bcd_value = l;

        printf("%d\n", bcd(bcd_value));
    }

    return 0;
}


// given a  BCD encoded value between 0 .. 99
// return corresponding integer
int bcd(int bcd_value) {

    
	int result=0;
	int tens=1;
	while(bcd_value>0)
	{
		result=result+((bcd_value&0x0F)*tens);
		tens=tens*10;
		bcd_value=bcd_value>>8;
		
	}
	return result;
}
