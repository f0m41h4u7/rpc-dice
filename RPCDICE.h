/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _RPCDICE_H_RPCGEN
#define _RPCDICE_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct inputData {
	int numOfRolls;
	int threshold;
	bool_t hasRerollAtOne;
	bool_t hasFullReroll;
};
typedef struct inputData inputData;

struct outputData {
	int successfull;
	int six;
	int one;
};
typedef struct outputData outputData;

#define RPCDICE 1337
#define RPCDICE_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define ROLL 1
extern  outputData * roll_1(inputData *, CLIENT *);
extern  outputData * roll_1_svc(inputData *, struct svc_req *);
extern int rpcdice_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define ROLL 1
extern  outputData * roll_1();
extern  outputData * roll_1_svc();
extern int rpcdice_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_inputData (XDR *, inputData*);
extern  bool_t xdr_outputData (XDR *, outputData*);

#else /* K&R C */
extern bool_t xdr_inputData ();
extern bool_t xdr_outputData ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_RPCDICE_H_RPCGEN */
