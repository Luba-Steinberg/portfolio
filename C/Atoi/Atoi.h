#ifndef _ILRD_ATOI_H_
#define _ILRD__ATOI_H_

void IntStrFuncs(); /*calls to Atoi-Itoa functions, gets and receivces nothing, O(1)*/
int IsBigEndian();/*checks whether the machine is Big endian, prints a suitable message and returns 1 if hte machine is BigEndian, O - if it's not*/
int IsAtoiOutputSame();/*checks whether the output of Atoi function by programmer and by system are the same and returns 1 if the are, 0 if they aren't*/

#endif /*_ILRD__ATOI_H_*/
