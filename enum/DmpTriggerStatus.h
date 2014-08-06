/*
 *  $Id: DmpTriggerStatus.h, 2014-08-06 14:04:05 DAMPE $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 06/08/2014
*/

#ifndef DmpTriggerStatus_H
#define DmpTriggerStatus_H

namespace DmpTriggerStatus{
  enum Type{
    kNoCheck = 0,       // did not receive check signal
    kCheckRight = 1,    // received check signal, and it's right
    kCheckWrong = 2,    // received check signal, but it's wrong
    kUnknow = 3         // undefined
  };
}

#endif

