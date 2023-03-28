/* Processed by ecpg (12.14 (Ubuntu 12.14-0ubuntu0.20.04.1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "pq.pgc"
/*
:!ecpg %
*/
/* exec sql begin declare section */
 
 

#line 5 "pq.pgc"
 int int4 ;
 
#line 6 "pq.pgc"
 double float8 ;
/* exec sql end declare section */
#line 7 "pq.pgc"


{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select a , b from test", ECPGt_EOIT, 
	ECPGt_int,&(int4),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_double,&(float8),(long)1,(long)1,sizeof(double), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 9 "pq.pgc"

