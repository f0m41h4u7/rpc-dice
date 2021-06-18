#include <memory.h>
#include "RPCDICE.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

outputData* roll_1(inputData* argp, CLIENT* clnt)
{
	static outputData clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, ROLL,
		(xdrproc_t) xdr_inputData, (caddr_t) argp,
		(xdrproc_t) xdr_outputData, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}
