/*
 *  $Id: DmpTriggerStatus.h, 2014-08-06 14:04:05 DAMPE $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 06/08/2014
*/

#ifndef DmpTriggerStatus_H
#define DmpTriggerStatus_H

namespace DmpTriggerStatus{
  enum Type{
    k0Compress = 0,
    kCompress = 1,
    kCalDAC = 2,
    kUnknow = 3
  };
}

#endif

