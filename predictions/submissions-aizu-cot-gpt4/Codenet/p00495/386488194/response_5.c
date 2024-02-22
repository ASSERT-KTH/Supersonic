#include <stdio.h>

#define MAX_SIZE 5004

int inputSequence[MAX_SIZE], maxLengths[MAX_SIZE], maxSeqLength, temp, seqSize, i;

int main() {
  for (scanf("%d%*d", &inputSequence[0]); i < inputSequence[0]; scanf("%d\n", &inputSequence[++i]))
    ;
  for (; ~scanf("%d\n", &temp);)
    for (seqSize = i = maxSeqLength = 0; i++ < inputSequence[0]; maxLengths[i] = maxSeqLength < seqSize ? maxSeqLength = seqSize : seqSize)
      seqSize = temp - inputSequence[i] ? seqSize : maxLengths[i] + 1;
  printf("%d\n", maxSeqLength);
  
  return 0;
}