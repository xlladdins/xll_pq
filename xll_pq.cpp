// xll_pq.cpp
#include "xll_pq.h"

int test_conn()
{
	const char* cs = "database=postgres user=postgres socket=/var/run/postgresql port=5432";
	PQ::conn conn(cs);

	return 0;
}
int conn_test = test_conn();
