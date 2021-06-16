struct inputData{
  int numOfRolls;
  int threshold;
  bool hasRerollAtOne;
  bool hasFullReroll;
};

struct outputData{
  int successfull;
  int six;
  int one;
};

program RPCDICE{
  version RPCDICE_VERS{
    outputData ROLL(inputData)=1;
  }=1;
}=1337;
