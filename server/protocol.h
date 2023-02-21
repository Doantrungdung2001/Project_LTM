#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__
#define FG_BLACK    "\x1b[90m"     // Black foreground
#define FG_RED      "\x1b[91m"     // Red foreground
#define FG_GREEN    "\x1b[92m"     // Green foreground
#define FG_YELLOW   "\x1b[93m"     // Yellow foreground
#define FG_BLUE     "\x1b[94m"     // Blue foreground
#define FG_MAGENTA  "\x1b[95m"     // Magenta foreground
#define FG_CYAN     "\x1b[96m"     // Cyan foreground
#define FG_WHITE    "\x1b[97m"     // White foreground
 
#define BOLD        "\x1b[1m"      // Bold format
#define ITALIC      "\x1b[3m"      // Italic format
#define UNDERLINE   "\x1b[4m"      // Underline format
 
#define NORMAL      "\x1b[0m"      // Normal format
typedef enum {
    LOGIN_REQUEST,
    REGISTER_REQUEST,
    LOGOUT_REQUEST,
    FIND_IMG_REQUEST,
    IMG_REQUEST,
    STATUS_USER_REQUEST,
    STATUS_USER_LIST,
    FIND_IMG_IN_USERS,
    FILE_WAS_FOUND,
    FILE_WAS_NOT_FOUND,
    SEND_IMGS_TO_USER,
    NO_IMG_FOUND,
    ACCEPT_IMAGE,
    SEND_DONE,
    SEND_IMG_CONTINUE,
    STOP,
    BREAK,
    EXIT_SYS,
    REGISTER_SUCCESS,
    LOGIN_SUCCESS,
    LOGOUT_SUCCESS,
    UPLOAD_SUCCESS,
    INCORRECT_PASSWORD,
    EXISTENCE_USERNAME,   
    LOGIN_FAILED,
    NON_EXISTENCE_USERNAME,
    IS_CURRENTLY_LOGGED,
    QUERY_FAILD
} PROTOCOL;
#endif