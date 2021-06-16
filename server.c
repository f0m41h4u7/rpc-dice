#include "RPCDICE.h"
#include <assert.h>

void roll_dice(int qty, int thr, int* cnt_s, int* cnt_six, int* cnt_one)
{
  *cnt_one = 0;
  int res = 0;

  for(int i = 0; i < qty; ++i)
  {
    res = rand()%6 + 1;
    if(res >= thr)
      (*cnt_s)++;
    if(res == 6)
      (*cnt_six)++;
    if(res == 1)
      (*cnt_one)++;
  }
}

outputData* roll_1_svc(inputData* argp, struct svc_req* rqstp)
{
	static outputData result;

  int cnt_success = 0;
  int cnt_six = 0;
  int cnt_one = 0;

  roll_dice(argp->numOfRolls, argp->threshold, &cnt_success, &cnt_six, &cnt_one);
  if(argp->hasFullReroll)
  {
    if(cnt_success != argp->numOfRolls)
      roll_dice(argp->numOfRolls - cnt_success, argp->threshold, &cnt_success, &cnt_six, &cnt_one);
  }
  else if(argp->hasRerollAtOne)
  {
    if(cnt_one > 0)
      roll_dice(cnt_one, argp->threshold, &cnt_success, &cnt_six, &cnt_one);
  }

  result.successfull = cnt_success;
  result.six = cnt_six;
  result.one = cnt_one;

	return &result;
}
