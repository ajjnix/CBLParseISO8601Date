//
//  CBLParseDate.h
//  CouchbaseLite
//
//  Created by Jens Alfke on 9/8/13.
//
//

#ifndef CouchbaseLite_CBLParseDate_h
#define CouchbaseLite_CBLParseDate_h

#include <stdint.h>

typedef int64_t sqlite3_int64;

/** Parses a C string as an ISO-8601 date-time, returning a UNIX timestamp (number of seconds
    since 1/1/1970), or a NAN if the string is not valid. */
double CBLParseISO8601Date(const char* dateStr);

/*
 ** A structure for holding a single date and time.
 */
typedef struct DateTime DateTime;
struct DateTime {
    sqlite3_int64 iJD; /* The julian day number times 86400000 */
    int Y, M, D;       /* Year, month, and day */
    int h, m;          /* Hour and minutes */
    int tz;            /* Timezone offset in minutes */
    double s;          /* Seconds */
    char validYMD;     /* True (1) if Y,M,D are valid */
    char validHMS;     /* True (1) if h,m,s are valid */
    char validJD;      /* True (1) if iJD is valid */
    char validTZ;      /* True (1) if tz is valid */
};

/** Parses a C string as an ISO-8601 date-time into the DateTime structure
 ** and return 0 on success and 1 if the input string is not a well-formed date.
 */
int CBLParseISO8601DateTime(const char* zDate, DateTime *dateTime);

#endif
