#include "RPCDICE.h"
#include <stdio.h>

void rpcdice_1(char* host, inputData* input)
{
	CLIENT* clnt;
	outputData* result;
	
	char service_name[] = "root@41.101.212.61";
	char mech[] = "gssproxy_v1";

	clnt = clnt_create(host, RPCDICE, RPCDICE_VERS, "udp");
	if(clnt == NULL)
	{
		clnt_pcreateerror(host);
		exit(1);
	}
	
	clnt->cl_auth = authunix_create_default();
	
	result = roll_1(input, clnt);
	if(result == (outputData *) NULL)
	{
		clnt_perror(clnt, "call failed");
		exit(1);
	}

	printf("Result:\n\tSuccessfull: %d\n\tSix: %d\n\tOne: %d\n", result->successfull, result->six, result->one);

	auth_destroy(clnt->cl_auth);
	clnt_destroy(clnt);
}

int main(int argc, char* argv[])
{
	char* host;
	if(argc < 3)
	{
		printf("usage: %s server_host number_of_rolls [threshold] [full reroll: 1/0] [reroll 1s: 1/0]\n", argv[0]);
		exit(1);
	}

	host = argv[1];

	inputData input;
	input.numOfRolls = atoi(argv[2]);

	if(argc >= 4)
		input.threshold = atoi(argv[3]);
	if(argc >= 5)
		input.hasFullReroll = atoi(argv[4]);
	if(argc >= 6)
		input.hasRerollAtOne = atoi(argv[5]);

	rpcdice_1(host, &input);
	exit(0);
}
