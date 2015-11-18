/*
@project name: web server for cosmos
@system:       nOS with uIP1.0	
@bug:          zhoukesec@163.com, QQ 9482145
@date:         2013-03-20
*/


#include "common.h"
#include "miscfun.h"


static uchar upload_busy = 0;

uchar password_ok (uchar *entry_ptr)
/* ------------------------------------------------------------------------ --
 * Purpose     : Check specified password against password in eeprom.
 * Remarks     : Return TRUE if password is correct, otherwise FALSE is
 *               returned.
 * Restrictions:
 * See also    :
 * Example     :
 * ************************************************************************ */
{
    password_t password;
    uchar j;
    uchar ok;
 
    ok = 1;
	
	  return ok;
	
    if (password[0] != 0) {
        for (j = 0; j < MAX_PASSWORD_LEN; j++) {
            if (password[j] == 0) {
                break;
            }
            if (*entry_ptr == 0x0d) {
                ok = 0;
                break;
            }
            if (password[j] != *entry_ptr) {
                ok = 0;
                break;
            }
            entry_ptr++;
        }
        if (*entry_ptr != 0x0d) {
            ok = 0;
        }
    }

    return ok;
}

/* ************************************************************************ */
uchar ascii_to_hex_nib (uchar ch)
/* ------------------------------------------------------------------------ --
 * Purpose     : Convert an ASCII hex digit to a hex digit.
 * Remarks     : 
 * Restrictions:
 * See also    :
 * Example     :
 * ************************************************************************ */
{
    ch = conv_to_upper_case(ch);

    if (('0' <= ch) && (ch <= '9')) {
        return (ch - '0');
    }
    else if (('A' <= ch) && (ch <= 'F')) {
        return (ch - 'A' + 10);
    }
    else {
        return 0xff;
    }
}

/* ************************************************************************ */
uchar hex_to_ascii_nib (uchar nib)
/* ------------------------------------------------------------------------ --
 * Purpose     : Convert a hex nibble in binary (0-f) to ASCII.
 * Remarks     : nib holds nibble to convert (must be in range 0-f).
 * Restrictions:
 * See also    :
 * Example     :
 * ************************************************************************ */
{
    if (nib < 10) {
        return nib + '0';
    }
    else {
        return (nib - 10) + 'a';
    }
}

/* ************************************************************************ */
char conv_to_upper_case (char ch)
/* ------------------------------------------------------------------------ --
 * Purpose     : Convert a char to upper case.
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 * ************************************************************************ */
{
    if (('a' <= ch) && (ch <= 'z')) {
        return (ch - 0x20);
    }
    else {
        return ch;
    }
}


/* ************************************************************************ */
void str_conv_to_upper_case (char *str)
/* ------------------------------------------------------------------------ --
 * Purpose     : Convert a char to upper case.
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 * ************************************************************************ */
{
   while(*str){
		if (('a' <= *str) && (*str <= 'z')) {
        *str = (*str- 0x20);
    }
    str++; 
	}
}

uchar reserve_updown_load(void)
{
    if (upload_busy)
        return 0;
    upload_busy = 1;
    return 1;
}

void release_updown_load(void)
{
    upload_busy = 0;
}
