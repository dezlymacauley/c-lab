/*
    ABOUT: Switch statement

    Use this when you want to handle 3 or more potential outcomes.
*/

#include <stdio.h>

int main() {

    int status = 200;

    switch (status) {
    case 200:
        printf("\n200 OK - Request successful\n\n");
        break;
    case 301:
        printf("\n301 Moved Permanently - Resource relocated\n\n");
        break;
    case 400:
        printf("\n400 Bad Request - Client error\n\n");
        break;
    case 404:
        printf("\n404 Not Found - Resource does not exist\n\n");
        break;
    case 500:
        printf("\n500 Internal Server Error - Server failure\n\n");
        break;
    default:
        printf("\nUnknown status code: %d\n\n", status);
        break;
    }

    return 0;
}
