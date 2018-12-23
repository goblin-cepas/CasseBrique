#ifndef __TIMER_H__
#define __TIMER_H__

#include <time.h>

struct timer{
  unsigned int elapsed;
  time_t start, end;
};

#endif
