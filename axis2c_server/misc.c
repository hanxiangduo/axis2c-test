/*
Copyright (c) 2009  Eucalyptus Systems, Inc.	

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by 
the Free Software Foundation, only version 3 of the License.  
 
This file is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.  

You should have received a copy of the GNU General Public License along
with this program.  If not, see <http://www.gnu.org/licenses/>.
 
Please contact Eucalyptus Systems, Inc., 130 Castilian
Dr., Goleta, CA 93101 USA or visit <http://www.eucalyptus.com/licenses/> 
if you need additional information or have any questions.

This file may incorporate work covered under the following copyright and
permission notice:

  Software License Agreement (BSD License)

  Copyright (c) 2008, Regents of the University of California
  

  Redistribution and use of this software in source and binary forms, with
  or without modification, are permitted provided that the following
  conditions are met:

    Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.

    Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
  TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
  PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
  OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. USERS OF
  THIS SOFTWARE ACKNOWLEDGE THE POSSIBLE PRESENCE OF OTHER OPEN SOURCE
  LICENSED MATERIAL, COPYRIGHTED MATERIAL OR PATENTED MATERIAL IN THIS
  SOFTWARE, AND IF ANY SUCH MATERIAL IS DISCOVERED THE PARTY DISCOVERING
  IT MAY INFORM DR. RICH WOLSKI AT THE UNIVERSITY OF CALIFORNIA, SANTA
  BARBARA WHO WILL THEN ASCERTAIN THE MOST APPROPRIATE REMEDY, WHICH IN
  THE REGENTS’ DISCRETION MAY INCLUDE, WITHOUT LIMITATION, REPLACEMENT
  OF THE CODE SO IDENTIFIED, LICENSING OF THE CODE SO IDENTIFIED, OR
  WITHDRAWAL OF THE CODE CAPABILITY TO THE EXTENT NEEDED TO COMPLY WITH
  ANY SUCH LICENSES OR RIGHTS.
*/
#include <stdio.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <string.h> /* strlen, strcpy */
#include <ctype.h> /* isspace */
#include "misc.h"
#include <stdarg.h>
#include <sys/types.h>
#define _FILE_OFFSET_BITS 64
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <math.h> /* powf */
#include <fcntl.h> /* open */
#include <utime.h> /* utime */
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h> // opendir, etc
#include <errno.h> // errno
#include <sys/time.h> // gettimeofday
#include <limits.h>




int timelog=0; /* change to 1 for TIMELOG entries */

int logging=0;
int loglevel=EUCADEBUG;
FILE *LOGFH=NULL;
char logFile[MAX_PATH];






/* given string *stringp, replace occurences of <source> with <destination>
 * and return the new string in stringp */

/* do sscanf() on each line in lines[], returning upon first match */
/* returns 1 if there was match and 0 otherwise */

/* search for variable #name# in file #path# and return whatever is after
 * = in value (which will need to be freed).
 *
 * Example of what we are able to parse:
 * TEST="test"
 * TEST=test
 *     TEST   = test
 *
 * Return 1 on success, 0 on variable not found and -1 on error (parse or
 * file not found)
 */




int logfile(char *file, int in_loglevel) {
  logging = 0;
  if (in_loglevel >= EUCADEBUG2 && in_loglevel <= EUCAFATAL) {
    loglevel = in_loglevel;
  } else {
    loglevel = EUCADEBUG;
  }
  if (file == NULL) {
    LOGFH = NULL;
  } else {
    if (LOGFH != NULL) {
      fclose(LOGFH);
    }
    
    snprintf(logFile, MAX_PATH, "%s", file);
    LOGFH = fopen(file, "a");
    if (LOGFH) {
      logging=1;
    }
  }
  return(1-logging);
}

void eventlog(char *hostTag, char *userTag, char *cid, char *eventTag, char *other) {
  double ts;
  struct timeval tv;
  char hostTagFull[256];
  char hostName [256];
  FILE *PH;

  if (!timelog) return;

  hostTagFull[0] = '\0';
  PH = popen("hostname", "r");
  fscanf(PH, "%256s", hostName);
  pclose(PH);
  snprintf (hostTagFull, 256, "%s/%s", hostName, hostTag);
  
  gettimeofday(&tv, NULL);
  ts = (double)tv.tv_sec + ((double)tv.tv_usec / 1000000.0);

  logprintf("TIMELOG %s:%s:%s:%s:%f:%s\n", hostTagFull, userTag, cid, eventTag, ts, other);
}

int logprintf(const char *format, ...) {
  va_list ap;
  int rc;
  char buf[27], *eol;
  time_t t;
  FILE *file;
  
  rc = 1;
  va_start(ap, format);
  
  if (logging) {
    file = LOGFH;
  } else {
    file = stdout;
  }
  
  t = time(NULL);
  if (ctime_r(&t, buf)) {
    eol = strchr(buf, '\n');
    if (eol) {
      *eol = '\0';
    }
    fprintf(file, "[%s] ", buf);
  }
  rc = vfprintf(file, format, ap);
  fflush(file);
  
  va_end(ap);
  return(rc);
}

int logprintfl(int level, const char *format, ...) {
  va_list ap;
  int rc, fd;
  char buf[27], *eol;
  time_t t;
  struct stat statbuf;
  FILE *file;
  
  if (level < loglevel) {
    return(0);
  }
  
  rc = 1;
  va_start(ap, format);
  
  if (logging) {
    file = LOGFH;
    fd = fileno(file);
    if (fd > 0) {
      rc = fstat(fd, &statbuf);
      if (!rc && ((int)statbuf.st_size > MAXLOGFILESIZE)) {
	int i;
	char oldFile[MAX_PATH], newFile[MAX_PATH];
	
	rc = stat(logFile, &statbuf);
	if (!rc && ((int)statbuf.st_size > MAXLOGFILESIZE)) {
	  for (i=4; i>=0; i--) {
	    snprintf(oldFile, MAX_PATH, "%s.%d", logFile, i);
	    snprintf(newFile, MAX_PATH, "%s.%d", logFile, i+1);
	    rename(oldFile, newFile);
	  }
	  snprintf(oldFile, MAX_PATH, "%s", logFile);
	  snprintf(newFile, MAX_PATH, "%s.%d", logFile, 0);
	  rename(oldFile, newFile);
	}
	fclose(LOGFH);
	LOGFH = fopen(logFile, "a");
	if (LOGFH) {
	  file = LOGFH;
	} else {
	  file = stdout;
	}
      }
    }
  } else {
    file = stdout;
  }

  
  t = time(NULL);
  if (ctime_r(&t, buf)) {
    eol = strchr(buf, '\n');
    if (eol) {
      *eol = '\0';
    }
    fprintf(file, "[%s]", buf);
  }

  fprintf(file, "[%06d]", getpid());
  if (level == EUCADEBUG2) {fprintf(file, "[%-10s] ", "EUCADEBUG2");}
  else if (level == EUCADEBUG) {fprintf(file, "[%-10s] ", "EUCADEBUG");}
  else if (level == EUCAINFO) {fprintf(file, "[%-10s] ", "EUCAINFO");}
  else if (level == EUCAWARN) {fprintf(file, "[%-10s] ", "EUCAWARN");}
  else if (level == EUCAERROR) {fprintf(file, "[%-10s] ", "EUCAERROR");}
  else if (level == EUCAFATAL) {fprintf(file, "[%-10s] ", "EUCAFATAL");}
  else {fprintf(file, "[%-10s] ", "EUCADEBUG");}
  rc = vfprintf(file, format, ap);
  fflush(file);
  
  va_end(ap);
  return(rc);
}

/* implements Java's String.hashCode() */
int hash_code (const char * s)
{
	int code = 0;
	int i;
	
	if (!s) return code;
	
	int len = strlen((char *)s);
	for (i = 0; i<len; i++) {
		code = 31 * code + (unsigned char) s[i];
	}
	
	return code;
}

/* given a string, returns 3 relevant statistics as a static string */
#define BUFSIZE 1024

/* daemonize and store pid in pidfile. if pidfile exists and contained
   pid is daemon already running, do nothing.  force option will first
   kill and then re-daemonize */

/* daemonize and run 'cmd', returning pid of the daemonized process */

/* given printf-style arguments, run the resulting string in the shell */

/* given a file path, prints it to stdout */

/* prints contents of a file with logprintf */

/* "touch" a file, creating if necessary */
/* sums up sizes of files in the directory, as well as the size of the
 * directory itself; no subdirectories are allowed - if there are any, this
 * returns -1 */
