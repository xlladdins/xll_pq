// xll_pq.h - Embed Postgres in Excel
#pragma once
#include <libpq-fe.h>
#include "xll/xll/xll.h"

#ifndef CATEGORY
#define CATEGORY "PQ"
#endif

namespace PQ {

	class result {
		PGresult* presult;
	public:
		result(PGconn* pconn, const char* command)
			: presult{ PQexec(pconn, command) }
		{ }
		result(const result&) = delete;
		result& operator=(const result&) = delete;
		~result()
		{
			PQclear(presult);
		}

		operator PGresult* ()
		{
			return presult;
		}

		int ntuples() const
		{
			return PQntuples(presult);
		}
		int nfields() const
		{
			return PQnfields(presult);
		}

		Oid ftype(int i) const
		{
			return PQftype(presult, i);
		}

		int getint(int i)
		{
			return 0; // PQgetvalue(presult, r, c);
		}
	};

	class conn {
		PGconn* pconn;
		std::map<int, std::string> oid_type;
		std::map<std::string, int> type_oid;
	public:
		//conn(){ }
		conn(const char* conninfo)
			: pconn{ PQconnectdb(conninfo) }
		{ 
			if (!pconn) {
				throw std::runtime_error(__FUNCTION__ ": failed to connect");
			}

			result res = exec("SELECT oid, typname FROM pg_catalog.pg_type");
			if (!res) {
				throw std::runtime_error("foo");
			}
			//ECPGt_double
		}
		conn(const conn&) = delete;
		conn& operator=(const conn&) = delete;
		~conn()
		{
			PQfinish(pconn);
		}

		operator PGconn* ()
		{
			return pconn;
		}
		operator const PGconn* () const
		{
			return pconn;
		}

		result exec(const char* command) const
		{
			return result(pconn, command);
		}
	};

} // namespace PQ